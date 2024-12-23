#include "smartcard_operations.h"
#include "QByteArrayWriteInteger.h"
#include <ogon-channels/logging.h>

//#include <locale> // для конвертера из UNICODE в ASCII

#define TAG CWLOG_TAG("rdpdr_SCARD")

const char* smartcardIOControl_Call::getIOctlString(bool funcName){
	switch (_ioControlCode)
	{
		case SCARD_IOCTL_ESTABLISHCONTEXT:
			return funcName ? "SCardEstablishContext" : "SCARD_IOCTL_ESTABLISHCONTEXT";

		case SCARD_IOCTL_RELEASECONTEXT:
			return funcName ? "SCardReleaseContext" : "SCARD_IOCTL_RELEASECONTEXT";

		case SCARD_IOCTL_ISVALIDCONTEXT:
			return funcName ? "SCardIsValidContext" : "SCARD_IOCTL_ISVALIDCONTEXT";

		case SCARD_IOCTL_LISTREADERGROUPSA:
			return funcName ? "SCardListReaderGroupsA" : "SCARD_IOCTL_LISTREADERGROUPSA";

		case SCARD_IOCTL_LISTREADERGROUPSW:
			return funcName ? "SCardListReaderGroupsW" : "SCARD_IOCTL_LISTREADERGROUPSW";

		case SCARD_IOCTL_LISTREADERSA:
			return funcName ? "SCardListReadersA" : "SCARD_IOCTL_LISTREADERSA";

		case SCARD_IOCTL_LISTREADERSW:
			return funcName ? "SCardListReadersW" : "SCARD_IOCTL_LISTREADERSW";

		case SCARD_IOCTL_INTRODUCEREADERGROUPA:
			return funcName ? "SCardIntroduceReaderGroupA" : "SCARD_IOCTL_INTRODUCEREADERGROUPA";

		case SCARD_IOCTL_INTRODUCEREADERGROUPW:
			return funcName ? "SCardIntroduceReaderGroupW" : "SCARD_IOCTL_INTRODUCEREADERGROUPW";

		case SCARD_IOCTL_FORGETREADERGROUPA:
			return funcName ? "SCardForgetReaderGroupA" : "SCARD_IOCTL_FORGETREADERGROUPA";

		case SCARD_IOCTL_FORGETREADERGROUPW:
			return funcName ? "SCardForgetReaderGroupW" : "SCARD_IOCTL_FORGETREADERGROUPW";

		case SCARD_IOCTL_INTRODUCEREADERA:
			return funcName ? "SCardIntroduceReaderA" : "SCARD_IOCTL_INTRODUCEREADERA";

		case SCARD_IOCTL_INTRODUCEREADERW:
			return funcName ? "SCardIntroduceReaderW" : "SCARD_IOCTL_INTRODUCEREADERW";

		case SCARD_IOCTL_FORGETREADERA:
			return funcName ? "SCardForgetReaderA" : "SCARD_IOCTL_FORGETREADERA";

		case SCARD_IOCTL_FORGETREADERW:
			return funcName ? "SCardForgetReaderW" : "SCARD_IOCTL_FORGETREADERW";

		case SCARD_IOCTL_ADDREADERTOGROUPA:
			return funcName ? "SCardAddReaderToGroupA" : "SCARD_IOCTL_ADDREADERTOGROUPA";

		case SCARD_IOCTL_ADDREADERTOGROUPW:
			return funcName ? "SCardAddReaderToGroupW" : "SCARD_IOCTL_ADDREADERTOGROUPW";

		case SCARD_IOCTL_REMOVEREADERFROMGROUPA:
			return funcName ? "SCardRemoveReaderFromGroupA" : "SCARD_IOCTL_REMOVEREADERFROMGROUPA";

		case SCARD_IOCTL_REMOVEREADERFROMGROUPW:
			return funcName ? "SCardRemoveReaderFromGroupW" : "SCARD_IOCTL_REMOVEREADERFROMGROUPW";

		case SCARD_IOCTL_LOCATECARDSA:
			return funcName ? "SCardLocateCardsA" : "SCARD_IOCTL_LOCATECARDSA";

		case SCARD_IOCTL_LOCATECARDSW:
			return funcName ? "SCardLocateCardsW" : "SCARD_IOCTL_LOCATECARDSW";

		case SCARD_IOCTL_GETSTATUSCHANGEA:
			return funcName ? "SCardGetStatusChangeA" : "SCARD_IOCTL_GETSTATUSCHANGEA";

		case SCARD_IOCTL_GETSTATUSCHANGEW:
			return funcName ? "SCardGetStatusChangeW" : "SCARD_IOCTL_GETSTATUSCHANGEW";

		case SCARD_IOCTL_CANCEL:
			return funcName ? "SCardCancel" : "SCARD_IOCTL_CANCEL";

		case SCARD_IOCTL_CONNECTA:
			return funcName ? "SCardConnectA" : "SCARD_IOCTL_CONNECTA";

		case SCARD_IOCTL_CONNECTW:
			return funcName ? "SCardConnectW" : "SCARD_IOCTL_CONNECTW";

		case SCARD_IOCTL_RECONNECT:
			return funcName ? "SCardReconnect" : "SCARD_IOCTL_RECONNECT";

		case SCARD_IOCTL_DISCONNECT:
			return funcName ? "SCardDisconnect" : "SCARD_IOCTL_DISCONNECT";

		case SCARD_IOCTL_BEGINTRANSACTION:
			return funcName ? "SCardBeginTransaction" : "SCARD_IOCTL_BEGINTRANSACTION";

		case SCARD_IOCTL_ENDTRANSACTION:
			return funcName ? "SCardEndTransaction" : "SCARD_IOCTL_ENDTRANSACTION";

		case SCARD_IOCTL_STATE:
			return funcName ? "SCardState" : "SCARD_IOCTL_STATE";

		case SCARD_IOCTL_STATUSA:
			return funcName ? "SCardStatusA" : "SCARD_IOCTL_STATUSA";

		case SCARD_IOCTL_STATUSW:
			return funcName ? "SCardStatusW" : "SCARD_IOCTL_STATUSW";

		case SCARD_IOCTL_TRANSMIT:
			return funcName ? "SCardTransmit" : "SCARD_IOCTL_TRANSMIT";

		case SCARD_IOCTL_CONTROL:
			return funcName ? "SCardControl" : "SCARD_IOCTL_CONTROL";

		case SCARD_IOCTL_GETATTRIB:
			return funcName ? "SCardGetAttrib" : "SCARD_IOCTL_GETATTRIB";

		case SCARD_IOCTL_SETATTRIB:
			return funcName ? "SCardSetAttrib" : "SCARD_IOCTL_SETATTRIB";

		case SCARD_IOCTL_ACCESSSTARTEDEVENT:
			return funcName ? "SCardAccessStartedEvent" : "SCARD_IOCTL_ACCESSSTARTEDEVENT";

		case SCARD_IOCTL_LOCATECARDSBYATRA:
			return funcName ? "SCardLocateCardsByATRA" : "SCARD_IOCTL_LOCATECARDSBYATRA";

		case SCARD_IOCTL_LOCATECARDSBYATRW:
			return funcName ? "SCardLocateCardsByATRB" : "SCARD_IOCTL_LOCATECARDSBYATRW";

		case SCARD_IOCTL_READCACHEA:
			return funcName ? "SCardReadCacheA" : "SCARD_IOCTL_READCACHEA";

		case SCARD_IOCTL_READCACHEW:
			return funcName ? "SCardReadCacheW" : "SCARD_IOCTL_READCACHEW";

		case SCARD_IOCTL_WRITECACHEA:
			return funcName ? "SCardWriteCacheA" : "SCARD_IOCTL_WRITECACHEA";

		case SCARD_IOCTL_WRITECACHEW:
			return funcName ? "SCardWriteCacheW" : "SCARD_IOCTL_WRITECACHEW";

		case SCARD_IOCTL_GETTRANSMITCOUNT:
			return funcName ? "SCardGetTransmitCount" : "SCARD_IOCTL_GETTRANSMITCOUNT";

		case SCARD_IOCTL_RELEASESTARTEDEVENT:
			return funcName ? "SCardReleaseStartedEvent" : "SCARD_IOCTL_RELEASESTARTEDEVENT";

		case SCARD_IOCTL_GETREADERICON:
			return funcName ? "SCardGetReaderIcon" : "SCARD_IOCTL_GETREADERICON";

		case SCARD_IOCTL_GETDEVICETYPEID:
			return funcName ? "SCardGetDeviceTypeId" : "SCARD_IOCTL_GETDEVICETYPEID";

		default:
			return funcName ? "SCardUnknown" : "SCARD_IOCTL_UNKNOWN";
	}

	return funcName ? "SCardUnknown" : "SCARD_IOCTL_UNKNOWN";
}

