#pragma once
//#include "../rdpdrchannelserver.h"

#include <winpr/smartcard.h>
#include <qglobal.h>
#include <qbytearray.h>
#include <ogon-channels/qt/rdpstreambuffer.h>

#include "../smartcard_driver/gen-cpp/ogon.h"
#include "../smartcard_driver/gen-cpp/ogon_types.h"
#include "smartcard_message.h"

#define RDPDR_DEVICE_IO_REQUEST_LENGTH		24
#define RDPDR_DEVICE_IO_RESPONSE_LENGTH		16

#define SMARTCARD_COMMON_TYPE_HEADER_LENGTH		8
#define SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH	8

#define RDP_SCARD_CTL_CODE(code) \
	CTL_CODE(FILE_DEVICE_FILE_SYSTEM, (code), METHOD_BUFFERED, FILE_ANY_ACCESS)

#define SCARD_IOCTL_ESTABLISHCONTEXT RDP_SCARD_CTL_CODE(5)       /* SCardEstablishContext */
#define SCARD_IOCTL_RELEASECONTEXT RDP_SCARD_CTL_CODE(6)         /* SCardReleaseContext */
#define SCARD_IOCTL_ISVALIDCONTEXT RDP_SCARD_CTL_CODE(7)         /* SCardIsValidContext */
#define SCARD_IOCTL_LISTREADERGROUPSA RDP_SCARD_CTL_CODE(8)      /* SCardListReaderGroupsA */
#define SCARD_IOCTL_LISTREADERGROUPSW RDP_SCARD_CTL_CODE(9)      /* SCardListReaderGroupsW */
#define SCARD_IOCTL_LISTREADERSA RDP_SCARD_CTL_CODE(10)          /* SCardListReadersA */
#define SCARD_IOCTL_LISTREADERSW RDP_SCARD_CTL_CODE(11)          /* SCardListReadersW */
#define SCARD_IOCTL_INTRODUCEREADERGROUPA RDP_SCARD_CTL_CODE(20) /* SCardIntroduceReaderGroupA */
#define SCARD_IOCTL_INTRODUCEREADERGROUPW RDP_SCARD_CTL_CODE(21) /* SCardIntroduceReaderGroupW */
#define SCARD_IOCTL_FORGETREADERGROUPA RDP_SCARD_CTL_CODE(22)    /* SCardForgetReaderGroupA */
#define SCARD_IOCTL_FORGETREADERGROUPW RDP_SCARD_CTL_CODE(23)    /* SCardForgetReaderGroupW */
#define SCARD_IOCTL_INTRODUCEREADERA RDP_SCARD_CTL_CODE(24)      /* SCardIntroduceReaderA */
#define SCARD_IOCTL_INTRODUCEREADERW RDP_SCARD_CTL_CODE(25)      /* SCardIntroduceReaderW */
#define SCARD_IOCTL_FORGETREADERA RDP_SCARD_CTL_CODE(26)         /* SCardForgetReaderA */
#define SCARD_IOCTL_FORGETREADERW RDP_SCARD_CTL_CODE(27)         /* SCardForgetReaderW */
#define SCARD_IOCTL_ADDREADERTOGROUPA RDP_SCARD_CTL_CODE(28)     /* SCardAddReaderToGroupA */
#define SCARD_IOCTL_ADDREADERTOGROUPW RDP_SCARD_CTL_CODE(29)     /* SCardAddReaderToGroupW */
#define SCARD_IOCTL_REMOVEREADERFROMGROUPA RDP_SCARD_CTL_CODE(30) /* SCardRemoveReaderFromGroupA */
#define SCARD_IOCTL_REMOVEREADERFROMGROUPW RDP_SCARD_CTL_CODE(31) /* SCardRemoveReaderFromGroupW */
#define SCARD_IOCTL_LOCATECARDSA RDP_SCARD_CTL_CODE(38)       /* SCardLocateCardsA */
#define SCARD_IOCTL_LOCATECARDSW RDP_SCARD_CTL_CODE(39)       /* SCardLocateCardsW */
#define SCARD_IOCTL_GETSTATUSCHANGEA RDP_SCARD_CTL_CODE(40)   /* SCardGetStatusChangeA */
#define SCARD_IOCTL_GETSTATUSCHANGEW RDP_SCARD_CTL_CODE(41)   /* SCardGetStatusChangeW */
#define SCARD_IOCTL_CANCEL RDP_SCARD_CTL_CODE(42)             /* SCardCancel */
#define SCARD_IOCTL_CONNECTA RDP_SCARD_CTL_CODE(43)           /* SCardConnectA */
#define SCARD_IOCTL_CONNECTW RDP_SCARD_CTL_CODE(44)           /* SCardConnectW */
#define SCARD_IOCTL_RECONNECT RDP_SCARD_CTL_CODE(45)          /* SCardReconnect */
#define SCARD_IOCTL_DISCONNECT RDP_SCARD_CTL_CODE(46)         /* SCardDisconnect */
#define SCARD_IOCTL_BEGINTRANSACTION RDP_SCARD_CTL_CODE(47)   /* SCardBeginTransaction */
#define SCARD_IOCTL_ENDTRANSACTION RDP_SCARD_CTL_CODE(48)     /* SCardEndTransaction */
#define SCARD_IOCTL_STATE RDP_SCARD_CTL_CODE(49)              /* SCardState */
#define SCARD_IOCTL_STATUSA RDP_SCARD_CTL_CODE(50)            /* SCardStatusA */
#define SCARD_IOCTL_STATUSW RDP_SCARD_CTL_CODE(51)            /* SCardStatusW */
#define SCARD_IOCTL_TRANSMIT RDP_SCARD_CTL_CODE(52)           /* SCardTransmit */
#define SCARD_IOCTL_CONTROL RDP_SCARD_CTL_CODE(53)            /* SCardControl */
#define SCARD_IOCTL_GETATTRIB RDP_SCARD_CTL_CODE(54)          /* SCardGetAttrib */
#define SCARD_IOCTL_SETATTRIB RDP_SCARD_CTL_CODE(55)          /* SCardSetAttrib */
#define SCARD_IOCTL_ACCESSSTARTEDEVENT RDP_SCARD_CTL_CODE(56) /* SCardAccessStartedEvent */
#define SCARD_IOCTL_RELEASESTARTEDEVENT RDP_SCARD_CTL_CODE(57) /* SCardReleaseStartedEvent */ // НЕ СООТВЕТСТВУЕТ С FREERDP !!!
#define SCARD_IOCTL_LOCATECARDSBYATRA RDP_SCARD_CTL_CODE(58)  /* SCardLocateCardsByATRA */
#define SCARD_IOCTL_LOCATECARDSBYATRW RDP_SCARD_CTL_CODE(59)  /* SCardLocateCardsByATRW */
#define SCARD_IOCTL_READCACHEA RDP_SCARD_CTL_CODE(60)         /* SCardReadCacheA */
#define SCARD_IOCTL_READCACHEW RDP_SCARD_CTL_CODE(61)         /* SCardReadCacheW */
#define SCARD_IOCTL_WRITECACHEA RDP_SCARD_CTL_CODE(62)        /* SCardWriteCacheA */
#define SCARD_IOCTL_WRITECACHEW RDP_SCARD_CTL_CODE(63)        /* SCardWriteCacheW */
#define SCARD_IOCTL_GETTRANSMITCOUNT RDP_SCARD_CTL_CODE(64)   /* SCardGetTransmitCount */
#define SCARD_IOCTL_GETREADERICON RDP_SCARD_CTL_CODE(65)      /* SCardGetReaderIconA */ // НЕ СООТВЕТСТВУЕТ С FREERDP !!!
#define SCARD_IOCTL_GETDEVICETYPEID RDP_SCARD_CTL_CODE(66)    /* SCardGetDeviceTypeIdA */ // НЕ СООТВЕТСТВУЕТ С FREERDP !!!

