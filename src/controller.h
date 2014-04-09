#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "window_main.h"
#include "window_dronecamera.h"
#include "ardrone\ardrone.h"
#include <QObject>
#include <QImage>
#include <QMessageBox>
#include <QSound>

//Controller class
class controller : public QObject 
{
    Q_OBJECT

public:
	//Constructor / Destructor
    controller();
    ~controller();

	//Launch the application
    int startApplication(); 
	 

public slots:
	//Update graphically the windows
	void graphicalUpdate();

	//Take off the drone
	void startDrone();

	//Land the drone
	void stopDrone();

	//Allow the drone to move forward
	void resumeDrone();

	//Perform the image processing
	void imageProcessing();


private:
	//Data
	Window_Main* windowMain;
    Window_DroneCamera* windowDroneCamera;
    ARDrone* ardrone;
	bool allowFollowPath;
	bool peopleDetected;
	int timeLineUndetected;
	QSound warningBeep;

	//An other graphical update
	void graphicalUpdateBatteryLevel (QLabel* imageBatteryLevel, QLabel* labelBatteryLevel);

	//Convert an image from OpenCv to QImage 
	QImage IplImage2QImage(const IplImage *iplImage); 
};

#endif // CONTROLLER_H