quint32 smartcardIOControl_Call::getPadding(QByteArray& bufPadding, quint32 size, quint32 alignment){
	quint32 pad;
	pad = size;
	size = (size + alignment - 1) & ~(alignment - 1);
	pad = size - pad;

	if (pad){
		bufPadding.fill('\0', pad);
	}

	return pad;
}

void smartcardIOControl_Call::packCommonTypeHeader(QByteArray& buf){
	/* See MS-RPCE */
	quint8 version = 1; 			/* Version (1 byte) */
	quint8 endianness = 0x10;		/* Endianness (1 byte) 0x10 - Little-endian; 0x00 - Big-endian. Remmina использует только Little-endian*/
	quint16 commonHeaderLength = 8; /* CommonHeaderLength (2 bytes) */
	quint32 filler = 0xCCCCCCCC; 	/* Filler (4 bytes), should be 0xCCCCCCCC */
	buf << version << endianness << commonHeaderLength << filler;
}

void smartcardIOControl_Call::packPrivateTypeHeader(QByteArray& buf, 
		quint32 objectBufferLength){  	/* objectBufferLength (4 bytes) including padding length)*/
	quint32 filler = 0x00000000; 		/* Filler (4 bytes), should be 0x00000000 */
	buf << objectBufferLength << filler;
}

