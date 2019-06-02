#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_WebControl.h"

class WebControl : public QMainWindow
{
	Q_OBJECT

public:
	WebControl(QWidget *parent = Q_NULLPTR);

private:
	Ui::WebControlClass ui;
};
