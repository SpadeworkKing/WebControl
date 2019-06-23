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

	int nSize = ui.listWidgetID->count();
	if (nRow < nSize)
	{
		// �����ڵ� �߰�
	}
}