// qint32 smartcardIOControl_Call::unpackCommonTypeHeader(int size, QDataStream& buf){
// 	quint8 version; 			/* Version (1 byte), should be 1 */
// 	quint8 endianness;			/* Endianness (1 byte) 0x10 - Little-endian; 0x00 - Big-endian. Remmina использует только Little-endian*/
// 	quint16 commonHeaderLength; /* CommonHeaderLength (2 bytes), should be 8 */
// 	quint32 filler; 			/* Filler (4 bytes), should be 0xCCCCCCCC */

// 	if (size < SMARTCARD_COMMON_TYPE_HEADER_LENGTH) {
// 		CWLOG_WRN(TAG, "CommonTypeHeader is too short: %" PRIuz "", size);
// 		return STATUS_BUFFER_TOO_SMALL;
// 	}
// 	// QDataStream ds(buf);
// 	// ds.setByteOrder(QDataStream::LittleEndian);

// 	// ds >> version;
// 	// ds >> endianness;
// 	// ds >> commonHeaderLength;
// 	// ds >> filler;

// 	buf >> version;
// 	buf >> endianness;
// 	buf >> commonHeaderLength;
// 	buf >> filler;

// 	if (version != 1)
// 	{
// 		CWLOG_WRN(TAG, "Unsupported CommonTypeHeader Version %" PRIu8 "", version);
// 		return STATUS_INVALID_PARAMETER;
// 	}

// 	if (endianness != 0x10)
// 	{
// 		CWLOG_WRN(TAG, "Unsupported CommonTypeHeader Endianness %" PRIu8 "", endianness);
// 		return STATUS_INVALID_PARAMETER;
// 	}

// 	if (commonHeaderLength != 8)
// 	{
// 		CWLOG_WRN(TAG, "Unsupported CommonTypeHeader CommonHeaderLength %" PRIu16 "", commonHeaderLength);
// 		return STATUS_INVALID_PARAMETER;
// 	}

// 	if (filler != 0xCCCCCCCC)
// 	{
// 		CWLOG_WRN(TAG, "Unexpected CommonTypeHeader Filler 0x%08" PRIX32 "", filler);
// 		return STATUS_INVALID_PARAMETER;
// 	}

// 	return SCARD_S_SUCCESS;
// }

// qint32 smartcardIOControl_Call::unpackPrivateTypeHeader(int size, QDataStream& buf){

// 	if (size < (SMARTCARD_COMMON_TYPE_HEADER_LENGTH + SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH)) {
// 		CWLOG_WRN(TAG, "PrivateTypeHeader is too short: %" PRIuz "", size);
// 		return STATUS_BUFFER_TOO_SMALL;
// 	}

// 	quint32 objectBufferLength;  	/* objectBufferLength (4 bytes) including padding length)*/
// 	quint32 filler;			 		/* Filler (4 bytes), should be 0x00000000 */

// 	buf >> objectBufferLength;
// 	buf >> filler;

// 	if (filler != 0x00000000)
// 	{
// 		CWLOG_WRN(TAG, "Unexpected PrivateTypeHeader Filler 0x%08" PRIX32 "", filler);
// 		return STATUS_INVALID_PARAMETER;
// 	}

// 	auto remaining = size + SMARTCARD_COMMON_TYPE_HEADER_LENGTH - buf.device()->pos();
// 	if (objectBufferLength != remaining)
// 	{
// 		CWLOG_WRN(TAG,
// 		          "PrivateTypeHeader ObjectBufferLength mismatch: Actual: %" PRIu32 ", Expected: %" PRIuz "",
// 		          objectBufferLength, remaining);
// 		return STATUS_INVALID_PARAMETER;
// 	}
	
