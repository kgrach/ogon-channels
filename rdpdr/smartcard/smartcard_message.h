
//========================================================================================================
//=============================== Классы запросов и ответов ==============================================
//========================================================================================================
#pragma once

#include <qglobal.h>
#include <qbytearray.h>

#include <vector>

#define PB_ATR_LEN 	32 	// see Status_Return
#define RGB_ATR_LEN 36 	// see ReaderState_Common_Call [MS-RDPESC] 2.2.1.5

struct REDIR_SCARDCONTEXT // MS-RDPESC 2.2.1.1
{	
	quint32 	_cbContext; 			// The number of bytes in the _pbContext
	QByteArray 	_pbContext; 			// littleEndian
};

struct REDIR_SCARDHANDLE
{
	REDIR_SCARDCONTEXT _Context;
	quint32 	_cbHandle; 		// The number of bytes in the pbHandle field
	QByteArray 	_pbHandle;		// An array of cbHandle bytes that corresponds to a smart card reader handle on the TS client
};

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
	quint32 	_dwCurrentState;
	quint32 	_dwEventState;
	quint32 	_cbAtr;
	QByteArray 	_rgbAtr; //[36];

	ReaderState();
}; 

class ReaderState_Return
{
public:	
	quint32 _dwCurrentState;
	quint32 _dwEventState;
	/* [range] */ quint32 _cbAtr;
	QByteArray _rgbAtr; // [36]

	ReaderState_Return();
	quint32 getSize() const {return sizeof(_dwCurrentState) + sizeof(_dwEventState) + sizeof(_cbAtr) + _rgbAtr.size();}
};

class GetStatusChange_Return
{
public:	
	qint32 		_returnCode;
	quint32 	_cReaders{0};
	std::vector<ReaderState_Return> _rgReaderStates;
}; 

class Status_Return {
public:	
	qint32 		_returnCode;
	quint32 	_cBytes;
	QByteArray 	_mszReaderNames;
	quint32 	_dwState;
	quint32 	_dwProtocol;
	QByteArray 	_pbAtr; // 32
	quint32 	_cbAtrLen;
	Status_Return();
};