#include "WebControl.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>
#include <vld.h>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	CWebControl w;
	QDesktopWidget qDesctopWG;
	w.setFixedSize(qDesctopWG.width()*0.6, qDesctopWG.height()*0.6);
	w.show();
	return a.exec();
}