// 	return SCARD_S_SUCCESS;
// }


qint32 smartcardIOControl_Call::unpackCommonTypeHeader(RdpStreamBuffer& rsBuf){
	quint8 version; 			/* Version (1 byte), should be 1 */
	quint8 endianness;			/* Endianness (1 byte) 0x10 - Little-endian; 0x00 - Big-endian. Remmina использует только Little-endian*/
	quint16 commonHeaderLength; /* CommonHeaderLength (2 bytes), should be 8 */
	quint32 filler; 			/* Filler (4 bytes), should be 0xCCCCCCCC */

	if (!rsBuf.verifyRemainingLength(SMARTCARD_COMMON_TYPE_HEADER_LENGTH)) {
		CWLOG_WRN(TAG, "CommonTypeHeader is too short: %" PRIuz "", rsBuf.remainingLength());
		return STATUS_BUFFER_TOO_SMALL;
	}
	
	rsBuf >> version;
	rsBuf >> endianness;
	rsBuf >> commonHeaderLength;
	rsBuf >> filler;

	if (version != 1)
	{
		CWLOG_WRN(TAG, "Unsupported CommonTypeHeader Version %" PRIu8 "", version);
		return STATUS_INVALID_PARAMETER;
	}

	if (endianness != 0x10)
	{
		CWLOG_WRN(TAG, "Unsupported CommonTypeHeader Endianness %" PRIu8 "", endianness);
		return STATUS_INVALID_PARAMETER;
	}

	if (commonHeaderLength != 8)
	{
		CWLOG_WRN(TAG, "Unsupported CommonTypeHeader CommonHeaderLength %" PRIu16 "", commonHeaderLength);
		return STATUS_INVALID_PARAMETER;
	}

	if (filler != 0xCCCCCCCC)
	{
		CWLOG_WRN(TAG, "Unexpected CommonTypeHeader Filler 0x%08" PRIX32 "", filler);
		return STATUS_INVALID_PARAMETER;
	}

	return SCARD_S_SUCCESS;
}
qint32 smartcardIOControl_Call::unpackPrivateTypeHeader(RdpStreamBuffer& rsBuf, 
	quint32& objectBufferLength){  	/* objectBufferLength (4 bytes) including padding length)*/
	quint32 filler;			 		/* Filler (4 bytes), should be 0x00000000 */

	if (!rsBuf.verifyRemainingLength(SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH)) {
		CWLOG_WRN(TAG, "PrivateTypeHeader is too short: %" PRIuz "", rsBuf.remainingLength());
		return STATUS_BUFFER_TOO_SMALL;
	}

	rsBuf >> objectBufferLength;
	rsBuf >> filler;

	if (filler != 0x00000000)
	{
		CWLOG_WRN(TAG, "Unexpected PrivateTypeHeader Filler 0x%08" PRIX32 "", filler);
		return STATUS_INVALID_PARAMETER;
	}

	if (objectBufferLength != rsBuf.remainingLength())
	{
		CWLOG_WRN(TAG,
		          "PrivateTypeHeader ObjectBufferLength mismatch: Actual: %" PRIu32 ", Expected: %" PRIuz "",
		          objectBufferLength, rsBuf.remainingLength());
		return STATUS_INVALID_PARAMETER;
	}
	
	return SCARD_S_SUCCESS;
}

uint32_t smartcardIOControl_Call::packRedirScardContext(const REDIR_SCARDCONTEXT& context, uint32_t& index, quint32& pbContextNdrPtr){
 
	//const quint32 
	pbContextNdrPtr = 0x00020000 + index * 4;

	if (context._cbContext != 0)
	{
		_inputBuffer << context._cbContext;			/* cbContext (4 bytes) */
		_inputBuffer << pbContextNdrPtr;			/* pbContextNdrPtr (4 bytes) */
		++index;
	}
	else {
		quint64 zeroNDR = 0;
		_inputBuffer << zeroNDR;
	}
	
	return SCARD_S_SUCCESS;
}

