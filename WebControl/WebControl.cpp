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

void CWebControl::on_buttonSiteAdd_clicked()
{
	addSite();
}

void CWebControl::on_buttonSiteDel_clicked()
{
	delSite();
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
	if (nRow < 0)
	{
		QMessageBox::warning(this, kr("경고"), kr("삭제할 아이디가 선택되지 않았습니다."), kr("확인"));
	}

	int nSize = ui.listWidgetID->count();
	if (nRow < nSize)
	{
		m_qlistUser.removeAt(nRow);			// 리스트에서 삭제
		ui.listWidgetID->takeItem(nRow);	// 리스트위젯에서 삭제
	}
}

void CWebControl::addSite()
{
	QString qsSite = ui.editSite->text();

	if (qsSite.isEmpty() == true)
	{
		QMessageBox::information(this, kr("정보"), kr("홈페이지를 입력해주세요"), kr("확인"));
		return;
	}

	cSiteData cSite;
	cSite.m_qsSite = qsSite;

	m_qlistSite.push_back(cSite);		// 리스트에 저장
	ui.listWidgetSite->addItem(qsSite);		// 화면에 표시

	ui.editSite->setText("");
}

void CWebControl::delSite()
{
	int nRow = ui.listWidgetSite->currentRow();
	if (nRow < 0)
	{
		QMessageBox::warning(this, kr("경고"), kr("삭제할 홈페이지가 선택되지 않았습니다."), kr("확인"));
	}

	int nSize = ui.listWidgetSite->count();
	if (nRow < nSize)
	{
		m_qlistSite.removeAt(nRow);			// 리스트에서 삭제
		ui.listWidgetSite->takeItem(nRow);	// 리스트위젯에서 삭제
	}
}