// Интерфейс для всех возможных запросов
class smartcardIOControl_Call {
protected:
	enum ndr_ptr_t
	{
		NDR_PTR_FULL,
		NDR_PTR_SIMPLE,
		NDR_PTR_FIXED
	};

	quint32 	_ioControlCode{0};
	QByteArray 	_inputBuffer;
	quint32 	_outputBufferLength{2048}; 	// [MS-RDPESC] 3.2.5.1

	void packCommonTypeHeader(QByteArray& buf);
	void packPrivateTypeHeader(QByteArray& buf, quint32 objectBufferLength);
	uint32_t packRedirScardContext(QByteArray& buf, const REDIR_SCARDCONTEXT& context, uint32_t& index, quint32& pbContextNdrPtr, quint32& offset); // RPC NDR [MS-RPCE 2.2.6.2]
	uint32_t packRedirScardHandle(QByteArray& buf, const REDIR_SCARDHANDLE& handle, uint32_t& index, quint32& pbContextNdrPtr, quint32& offset);
	int32_t packReaderState(QByteArray& buf, std::vector<ReaderState>& ppcReaders, quint32 cReaders, uint32_t& ptrIndex, quint32& offset, bool unicode);
	void packHcardAndDispositionCall(QByteArray& buf, const HCardAndDisposition_Call& call, quint32& offset);