uint32_t smartcardIOControl_Call::unpackRedirScardContext(RdpStreamBuffer& stream, REDIR_SCARDCONTEXT& context, uint32_t& index) {
 
	quint32 pbContextNdrPtr;


	if (!stream.verifyRemainingLength(4))
	{
		CWLOG_DBG(TAG, "REDIR_SCARDCONTEXT is too short: %" PRIuz "", stream.remainingLength());
		return STATUS_BUFFER_TOO_SMALL;
	}

	stream >> context._cbContext; /* cbContext (4 bytes) */

	if (stream.remainingLength() < context._cbContext)
	{
		CWLOG_DBG(TAG, "REDIR_SCARDCONTEXT is too short: Actual: %" PRIuz ", Expected: %" PRIu32 "",
		          stream.remainingLength(), context._cbContext);
  
		return STATUS_BUFFER_TOO_SMALL;
	}

	if ((context._cbContext != 0) && (context._cbContext != 4) && (context._cbContext != 8))
	{
		CWLOG_DBG(TAG, "REDIR_SCARDCONTEXT length is not 0, 4 or 8: %" PRIu32 "", context._cbContext);
  
		return STATUS_INVALID_PARAMETER;
	}

	if (!ndrPointerRead(stream, index, &pbContextNdrPtr)){
  
		return ERROR_INVALID_DATA;
    }

	if (((context._cbContext == 0) && pbContextNdrPtr) ||
	    ((context._cbContext != 0) && !pbContextNdrPtr))
	{
		CWLOG_DBG(TAG,
		          "REDIR_SCARDCONTEXT cbContext (%" PRIu32 ") pbContextNdrPtr (%" PRIu32
		          ") inconsistency",
		          context._cbContext, pbContextNdrPtr);
  
		return STATUS_INVALID_PARAMETER;
	}

	if (context._cbContext > stream.remainingLength())
	{
		CWLOG_DBG(TAG, "REDIR_SCARDCONTEXT is too long: Actual: %" PRIuz ", Expected: %" PRIu32 "",
		          stream.remainingLength(), context._cbContext);
  
		return STATUS_INVALID_PARAMETER;
	}
  
	return SCARD_S_SUCCESS;
}

int32_t smartcardIOControl_Call::unpackRedirScardHandle(RdpStreamBuffer& stream, REDIR_SCARDHANDLE& handle, uint32_t& index)
{
	quint32 pbHandleNdrPtr;

	if (!stream.verifyRemainingLength(4))
	{
		CWLOG_WRN(TAG, "SCARDHANDLE is too short: %" PRIuz "", stream.remainingLength());          
		return STATUS_BUFFER_TOO_SMALL;
	}

	stream >> handle._cbHandle; /* Length (4 bytes) */

	if ((stream.remainingLength() < handle._cbHandle) || (!handle._cbHandle)){
		CWLOG_WRN(TAG, "SCARDHANDLE is too short: Actual: %" PRIuz ", Expected: %" PRIu32 "",
		          stream.remainingLength(), handle._cbHandle);
		return STATUS_BUFFER_TOO_SMALL;
	}

	if(!ndrPointerRead(stream, index, &pbHandleNdrPtr)){ 
		return ERROR_INVALID_DATA;
    }
	return SCARD_S_SUCCESS;
}

bool smartcardIOControl_Call::ndrPointerRead(RdpStreamBuffer& stream, uint32_t& index, quint32* ptr){
 
	const uint32_t expect = 0x20000 + index * 4;
	quint32 ndrPtr;

	if (!stream.verifyRemainingLength(4)) {
		return false;
    }

	stream >> ndrPtr; /* 4 bytes */
	if (ptr)
		*ptr = ndrPtr;
	if (expect != ndrPtr)
	{
		/* Allow NULL pointer if we read the result */
		if (ptr && (ndrPtr == 0)){            
			return true;
        }
		CWLOG_DBG(TAG, "Read context pointer 0x%08" PRIx32 ", expected 0x%08" PRIx32, ndrPtr, expect);
		return false;
	}

	++index;

	return true;
}

bool smartcardIOControl_Call::ndrPointerWrite(uint32_t& index, uint32_t length, quint32& ndrPtr)
{
	ndrPtr = 0x20000 + index * 4;

	if (length > 0)
	{
		_inputBuffer << ndrPtr; /* mszGroupsNdrPtr (4 bytes) */
		++index;
	}
	else {
		quint32 zeroNDR = 0;
		_inputBuffer << zeroNDR;
	}
	return true;
}

uint32_t smartcardIOControl_Call::ndrWrite(const QString& data, quint32 size, uint32_t elementSize, ndr_ptr_t type, bool unicode){
	const quint32 offset = 0;
	const quint32 len = size;
	const quint32 dataLen = size * elementSize;

	if (size == 0){
		return SCARD_S_SUCCESS;
    }

	switch (type)
	{
		case NDR_PTR_FULL:			
			_inputBuffer << len;
			_inputBuffer << offset;
			_inputBuffer << len;
			break;
		case NDR_PTR_SIMPLE:
			_inputBuffer << len;
			break;
		case NDR_PTR_FIXED:
			break;
	}

	if (data.data()) {
		if(unicode){
			QByteArray tmp((const char*) (data.utf16()), data.size() * 2);
			_inputBuffer.append(tmp);			
		} else {
			_inputBuffer.append(data);
		}
	}
	else {		
		_inputBuffer.append(dataLen, '0');
	}
		
	return SCARD_S_SUCCESS;
}

