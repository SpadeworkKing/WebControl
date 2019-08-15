#ifndef __DIFINE_H
#define __DIFINE_H

#pragma once

#define  kr(str) QString::fromLocal8Bit(str)


class cUserData
{
public:
	QString m_qsID;
	QString m_qsPW;
};

class cSiteData
{
public:
	QString m_qsSite;
};


#endif // !DIFINE_H
