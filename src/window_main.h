#ifndef WINDOW_MAIN_H
#define WINDOW_MAIN_H

#include <QtWidgets/QMainWindow>
#include "ui_window_main.h"

class Window_Main : public QMainWindow
{
	Q_OBJECT

public:
	//Constructor / Destructor
	Window_Main(QWidget *parent = 0); 
	~Window_Main();

	// --- Getters ---
	QWidget* getPushButtonStart();
	QWidget* getPushButtonStop();
	QWidget* getPushButtonDroneCamera();
	QLabel*  getImageDroneStatus();
	QLabel*  getImageBatteryLevel();
	QLabel*  getImageWarning();
	QLabel*  getLabelDroneStatus();
	QLabel*  getLabelBatteryLevel();
	QLabel*  getLabelWarning();
	QTextEdit* getTextWifiName();


private:
	Ui::Window_MainClass ui;
};

#endif // WINDOW_MAIN_H