//========================================================================================================
//========================================================================================================

ScardAccessStartedEvent_Call::ScardAccessStartedEvent_Call() {
	_ioControlCode = SCARD_IOCTL_ACCESSSTARTEDEVENT;
	_outputBufferLength = 2048;
	_inputBuffer.append(QByteArray::fromHex("00000000")); // в обратном порядке
//	_inputBuffer.append(QByteArray::fromHex("40F0AABF")); // в обратном порядке
}

//==================================== EstablishContext_Call =============================================
EstablishContext_Call::EstablishContext_Call() {
	quint32 objectBufferLength = 0;
	QByteArray padding;
	_ioControlCode = SCARD_IOCTL_ESTABLISHCONTEXT;
	_dwScope = SCARD_SCOPE_SYSTEM; /* комментарий из freeRDP: SCARD_SCOPE_SYSTEM is the only scope supported by pcsc-lite */

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	objectBufferLength = sizeof(_dwScope) +	getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH + SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH + sizeof(_dwScope));

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);

	_inputBuffer << _dwScope; 	
	_inputBuffer.append(padding); 	
	CWLOG_DBG(TAG, "_outputBufferLength: %d objectBufferLength: %ud", _outputBufferLength, objectBufferLength);
}


void EstablishContext_Call::setResponse(QByteArray& buf){
	uint32_t index = 0;
	quint32 objectBufferLength;
	
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		return;
	}

quint32 offset = 0; // пока не понятно как парсить 4 байта перед контекстом. Значение всегда 0x08000000 - похоже на размер контекста
	rsb >> _response._returnCode;
	// rsb >> offset;
	// rsb >> _response._hContext._cbContext;
	auto rv = unpackRedirScardContext(rsb, _response._hContext, index);
	if(rv != _response._returnCode){
		_response._returnCode = rv;
	}
	rsb >> offset;

	auto startContext = rsb.pointer();
	auto endContext = objectBufferLength - sizeof(_response._returnCode) - sizeof(_response._hContext._cbContext) - sizeof(offset);
	_response._hContext._pbContext = QByteArray(startContext, endContext); 
	// _response._hContext._pbContextReverse = _response._hContext._pbContext;
	// std::reverse(_response._hContext._pbContextReverse.begin(), _response._hContext._pbContextReverse.end());
}

//==================================== ListReaders_Call =============================================
// MS-RDPESC 2.2.2.4
ListReaders_Call::ListReaders_Call(quint64 hContext, quint32 ioControlCode) {
	uint32_t 	index = 0;
	uint32_t	offset = 8; // TODO: пока не понятно, но не хватает этих байт
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	pbContextNdrPtr = 0x00020000;
	quint32 	mszGroupsNdrPtr = 0;
	QByteArray 	mszGroupsPadding;
	_mszGroups = "SCard$AllReaders";
	_mszGroups = _mszGroups.leftJustified(_mszGroups.size() + 2, '\0');

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;

	_hContext._cbContext = sizeof(hContext); // 8 байт
	_hContext._pbContext << hContext;
	_cBytes = _mszGroups.length();

	if(_ioControlCode == SCARD_IOCTL_LISTREADERSW){	
		_cBytes = _cBytes * 2;	
	}
	
	_fmszReadersIsNULL = 0;
	_ccReaders = SCARD_AUTOALLOCATE;	

	objectBufferLength = sizeof(pbContextNdrPtr) /* 4 байт - размер pbContextNdrPtr (см. метод packRedirScardContext) */ + sizeof(_cBytes) + sizeof(mszGroupsNdrPtr) + sizeof(_fmszReadersIsNULL) 
								+ sizeof(_ccReaders) + sizeof(_hContext._cbContext) + _hContext._pbContext.size() + _cBytes /* размер _mszGroups */
								+ offset // TODO: пока не понятно, но не хватает этих байт
								;
	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength);

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	packRedirScardContext(_hContext, index, pbContextNdrPtr);
	
	_inputBuffer << _cBytes;
	ndrPointerWrite(index, 4, mszGroupsNdrPtr); // 4 - любое значение больше 0
	_inputBuffer << _fmszReadersIsNULL;
	_inputBuffer << _ccReaders;
	_inputBuffer << _hContext._cbContext;
	_inputBuffer << hContext; 
	if (mszGroupsNdrPtr){
		if(_ioControlCode == SCARD_IOCTL_LISTREADERSW){
			ndrWrite(_mszGroups, _cBytes, 1, NDR_PTR_SIMPLE, true);
		} else {
			ndrWrite(_mszGroups, _cBytes, 1, NDR_PTR_SIMPLE, false);
		}
	}
	_inputBuffer.append(padding); 	
	CWLOG_DBG(TAG, "_outputBufferLength: %d objectBufferLength: %ud", _outputBufferLength, objectBufferLength);
}