	qint32 unpackCommonTypeHeader(RdpStreamBuffer& rsBuf);
	qint32 unpackPrivateTypeHeader(RdpStreamBuffer& rsBuf, quint32& objectBufferLength);

	uint32_t unpackRedirScardContext(RdpStreamBuffer& stream, REDIR_SCARDCONTEXT& context, uint32_t& index);
	int32_t unpackRedirScardHandle(RdpStreamBuffer& stream, REDIR_SCARDHANDLE& handle, uint32_t& index);
	int32_t unpackGetStatusChangeReturn(RdpStreamBuffer& stream, GetStatusChange_Return& ret, bool unicode);

	bool ndrPointerRead(RdpStreamBuffer& stream, uint32_t& index, quint32& ptr); // RPC NDR [MS-RPCE 2.2.6.2]
	bool ndrPointerWrite(QByteArray& buf, uint32_t& index, uint32_t length, quint32& ndrPtr, quint32& offset);
	
	uint32_t ndrWrite(QByteArray& buf, const QByteArray& data, quint32 size, uint32_t elementSize, ndr_ptr_t type, quint32& offset, bool unicode);
	uint32_t ndrRead(RdpStreamBuffer& stream, QByteArray& data, size_t min, size_t elementSize, ndr_ptr_t type);

	/*
	*  getPadding - вернет размер наполнителя и заполнит нулями сам наполнитель 
	* 	size - размер буфера в который нужно добавить наполнитель (Padding), например _inputBuffer
	* 	alignment - выравнивание для padding'а
	*/
	quint32 getPadding(QByteArray& bufPadding, quint32 size, quint32 alignment = 8);

	/* unpackReadSizeAlign - сдвинет указатель потока на значение наполнителя и вернет это значение */
	quint32 unpackReadSizeAlign(RdpStreamBuffer& stream, size_t size, quint32 alignment = 8);

public:
	virtual ~smartcardIOControl_Call() noexcept = default;

	const char* getIOctlString(bool funcName); // вернет строковое название ioControlCode

	virtual quint32 getIoControlCode() { return _ioControlCode; }
	virtual quint32 getOutputBufferLength() { return _outputBufferLength; }
	virtual const QByteArray& getInputBuffer() const { return _inputBuffer; }

	virtual void setResponse(QByteArray& buf) = 0;
	virtual quint64 getReturnCode() const = 0;
	virtual const QByteArray& getReturnReply() const = 0;
};

class ScardAccessStartedEvent_Call : public smartcardIOControl_Call
{
public:
	ScardAccessStartedEvent_Call();
	virtual ~ScardAccessStartedEvent_Call() noexcept = default;
	void setResponse(QByteArray& buf) override {}
	quint64 getReturnCode() const override {return 0; }
	const QByteArray& getReturnReply() const override { return QByteArray();}
};

class EstablishContext_Call : public smartcardIOControl_Call
{
	// enum scope {
	// 	SCARD_SCOPE_USER = 0x00000000,
	// 	SCARD_SCOPE_TERMINAL = 0x00000001,
	// 	SCARD_SCOPE_SYSTEM = 0x00000002
	// };

	quint32 _dwScope;
	EstablishContext_Return _response;

public:
	EstablishContext_Call();
	virtual ~EstablishContext_Call() noexcept = default;
	void setResponse(QByteArray& buf) override;
	quint64 getReturnCode() const override {return _response._returnCode; }
	const QByteArray& getReturnReply() const override {return _response._hContext._pbContext;}
};

class ListReaders_Call :  public smartcardIOControl_Call {
	REDIR_SCARDCONTEXT 	_hContext;
	quint32 			_cBytes{0};
	QByteArray 			_mszGroups;
//	QString 			_mszGroups;
	quint32 			_fmszReadersIsNULL{0};
	quint32				_ccReaders{0};

	ListReaders_Return	_response;

public:
	ListReaders_Call(quint64 hContext, const std::string& readerName, quint32 ioControlCode = SCARD_IOCTL_LISTREADERSA);
	virtual ~ListReaders_Call()  noexcept = default;

	void setResponse(QByteArray& buf) override;
	quint64 getReturnCode() const override {return _response._returnCode; }
	const QByteArray& getReturnReply() const override {return _response._msz;}
	quint32 getReturnCBytes() const {return _response._cBytes;}
};

