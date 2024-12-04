
//========================================================================================================
//=============================== Классы запросов и ответов ==============================================
//========================================================================================================
#pragma once

#include <qglobal.h>
#include <qbytearray.h>

#include <vector>

class REDIR_SCARDCONTEXT // MS-RDPESC 2.2.1.1
{
	quint32 _cbContext;
	QByteArray _pbContext;
};

class REDIR_SCARDHANDLE
{
	quint32 _cbHandle;
	QByteArray _pbHandle;
};

class Long_Call
{
	qint32 _longValue;
};

class Long_Return
{
	qint32 _returnCode;
};

class longAndMultiString_Return
{
	qint32 _returnCode;
	quint32 _cBytes;
	QByteArray _msz;
};

class EstablishContext_Return
{
public:	
	qint32 _returnCode;
//	REDIR_SCARDCONTEXT hContext;
	QByteArray _hContext;

// public:
// 	void setReturnCode(qint32 ret);
// 	void setContext(const QByteArray& context);
}; 