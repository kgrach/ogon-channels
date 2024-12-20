
//========================================================================================================
//=============================== Классы запросов и ответов ==============================================
//========================================================================================================
#pragma once

#include <qglobal.h>
#include <qbytearray.h>

#include <vector>

struct REDIR_SCARDCONTEXT // MS-RDPESC 2.2.1.1
{	
	quint32 	_cbContext; 			// The number of bytes in the _pbContext
	QByteArray 	_pbContext; 			// littleEndian
//	QByteArray _pbContextReverse; 	// bigEndian
};

struct REDIR_SCARDHANDLE
{
	quint32 	_cbHandle;
	QByteArray 	_pbHandle;
};

// class Long_Call
// {
// 	qint32 _longValue;
// };

struct Long_Return
{
	qint32 _returnCode;
};

struct longAndMultiString_Return
{
	qint32 _returnCode;
	quint32 _cBytes;
	QByteArray _msz;
};

struct EstablishContext_Return
{	
	qint32 		_returnCode;
	REDIR_SCARDCONTEXT _hContext;
}; 

typedef longAndMultiString_Return ListReaders_Return;


class Connect_Return {
public:
	qint32 				_returnCode;
	REDIR_SCARDHANDLE 	_hCard;
	quint32 		 	_dwActiveProtocol;
};

class ReaderState // ReaderStateA и ReaderStateW. В зависимости от ioControlCode в _szReader хранится ASCII или Unicode
{
public:
	QByteArray 	_szReader;
//	LPVOID 		_pvUserData;
	quint32 	_dwCurrentState;
	quint32 	_dwEventState;
	quint32 	_cbAtr;
	QByteArray 	_rgbAtr; //[36];

	ReaderState();
}; 

struct ReaderState_Return
{
	quint32 _dwCurrentState;
	quint32 _dwEventState;
	/* [range] */ quint32 _cbAtr;
	QByteArray _rgbAtr; // [36]
};

struct GetStatusChange_Return
{
	qint32 		_returnCode;
	quint32 	_cReaders{0};
	std::vector<ReaderState_Return> _rgReaderStates;
}; 
