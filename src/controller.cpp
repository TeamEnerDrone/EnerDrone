#include "controller.h"
#include <QTimer>
#include <QString>
#include <QNetworkConfiguration>
#include <QNetworkConfigurationManager>

// --------------------------------------------------------------------------
// controller::controller()
// Description : Constructor of controller class.
// --------------------------------------------------------------------------
controller::controller() : allowFollowPath(false), peopleDetected(false), timeLineUndetected(0), warningBeep("../../asset/beep-06.wav")
{
    //Creation of the windows
    windowMain = new Window_Main();
    windowDroneCamera = new Window_DroneCamera();

	//Creation of the drone object
	ardrone = new ARDrone();

	//Récupération du nom du réseau connecté
	QNetworkConfigurationManager netConfigManager;
	auto listConfig = netConfigManager.allConfigurations(QNetworkConfiguration::Active);

	for (QNetworkConfiguration netConfig : listConfig)
	{
		if (netConfig.bearerType() == QNetworkConfiguration::BearerWLAN)
			windowMain->getTextWifiName()->setText(netConfig.name());
	}

    //Creation of the timers
    QTimer* timerGraphicalUpdate = new QTimer();
	QTimer* timerImageProcessing = new QTimer();

    //Connection between timer and functions
	QObject::connect(timerGraphicalUpdate, SIGNAL(timeout()), this, SLOT(graphicalUpdate()));
	QObject::connect(timerImageProcessing, SIGNAL(timeout()), this, SLOT(imageProcessing()));

	//Start the timer
	timerGraphicalUpdate->start(1000);
	timerImageProcessing->start(200);

    //Connection between the windows
    QObject::connect(windowMain->getPushButtonDroneCamera(), SIGNAL(clicked()), windowDroneCamera, SLOT(show()));
    QObject::connect(windowMain->getPushButtonDroneCamera(), SIGNAL(clicked()), windowMain, SLOT(close()));
    QObject::connect(windowDroneCamera->getPushButtonSwitchWindow(), SIGNAL(clicked()), windowMain, SLOT(show()));
    QObject::connect(windowDroneCamera->getPushButtonSwitchWindow(), SIGNAL(clicked()), windowDroneCamera, SLOT(close()));

	//Connection between some widgets and the drone
	QObject::connect(windowMain->getPushButtonStart(), SIGNAL(clicked()), this, SLOT (startDrone()));
	QObject::connect(windowMain->getPushButtonStop(), SIGNAL(clicked()), this, SLOT (stopDrone()));
	QObject::connect(windowDroneCamera->getPushButtonStop(), SIGNAL(clicked()), this, SLOT (stopDrone()));
	QObject::connect(windowDroneCamera->getPushButtonResume(), SIGNAL(clicked()), this, SLOT (resumeDrone()));


	//Hide the warning labels
	windowMain->getImageWarning()->setVisible(false);
	windowMain->getLabelWarning()->setVisible(false);
	windowDroneCamera->getImageWarning()->setVisible(false);
	windowDroneCamera->getLabelWarning()->setVisible(false);

}

// --------------------------------------------------------------------------
// controller::startApplication()
// Description : Start the application
// Return value : 1 if sucess, -1 is fail
// --------------------------------------------------------------------------
int controller::startApplication()
{
	// Initialize
	if (!ardrone->open()) {
		return -1;
	}

	else
	{
		//Set camera mode
		ardrone->setCamera(2);

		//Display the main window
		windowMain->show();
		return 1;
	}
}

// --------------------------------------------------------------------------
// controller::graphicalUpdate()
// Description : Graphically update the windows.
// Return value : NONE
// -------------------------------------------------------------------------
void controller::graphicalUpdate()
{
	//We only update the active window
	if (windowMain->isActiveWindow())
	{
		//Update of the battery
		graphicalUpdateBatteryLevel(windowMain->getImageBatteryLevel(), windowMain->getLabelBatteryLevel());

		//Update buttons and labels
		if (ardrone->emergencyState())  //Emergency
		{
			windowMain->getImageDroneStatus()->setPixmap(QPixmap("../../asset/imgvoyantrouge.png"));
			windowMain->getLabelDroneStatus()->setText("Emergency !!!");
			windowMain->getPushButtonStart()->setEnabled(false);
			windowMain->getPushButtonStop()->setEnabled(false);
		}

		else if(ardrone->onGround())      //On Ground
		{
			windowMain->getImageDroneStatus()->setPixmap(QPixmap("../../asset/imgvoyantgris.png"));
			windowMain->getLabelDroneStatus()->setText("On Ground");
			windowMain->getPushButtonStart()->setEnabled(true);
			windowMain->getPushButtonStop()->setEnabled(false);
		}

		else                             //Flying
		{
			windowMain->getImageDroneStatus()->setPixmap(QPixmap("../../asset/imgvoyantvert.png"));
			windowMain->getLabelDroneStatus()->setText("Flying...");
			windowMain->getPushButtonStart()->setEnabled(false);
			windowMain->getPushButtonStop()->setEnabled(true);
		}

		//Update warning label and image if necessary
		if (peopleDetected)
		{
			if (windowMain->getImageWarning()->isVisible())
			{
				windowMain->getImageWarning()->setVisible(false);
				windowMain->getLabelWarning()->setVisible(false);
			}

			else
			{
				windowMain->getImageWarning()->setVisible(true);
				windowMain->getLabelWarning()->setVisible(true);
				warningBeep.play();
			}
		}

		else
		{
			windowMain->getImageWarning()->setVisible(false);
			windowMain->getLabelWarning()->setVisible(false);
		}
	}

	//2nd window
	else if (windowDroneCamera->isActiveWindow())
	{
		//Update of the battery
		graphicalUpdateBatteryLevel(windowDroneCamera->getImageBatteryLevel(), windowDroneCamera->getLabelBatteryLevel());

		//Mise à jour de l'image à afficher
		QImage tmpImage = IplImage2QImage(ardrone->getImage());
		windowDroneCamera->getImageDroneCamera()->setPixmap(QPixmap::fromImage(tmpImage));

		if (ardrone->emergencyState())  //Emergency
		{
			windowDroneCamera->getPushButtonStop()->setEnabled(false);
			windowDroneCamera->getPushButtonResume()->setEnabled(false);
		}
		
		else if(ardrone->onGround())   //On ground
		{
			windowDroneCamera->getPushButtonStop()->setEnabled(false);
			windowDroneCamera->getPushButtonResume()->setEnabled(false);
		}

		else                            //Flying...
		{
			windowDroneCamera->getPushButtonStop()->setEnabled(true);
		}


		//A DEPLACER DANS LE ELSE JUSTE AU DESSUS
		if(peopleDetected)
				windowDroneCamera->getPushButtonResume()->setEnabled(true);

		else windowDroneCamera->getPushButtonResume()->setEnabled(false);

		//A CHANGER DE PLACE --------------- TEST TEST TEST
		if (peopleDetected)
		{
			if (windowDroneCamera->getImageWarning()->isVisible())
			{
				windowDroneCamera->getImageWarning()->setVisible(false);
				windowDroneCamera->getLabelWarning()->setVisible(false);
			}

			else
			{
				windowDroneCamera->getImageWarning()->setVisible(true);
				windowDroneCamera->getLabelWarning()->setVisible(true);
				warningBeep.play();
			}
		}

		else
		{
			windowDroneCamera->getImageWarning()->setVisible(false);
			windowDroneCamera->getLabelWarning()->setVisible(false);
		}
	}
}

