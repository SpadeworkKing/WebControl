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

	void on_buttonSiteAdd_clicked();
	void on_buttonSiteDel_clicked();

private:
	void addUser();
	void delUser();

	void addSite();
	void delSite();
	
	QList<cUserData> m_qlistUser;	// user id,pw 리스트
	QList<cSiteData> m_qlistSite;	// site 리스트

};


#endif // !__CWEBCONTROL_H