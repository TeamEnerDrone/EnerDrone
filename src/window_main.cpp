#include "window_main.h"


// --------------------------------------------------------------------------
// Window_Main::Window_Main(Widget Parent)
// Description : Constructor of Window_Main class.
// --------------------------------------------------------------------------
Window_Main::Window_Main(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

// --------------------------------------------------------------------------
// Window_Main::~Window_Main()
// Description : Destructor of Window_Main class.
// --------------------------------------------------------------------------
Window_Main::~Window_Main() { }


// ------------- GETTERS -----------------

QWidget* Window_Main::getPushButtonStart()
{
	return ui.pushButton_start;
}

QWidget* Window_Main::getPushButtonStop()
{
	return ui.pushButton_stop;
}

QWidget* Window_Main::getPushButtonDroneCamera()
{
	return ui.pushButton_DroneCamera;
}

QLabel* Window_Main::getImageBatteryLevel()
{
	return ui.image_batteryLevel;
}

QLabel* Window_Main::getImageDroneStatus()
{
	return ui.image_droneStatus;
}

QLabel* Window_Main::getImageWarning()
{
	return ui.image_warning;
}

QLabel* Window_Main::getLabelBatteryLevel()
{
	return ui.label_batteryLevel;
}

QTextEdit* Window_Main::getTextWifiName()
{
	return ui.textEdit_droneName;
}

QLabel* Window_Main::getLabelDroneStatus()
{
	return ui.label_droneStatus;
}

QLabel* Window_Main::getLabelWarning()
{
	return ui.label_warning;
}

// ----------------- END GETTERS -------------------