#pragma once

#include <QObject>

class NetworkControl : public QObject
{
	Q_OBJECT

public:
	NetworkControl(QObject *parent);
	~NetworkControl();
};