// --------------------------------------------------------------------------
// controller::graphicalUpdateBatteryLevel()
// Description : Graphically update the label and the image for the battery.
// Return value : NONE
// -------------------------------------------------------------------------
void controller::graphicalUpdateBatteryLevel (QLabel* imageBatteryLevel, QLabel* labelBatteryLevel)
{
	if (ardrone->getBatteryPercentage() > 66)
		imageBatteryLevel->setPixmap(QPixmap("../../asset/imgbatteriepleine.png"));

	else if (ardrone->getBatteryPercentage() < 33)
		imageBatteryLevel->setPixmap(QPixmap("../../asset/imgbatterievide.png"));

	else imageBatteryLevel->setPixmap(QPixmap("../../asset/imgbatteriemoyen.png"));

	labelBatteryLevel->setText(QString::number(ardrone->getBatteryPercentage()) + " %");
}

// --------------------------------------------------------------------------
// controller::startDrone()
// Description : The drone takes off and starts to follow the line
// Return value : NONE
// ------------------------------------------------------------------------
void controller::startDrone()
{
	ardrone->takeoff();
	//Wait until the drone is stabilized
	Sleep(4000);
	allowFollowPath = true;
}

// --------------------------------------------------------------------------
// controller::stopDrone()
// Description : Stop the drone
// Return value : NONE
// ------------------------------------------------------------------------
void controller::stopDrone()
{
	//Disable image processing
	allowFollowPath = false;
	peopleDetected = false;

	ardrone->landing();
}

// --------------------------------------------------------------------------
// controller::resumeDrone()
// Description : Allow the drone to continue its way
// Return value : NONE
// ------------------------------------------------------------------------
void controller::resumeDrone()
{
	peopleDetected = false;
	allowFollowPath = true;

}


// --------------------------------------------------------------------------
// controller::imageProcessing()
// Description : Perform the image processing (Follow a line / Face Detection)
// Return value : NONE
// ------------------------------------------------------------------------
void controller::imageProcessing()
{
	//Get an image
	IplImage* image = ardrone->getImage();

	//Suivi de parcours
	if (allowFollowPath)
	{
		//Check if drone reachs the end of path
		bool foundCircle = ardrone->findCircle(image);

		//End of path detected
		if (foundCircle)
		{
			allowFollowPath = false;
			ardrone->landing();
		}

		//Still has to move
		else if (ardrone->followLine(image))
		{
			//If a line was found
			timeLineUndetected = 0;
		}

		else
		{
			//If no line was found
			timeLineUndetected++;

			//If no line was found for 10 seconds --> Landing.
			if (timeLineUndetected > 50)
			{
				allowFollowPath = false;
				ardrone->landing();
				timeLineUndetected = 0;
			}
		}
	}

	//Face detection
	if (ardrone->detectFaces(image))
	{
		peopleDetected = true;
		allowFollowPath = false;
	}
}

// --------------------------------------------------------------------------
// controller::IplImage2QImage(const IplImage* iplImage)
// Description : Convert an image from OpenCV to QImage
// Return value : Image at QImage format
// ------------------------------------------------------------------------
QImage controller::IplImage2QImage (const IplImage* iplImage)
{
	int height = iplImage->height;
    int width = iplImage->width;

    if(iplImage->depth == IPL_DEPTH_8U && iplImage->nChannels == 3)
    {
        const uchar *qImageBuffer = (const uchar*)iplImage->imageData;
        QImage img(qImageBuffer, width, height, QImage::Format_RGB888);
        return img.rgbSwapped();
    }

	else return QImage();
}


// --------------------------------------------------------------------------
// controller::controller()
// Description : Destructor of controller class.
// --------------------------------------------------------------------------
controller::~controller()
{
   windowMain->~Window_Main();
   windowDroneCamera->~Window_DroneCamera();
   ardrone->close();
}