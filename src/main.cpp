#include "controller.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	//Create the application and set style
	QApplication a(argc, argv);
	a.setStyle("Fusion");

	//Instanciate the controller of the application
	controller control;

	//Start the application
	int res = control.startApplication();

	if (res == -1) return -1;
	
	else
		return a.exec();
}