class Connect_Call :  public smartcardIOControl_Call {
	
	QByteArray 			_szReader;
	// QString 			_szReader;
	// Connect_Common struct:
	REDIR_SCARDCONTEXT 	_hContext;
	quint32 			_dwShareMode;
	quint32 			_dwPreferredProtocols;

	Connect_Return		_response;

public:
	Connect_Call(quint64 hContext, const std::string& szReader, int64_t dwShareMode, int64_t dwPreferredProtocols, quint32 ioControlCode = SCARD_IOCTL_CONNECTA);
	virtual ~Connect_Call()  noexcept = default;

	void setResponse(QByteArray& buf) override;
	quint64 getReturnCode() const override {return _response._returnCode; }
	const QByteArray& getReturnReply() const override {return _response._hCard._pbHandle;}
//	int64_t getHCard() const {return _response._hCard._pbHandle;}
	quint32 getActiveProtocol() const {return _response._dwActiveProtocol;}
};

class GetStatusChange_Call :  public smartcardIOControl_Call {
	REDIR_SCARDCONTEXT 	_hContext;
	quint32 			_dwTimeOut{0xFFFFFFFF};
	quint32 			_cReaders{0};
	std::vector<ReaderState> _rgReaderStates;

	GetStatusChange_Return	_response;

public:
	GetStatusChange_Call(quint64 hContext, const DWORD_RPC dwTimeout, const std::vector<scard_readerstate_rpc> & rgReaderStates, quint32 cReaders, quint32 ioControlCode = SCARD_IOCTL_GETSTATUSCHANGEA);
	virtual ~GetStatusChange_Call()  noexcept = default;

	void setResponse(QByteArray& buf) override;
	quint64 getReturnCode() const override {return _response._returnCode; }
	const QByteArray& getReturnReply() const override {return QByteArray();}
	const std::vector<ReaderState_Return>& getGetStatusChange_Return() const {return _response._rgReaderStates;}
};

class Status_Call :  public smartcardIOControl_Call {
	
	REDIR_SCARDHANDLE 	_hCard;
	quint32	 			_fmszReaderNamesIsNULL;
	quint32 			_cchReaderLen;
	quint32 			_cbAtrLen;

	Status_Return		_response;

public:
	Status_Call(quint64 hCard, quint64 hContext, int64_t cchReaderLen, int64_t cbAtrLen, quint32 ioControlCode = SCARD_IOCTL_STATUSA);
	virtual ~Status_Call()  noexcept = default;

	void setResponse(QByteArray& buf) override;
	quint64 getReturnCode() const override {return _response._returnCode; }
	const QByteArray& getReturnReply() const override {return _response._pbAtr;}
	const QByteArray& getReaderNames() const {return _response._mszReaderNames;}
	quint32 getDwState() {return _response._dwState;}
	quint32 getDwProtocol() {return _response._dwProtocol;}
};

class Transmit_Call :  public smartcardIOControl_Call {
	
	REDIR_SCARDHANDLE 	_hCard;
	SCardIO_Request		_ioSendPci;
	quint32 			_cbSendLength;
	QByteArray 			_pbSendBuffer;
	// QString				_pbSendBuffer;
	std::shared_ptr<SCardIO_Request> 	_pioRecvPci;
	quint32				_fpbRecvBufferIsNULL;
	quint32 			_cbRecvLength;

	Transmit_Return		_response;

public:
	Transmit_Call(quint64 hCard, quint64 hContext, const scard_io_request_rpc&  pioSendPci, const std::string& pbSendBuffer, quint64 pcbRecvLength, quint32 ioControlCode = SCARD_IOCTL_TRANSMIT);
	virtual ~Transmit_Call()  noexcept = default;

	void setResponse(QByteArray& buf) override;
	quint64 getReturnCode() const override {return _response._returnCode; }
	const QByteArray& getReturnReply() const override {return _response._pbRecvBuffer;}
	quint32 getCbRecvLength() const { return _response._cbRecvLength; }
};


class Disconnect_Call :  public smartcardIOControl_Call {
	
	HCardAndDisposition_Call _call;

	Long_Return			_response;

public:
	Disconnect_Call(quint64 hCard, quint64 hContext, int64_t dwDisposition, quint32 ioControlCode = SCARD_IOCTL_DISCONNECT);
	virtual ~Disconnect_Call()  noexcept = default;

	void setResponse(QByteArray& buf) override;
	quint64 getReturnCode() const override {return _response._returnCode; }
	const QByteArray& getReturnReply() const override {return QByteArray();}
};