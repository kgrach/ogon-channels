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

qint32 smartcardIOControl_Call::unpackCommonTypeHeader(int size, QDataStream& buf){
	quint8 version; 			/* Version (1 byte), should be 1 */
	quint8 endianness;			/* Endianness (1 byte) 0x10 - Little-endian; 0x00 - Big-endian. Remmina использует только Little-endian*/
	quint16 commonHeaderLength; /* CommonHeaderLength (2 bytes), should be 8 */
	quint32 filler; 			/* Filler (4 bytes), should be 0xCCCCCCCC */

	if (size < SMARTCARD_COMMON_TYPE_HEADER_LENGTH) {
		CWLOG_WRN(TAG, "CommonTypeHeader is too short: %" PRIuz "", size);
		return STATUS_BUFFER_TOO_SMALL;
	}
	// QDataStream ds(buf);
	// ds.setByteOrder(QDataStream::LittleEndian);

	// ds >> version;
	// ds >> endianness;
	// ds >> commonHeaderLength;
	// ds >> filler;

	buf >> version;
	buf >> endianness;
	buf >> commonHeaderLength;
	buf >> filler;

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

qint32 smartcardIOControl_Call::unpackPrivateTypeHeader(int size, QDataStream& buf){

	if (size < (SMARTCARD_COMMON_TYPE_HEADER_LENGTH + SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH)) {
		CWLOG_WRN(TAG, "PrivateTypeHeader is too short: %" PRIuz "", size);
		return STATUS_BUFFER_TOO_SMALL;
	}

	quint32 objectBufferLength;  	/* objectBufferLength (4 bytes) including padding length)*/
	quint32 filler;			 		/* Filler (4 bytes), should be 0x00000000 */

	buf >> objectBufferLength;
	buf >> filler;

	if (filler != 0x00000000)
	{
		CWLOG_WRN(TAG, "Unexpected PrivateTypeHeader Filler 0x%08" PRIX32 "", filler);
		return STATUS_INVALID_PARAMETER;
	}

	auto remaining = size + SMARTCARD_COMMON_TYPE_HEADER_LENGTH - buf.device()->pos();
	if (objectBufferLength != remaining)
	{
		CWLOG_WRN(TAG,
		          "PrivateTypeHeader ObjectBufferLength mismatch: Actual: %" PRIu32 ", Expected: %" PRIuz "",
		          objectBufferLength, remaining);
		return STATUS_INVALID_PARAMETER;
	}
	
	return SCARD_S_SUCCESS;
}


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

//========================================================================================================
//========================================================================================================

ScardAccessStartedEvent_Call::ScardAccessStartedEvent_Call() {
	_ioControlCode = SCARD_IOCTL_ACCESSSTARTEDEVENT;
	_outputBufferLength = 2048;
	_inputBuffer.append(QByteArray::fromHex("00000000")); // в обратном порядке
//	_inputBuffer.append(QByteArray::fromHex("40F0AABF")); // в обратном порядке
}

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
	quint32 objectBufferLength;
	quint64 offset = 0; // в дампе памяти между returnCode размерностью контекста (_response._hContext._cbContext) какие-то 8 байт. 
						// Пока не понял, что это за данные. В док-ции написано cbContext от 0 до 16 байт. См. MS-RDPESC 2.2.1.1. 
						// В freeRDP это значение заполняется в функции smartcard_pack_redir_scard_context
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
	rsb >> _response._hContext._cbContext;
	

	auto startContext = rsb.pointer();
	auto endContext = objectBufferLength - sizeof(_response._returnCode) - sizeof(_response._hContext._cbContext) - sizeof(offset);
	_response._hContext._pbContext = QByteArray(startContext, endContext); 
	// _response._hContext._pbContextReverse = _response._hContext._pbContext;
	// std::reverse(_response._hContext._pbContextReverse.begin(), _response._hContext._pbContextReverse.end());
}

// MS-RDPESC 2.2.2.4
ListReaders_Call::ListReaders_Call(quint64 hContext, quint32 ioControlCode) {
	quint32 objectBufferLength = 0;
	QByteArray padding;
	quint64 offset = 562949953421320; // в дампе памяти между returnCode размерностью контекста (_response._hContext._cbContext) какие-то 8 байт. 
						// Пока не понял, что это за данные. В док-ции написано cbContext от 0 до 16 байт. См. MS-RDPESC 2.2.1.1.
						// 562949953421320 = 0x08 00 00 00 00 00 02 00 - в обратном порядке
						// В freeRDP это значение заполняется в функции smartcard_pack_redir_scard_context
	QByteArray tmpMszGroups; // 

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;

	if(_ioControlCode == SCARD_IOCTL_LISTREADERSW){
		_hContext._cbContext = 8;
		_cBytes = 36; // Захардкодил
		tmpMszGroups.append(QByteArray::fromHex("04000200")); // Захардкодил - тоже пока не понятно, что это за значение
		_mszGroups.append(QByteArray::fromHex("2400000053004300610072006400240041006c006c0052006500610064006500720073000000000000000000")); // Захардкодил текст 'SCard$AllReaders'
	}
	else {
		CWLOG_DBG(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
		CWLOG_DBG(TAG, "!!!!!!! NEED REALISE SCARD_IOCTL_LISTREADERSA !!!!!!!");
		CWLOG_DBG(TAG, "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
	}
	_fmszReadersIsNULL = 0;
	_ccReaders = SCARD_AUTOALLOCATE;	

	objectBufferLength = sizeof(offset) + sizeof(_cBytes) + tmpMszGroups.size() + sizeof(_fmszReadersIsNULL) 
								+ sizeof(_ccReaders) + sizeof(_hContext._cbContext) + sizeof(hContext) + _mszGroups.size()
								+ getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
								+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
								+ sizeof(offset) + sizeof(_cBytes) + tmpMszGroups.size() + sizeof(_fmszReadersIsNULL) 
								+ sizeof(_ccReaders) + sizeof(_hContext._cbContext) + sizeof(hContext) + _mszGroups.size());

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);

	_inputBuffer << offset;	
	_inputBuffer << _cBytes;
	_inputBuffer.append(tmpMszGroups);
	_inputBuffer << _fmszReadersIsNULL;
	_inputBuffer << _ccReaders;
	_inputBuffer << _hContext._cbContext;
	_inputBuffer << hContext; 
	_inputBuffer.append(padding); 	
	_inputBuffer.append(_mszGroups);
	CWLOG_DBG(TAG, "_outputBufferLength: %d objectBufferLength: %ud", _outputBufferLength, objectBufferLength);
}

void ListReaders_Call::setResponse(QByteArray& buf){
	quint32 objectBufferLength;
	quint64 offset = 0; // в дампе памяти между опять какие-то 8 байт между returnCode и cBytes. 
						// Пока не понял, что это за данные. 
						// В freeRDP это значение заполняется в функции smartcard_ndr_pointer_write для listReaders
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