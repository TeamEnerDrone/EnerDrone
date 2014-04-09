#include "window_dronecamera.h"

//Constructor
Window_DroneCamera::Window_DroneCamera(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

//Destructor
Window_DroneCamera::~Window_DroneCamera() { }

// ---------------- GETTERS  -----------------------

QWidget* Window_DroneCamera::getPushButtonResume()
{
	return ui.pushButton_resume;
}

QWidget* Window_DroneCamera::getPushButtonStop()
{
	return ui.pushButton_stop;
}

QWidget* Window_DroneCamera::getPushButtonSwitchWindow()
{
	return ui.pushButton_switchWindow;
}

QLabel* Window_DroneCamera::getImageBatteryLevel()
{
	return ui.image_batteryLevel;
}

QLabel* Window_DroneCamera::getLabelBatteryLevel()
{
	return ui.label_batteryLevel;
}

QLabel* Window_DroneCamera::getImageDroneCamera()
{
	return ui.image_droneCamera;
}

QLabel* Window_DroneCamera::getImageWarning()
{
	return ui.image_warning;
}

QLabel* Window_DroneCamera::getLabelWarning()
{
	return ui.label_warning;
}
// ----------------- END GETTERS -------------------