void ListReaders_Call::setResponse(QByteArray& buf){
	quint32 objectBufferLength;
	quint64 offset = 0; 
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		return;
	}

	rsb >> _response._returnCode;
	rsb >> offset;
	rsb >> _response._cBytes;
	
	if(_ioControlCode == SCARD_IOCTL_LISTREADERSW){
		QString unicodeStr;
		bool res = rsb.readUnicodeString(unicodeStr,_response._cBytes);  

		_response._msz = unicodeStr.toLatin1();
		_response._cBytes = _response._cBytes / 2;
	}
	else {
		auto start_msz = rsb.pointer();
		auto end_msz = objectBufferLength - sizeof(_response._returnCode) - sizeof(_response._cBytes) - sizeof(offset);
		_response._msz = QByteArray(start_msz, end_msz);
	}
	
}

//==================================== Connect_Call =============================================
Connect_Call::Connect_Call(quint64 hContext, const std::string& szReader, int64_t dwShareMode, int64_t dwPreferredProtocols, quint32 ioControlCode) {
	uint32_t 	index = 0;
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	ndrPtr = 0;
	quint32 	pbContextNdrPtr = 0x00020000;
	uint32_t 	status = SCARD_S_SUCCESS;
	quint32 	szReaderSize = 0; 
	uint32_t	offset = 16; // TODO: пока не понятно, но не хватает этих байт

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;

	_hContext._cbContext = sizeof(hContext); // 8 байт
	_hContext._pbContext << hContext;

	_szReader = szReader.c_str();
	szReaderSize = _szReader.size();
	_dwShareMode = dwShareMode;
	_dwPreferredProtocols = dwPreferredProtocols;

	if(_ioControlCode == SCARD_IOCTL_CONNECTW){	
		szReaderSize = szReaderSize * 2;	
	}

	objectBufferLength = sizeof(pbContextNdrPtr) /* 4 байт - размер pbContextNdrPtr (см. метод packRedirScardContext) */ + sizeof(ndrPtr) + sizeof(_dwShareMode) 
								+ sizeof(_dwPreferredProtocols) + sizeof(_hContext._cbContext) + _hContext._pbContext.size() + szReaderSize 
								+ offset // TODO: пока не понятно, но не хватает этих байт
								;
	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength);

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	if(!ndrPointerWrite(index, 4, ndrPtr)) {
		CWLOG_WRN(TAG, "packRedirScardContext fail. Error: 0x%08" PRIX32 "", status);
	}

	status = packRedirScardContext(_hContext, index, pbContextNdrPtr);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardContext fail");
	}
	_inputBuffer << _dwShareMode;
	_inputBuffer << _dwPreferredProtocols;
	
	if (ndrPtr){
		if(_ioControlCode == SCARD_IOCTL_CONNECTW){			
			ndrWrite(_szReader, _szReader.size() + 1, 1, NDR_PTR_FULL, true); 
		} else {

			ndrWrite(_szReader, _szReader.size() + 1, 1, NDR_PTR_FULL, false);
		}
	}

	_inputBuffer.append(padding); 	

	_inputBuffer << _hContext._cbContext;
	_inputBuffer << hContext; 

	CWLOG_DBG(TAG, "_outputBufferLength: %d objectBufferLength: %ud", _outputBufferLength, objectBufferLength);
}

void Connect_Call::setResponse(QByteArray& buf){
	uint32_t 	index = 0;
	quint32 objectBufferLength;
	quint32 offset4 = 0;
	quint64 offset8 = 0;
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		return;
	}

	rsb >> _response._returnCode;
	auto rv = unpackRedirScardContext(rsb, _response._hCard._Context, index);
	if(rv != _response._returnCode){
		_response._returnCode = rv;
	}

	rv = unpackRedirScardHandle(rsb, _response._hCard, index);
	if(rv != _response._returnCode){
		_response._returnCode = rv;
	}

	rsb >> _response._dwActiveProtocol;

	rsb >> offset4; // размер _cbContext (это значение не используется)
	// получим hContext
	auto startContext = rsb.pointer();
	auto endContext = objectBufferLength - sizeof(_response._returnCode) - sizeof(_response._hCard._Context._cbContext) - 4 /* pbContextNdrPtr */ 
					  - sizeof(_response._hCard._cbHandle) - 4 /* pbHandleNdrPtr */ - sizeof(_response._dwActiveProtocol);
	_response._hCard._Context._pbContext = QByteArray(startContext, endContext); 

	rsb >> offset8; // сдвинули на 8 байт - размер Context (прочитали значение выше)
	rsb >> offset4; // размер _cbHandle (это значение не используется)
	// получим _pbHandle
	startContext = rsb.pointer();
	endContext -= _response._hCard._Context._cbContext;
	_response._hCard._pbHandle = QByteArray(startContext, endContext); 

}




