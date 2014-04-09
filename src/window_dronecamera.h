#ifndef WINDOW_DRONECAMERA_H
#define WINDOW_DRONECAMERA_H

#include <QWidget>
#include "ui_window_dronecamera.h"

class Window_DroneCamera : public QWidget
{
	Q_OBJECT

public:
	//Constructor / Destructor
	Window_DroneCamera(QWidget *parent = 0);
	~Window_DroneCamera();

	// Getters
	QWidget* getPushButtonResume();
	QWidget* getPushButtonStop();
	QWidget* getPushButtonSwitchWindow();
	QLabel*  getImageBatteryLevel();
	QLabel*  getLabelBatteryLevel();
	QLabel*  getImageDroneCamera();
	QLabel*  getLabelWarning();
	QLabel*  getImageWarning();

private:
	Ui::Window_DroneCamera ui;
};

#endif // WINDOW_DRONECAMERA_H
