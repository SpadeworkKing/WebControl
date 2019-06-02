#include "WebControl.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	WebControl w;
	w.show();
	return a.exec();
}
