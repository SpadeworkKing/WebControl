#include "WebControl.h"
#include "QMessageBox"


CWebControl::CWebControl(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


void CWebControl::on_buttonIdAdd_clicked()
{
	addUser();
}

void CWebControl::on_buttonIdDel_clicked()
{
	delUser();
}

void CWebControl::addUser()
{
	QString qsID = ui.editID->text();
	QString qsPW = ui.editPW->text();

	if (qsID.isEmpty() == true)
	{
		QMessageBox::information(this, kr("정보"), kr("아이디를 입력해주세요"), kr("확인"));
		return;
	}

	if (qsPW.isEmpty() == true)
	{
		QMessageBox::information(this, kr("정보"), kr("비밀번호를 입력해주세요"), kr("확인"));
		return;
	}
	
	cUserData cUser;
	cUser.m_qsID = qsID;
	cUser.m_qsPW = qsPW;
	m_qlistUser.push_back(cUser);		// 리스트에 저장

	ui.listWidgetID->addItem(qsID);		// 화면에 표시

	ui.editID->setText("");
	ui.editPW->setText("");
}

void CWebControl::delUser()
{
	int nRow = ui.listWidgetID->currentRow();

	int nSize = ui.listWidgetID->count();
	if (nRow < nSize)
	{
		// 삭제코드 추가
	}
}