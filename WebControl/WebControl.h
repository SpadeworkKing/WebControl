#ifndef __CWEBCONTROL_H
#define __CWEBCONTROL_H
#pragma once

#include <QtWidgets/QMainWindow>
#include <QList>
#include "Define.h"
#include "ui_WebControl.h"

class CWebControl : public QMainWindow
{
	Q_OBJECT

public:
	CWebControl(QWidget *parent = Q_NULLPTR);

private:
	Ui::WebControlClass ui;

private slots:
	void on_buttonIdAdd_clicked();
	void on_buttonIdDel_clicked();

private:
	void addUser();
	void delUser();
	
	QList<cUserData> m_qlistUser;

};


#endif // !__CWEBCONTROL_H