//==================================== GetStatusChange_Call =============================================
GetStatusChange_Call::GetStatusChange_Call(quint64 hContext, const DWORD_RPC dwTimeout, const std::vector<scard_readerstate_rpc> & rgReaderStates, quint32 cReaders, quint32 ioControlCode){
	quint32 objectBufferLength = 0;
	QByteArray padding;
	quint64 offset = 562949953421320; // в дампе памяти между returnCode и размерностью контекста (_response._hContext._cbContext) какие-то 8 байт. 
						// Пока не понял, что это за данные. В док-ции написано cbContext от 0 до 16 байт. См. MS-RDPESC 2.2.1.1.
						// 562949953421320 = 0x08 00 00 00 00 00 02 00 - в обратном порядке
						// В freeRDP это значение заполняется в функции ......
	QByteArray unknownVar; 
	unknownVar.append(QByteArray::fromHex("04000200")); // Захардкодил - тоже пока не понятно, что это за значение
	
	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;
	_dwTimeOut = dwTimeout;
	_cReaders = cReaders;
	_hContext._cbContext = 8;
	QByteArray tmpBufferForSend; 

	for(int i = 0; i < cReaders; i++){
		
		ReaderState state;
		state._szReader = QByteArray(rgReaderStates[i].szReader.c_str());
      	state._dwCurrentState = rgReaderStates[i].dwCurrentState;
      	state._dwEventState = rgReaderStates[i].dwEventState;
      	state._cbAtr = rgReaderStates[i].rgbAtr.length();
		state._rgbAtr.append(rgReaderStates[i].rgbAtr.c_str());

		tmpBufferForSend.append(state._szReader);
		objectBufferLength += state._szReader.size();

      	tmpBufferForSend << state._dwCurrentState;
		objectBufferLength += sizeof(state._dwCurrentState);

		tmpBufferForSend << state._dwEventState;
		objectBufferLength += sizeof(state._dwEventState);

		tmpBufferForSend << state._cbAtr;
		objectBufferLength += sizeof(state._cbAtr);

		tmpBufferForSend.append(state._rgbAtr);
		objectBufferLength += sizeof(state._rgbAtr.size());
		
		_rgReaderStates.push_back(state);
	}

	if(_ioControlCode == SCARD_IOCTL_GETSTATUSCHANGEW){		
		
		// tmpMszGroups.append(QByteArray::fromHex("04000200")); // Захардкодил - тоже пока не понятно, что это за значение
		// _mszGroups.append(QByteArray::fromHex("2400000053004300610072006400240041006c006c0052006500610064006500720073000000000000000000")); // Захардкодил текст 'SCard$AllReaders'
	}
	else {
		CWLOG_DBG(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		CWLOG_DBG(TAG, "!!!!!!! NEED REALISE SCARD_IOCTL_GETSTATUSCHANGEA !!!!!!!");
		CWLOG_DBG(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	
	objectBufferLength = objectBufferLength + sizeof(offset) + sizeof(_dwTimeOut) + sizeof(_cReaders) + unknownVar.size() + sizeof(_hContext._cbContext) + sizeof(hContext)						
								+ getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
								+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
								+ objectBufferLength + sizeof(offset) + sizeof(_dwTimeOut) + sizeof(_cReaders) + unknownVar.size() + sizeof(_hContext._cbContext) + sizeof(hContext));

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);

	_inputBuffer << offset;	
	_inputBuffer << _dwTimeOut;
	_inputBuffer << _cReaders;
	_inputBuffer.append(unknownVar);
	_inputBuffer << _hContext._cbContext;
	_inputBuffer << hContext;
	_inputBuffer.append(padding); 		
	_inputBuffer.append(tmpBufferForSend);
	
	
	CWLOG_DBG(TAG, "_outputBufferLength: %d objectBufferLength: %ud", _outputBufferLength, objectBufferLength);
}

void GetStatusChange_Call::setResponse(QByteArray& buf){

}