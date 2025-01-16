
//========================================================================================================
//=============================== Классы запросов и ответов ==============================================
//========================================================================================================
#pragma once

#include <qglobal.h>
#include <qbytearray.h>

#include <vector>
#include <memory>

#define PB_ATR_LEN 	32 	// see Status_Return
#define RGB_ATR_LEN 36 	// see ReaderState_Common_Call [MS-RDPESC] 2.2.1.5

struct REDIR_SCARDCONTEXT // MS-RDPESC 2.2.1.1
{	
	quint32 	_cbContext; 			// The number of bytes in the _pbContext
	QByteArray 	_pbContext; 			// littleEndian
};

struct REDIR_SCARDHANDLE
{
	REDIR_SCARDCONTEXT 	_Context;
	quint32 			_cbHandle; 		// The number of bytes in the pbHandle field
	QByteArray 			_pbHandle;		// An array of cbHandle bytes that corresponds to a smart card reader handle on the TS client
};

struct Long_Return
{
	quint32 	_returnCode {0x80100001}; // SCARD_F_INTERNAL_ERROR
};

struct longAndMultiString_Return
{
	quint32 		_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
	quint32 	_cBytes;
	QByteArray 	_msz;
};

struct EstablishContext_Return
{	
	quint32 				_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
	REDIR_SCARDCONTEXT 	_hContext;
}; 

typedef longAndMultiString_Return ListReaders_Return;

class SCardIO_Request{
public:
	quint32 	_dwProtocol;
	quint32 	_cbExtraBytes;
	QByteArray 	_pbExtraBytes;
};

class Connect_Return {
public:
	quint32 				_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
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
	quint32 	_dwCurrentState;
	quint32 	_dwEventState;
	quint32 	_cbAtr;
	QByteArray 	_rgbAtr; // [36]

	ReaderState_Return();
};

class GetStatusChange_Return
{
public:	
	quint32 							_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
	quint32 						_cReaders{0};
	std::vector<ReaderState_Return>	_rgReaderStates;
}; 

class Status_Return {
public:	
	quint32 		_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
	quint32 	_cBytes{0};
	QByteArray 	_mszReaderNames;
	quint32 	_dwState{0};
	quint32 	_dwProtocol{0};
	QByteArray 	_pbAtr; // 32
	quint32 	_cbAtrLen{0};
	Status_Return();
};

class Transmit_Return{
public:	
	quint32 	_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
	std::shared_ptr<SCardIO_Request> 	_pioRecvPci;
	quint32 	_cbRecvLength{0};
	QByteArray 	_pbRecvBuffer;
};

class Reconnect_Return{
public:	
	quint32 	_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
	quint32 	_dwActiveProtocol{0};
};

class Control_Return{
	public:	
	quint32 	_returnCode{0x80100001}; // SCARD_F_INTERNAL_ERROR
	quint32 	_cbOutBufferSize{0};
	QByteArray 	_pbOutBuffer;
};


// ===================== calls ========================
class HCardAndDisposition_Call{
public:	
	REDIR_SCARDHANDLE 	_hCard;
	quint32 			_dwDisposition;
};