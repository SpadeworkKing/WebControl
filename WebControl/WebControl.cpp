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
		QMessageBox::information(this, kr("����"), kr("���̵� �Է����ּ���"), kr("Ȯ��"));
		return;
	}

	if (qsPW.isEmpty() == true)
	{
		QMessageBox::information(this, kr("����"), kr("��й�ȣ�� �Է����ּ���"), kr("Ȯ��"));
		return;
	}
	
	cUserData cUser;
	cUser.m_qsID = qsID;
	cUser.m_qsPW = qsPW;

	m_qlistUser.push_back(cUser);		// ����Ʈ�� ����
	ui.listWidgetID->addItem(qsID);		// ȭ�鿡 ǥ��

	ui.editID->setText("");
	ui.editPW->setText("");
}

void CWebControl::delUser()
{
	int nRow = ui.listWidgetID->currentRow();
	if (nRow < 0)
	{
		QMessageBox::warning(this, kr("���"), kr("������ ���̵� ���õ��� �ʾҽ��ϴ�."), kr("Ȯ��"));
	}

	int nSize = ui.listWidgetID->count();
	if (nRow < nSize)
	{
		m_qlistUser.removeAt(nRow);			// ����Ʈ���� ����
		ui.listWidgetID->takeItem(nRow);	// ����Ʈ�������� ����
	}
}

void CWebControl::addSite()
{
	QString qsSite = ui.editSite->text();

	if (qsSite.isEmpty() == true)
	{
		QMessageBox::information(this, kr("����"), kr("Ȩ�������� �Է����ּ���"), kr("Ȯ��"));
		return;
	}

	cSiteData cSite;
	cSite.m_qsSite = qsSite;

	m_qlistSite.push_back(cSite);		// ����Ʈ�� ����
	ui.listWidgetSite->addItem(qsSite);		// ȭ�鿡 ǥ��

	ui.editSite->setText("");
}

void CWebControl::delSite()
{
	int nRow = ui.listWidgetSite->currentRow();
	if (nRow < 0)
	{
		QMessageBox::warning(this, kr("���"), kr("������ Ȩ�������� ���õ��� �ʾҽ��ϴ�."), kr("Ȯ��"));
	}

	int nSize = ui.listWidgetSite->count();
	if (nRow < nSize)
	{
		m_qlistSite.removeAt(nRow);			// ����Ʈ���� ����
		ui.listWidgetSite->takeItem(nRow);	// ����Ʈ�������� ����
	}
}