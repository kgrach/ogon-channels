#include "smartcard_operations.h"
#include "QByteArrayWriteInteger.h"
#include <ogon-channels/logging.h>
#include <QDebug>

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

quint32 smartcardIOControl_Call::unpackReadSizeAlign(RdpStreamBuffer& stream, size_t size, quint32 alignment)
{
 
	quint32 pad;
	
	pad = size;
	size = (size + alignment - 1) & ~(alignment - 1);
	pad = size - pad;

	if (pad){
		stream >> pad;
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

uint32_t smartcardIOControl_Call::packRedirScardContext(QByteArray& buf, const REDIR_SCARDCONTEXT& context, uint32_t& index, quint32& pbContextNdrPtr, quint32& offset){
 
	//const quint32 
	pbContextNdrPtr = 0x00020000 + index * 4;

	if (context._cbContext != 0)
	{
		buf << context._cbContext;			/* cbContext (4 bytes) */
		offset += sizeof(context._cbContext);
		
		buf << pbContextNdrPtr;			/* pbContextNdrPtr (4 bytes) */
		offset += sizeof(pbContextNdrPtr);

		++index;		
	}
	else {
		quint64 zeroNDR = 0;
		buf << zeroNDR;
		pbContextNdrPtr = 0;
		offset += sizeof(zeroNDR);
	}
	
	return SCARD_S_SUCCESS;
}

uint32_t smartcardIOControl_Call::packRedirScardHandle(QByteArray& buf, const REDIR_SCARDHANDLE& handle, uint32_t& index, quint32& pbContextNdrPtr, quint32& offset)
{
	pbContextNdrPtr = 0x00020000 + index * 4;

	if (handle._cbHandle != 0)
	{
		buf << handle._cbHandle;			/* cbHandle (4 bytes) */
		offset += sizeof(handle._cbHandle);
		
		buf << pbContextNdrPtr;				/* pbContextNdrPtr (4 bytes) */
		offset += sizeof(pbContextNdrPtr);

		++index;		
	}
	else {
		quint64 zeroNDR = 0;
		buf << zeroNDR;
		pbContextNdrPtr = 0;
		offset += sizeof(zeroNDR);
	}
	
	return SCARD_S_SUCCESS;
}

int32_t smartcardIOControl_Call::packReaderState(QByteArray& buf, std::vector<ReaderState>& ppcReaders, quint32 cReaders, uint32_t& ptrIndex, quint32& offset, bool unicode)
{
	uint32_t index, len;
	int32_t status = SCARD_E_NO_MEMORY;

	buf << cReaders;
	offset += sizeof(cReaders);
	
	status = ERROR_INVALID_DATA;
	for (index = 0; index < cReaders; index++)
	{
		quint32 ptr = UINT32_MAX;

		ndrPointerWrite(buf, ptrIndex, 4, ptr, offset); // 4 - любое значение больше 0

		buf << ppcReaders[index]._dwCurrentState; /* dwCurrentState (4 bytes) */
		offset += sizeof(ppcReaders[index]._dwCurrentState);

		buf << ppcReaders[index]._dwEventState;   /* dwEventState (4 bytes) */
		offset += sizeof(ppcReaders[index]._dwEventState);

		buf << ppcReaders[index]._cbAtr;          /* cbAtr (4 bytes) */
		offset += sizeof(ppcReaders[index]._cbAtr);

		buf.append(ppcReaders[index]._rgbAtr);     /* rgbAtr [0..36] (36 bytes) */
		offset += ppcReaders[index]._rgbAtr.size();
	}

	for (index = 0; index < cReaders; index++)
	{
		if(unicode){
			status = ndrWrite(buf, ppcReaders[index]._szReader, ppcReaders[index]._szReader.size(), sizeof(WCHAR), NDR_PTR_FULL, offset, unicode);		
		} else {
			status = ndrWrite(buf, ppcReaders[index]._szReader, ppcReaders[index]._szReader.size(), sizeof(CHAR), NDR_PTR_FULL, offset, unicode);		
		}
	}

	return status;
}

void smartcardIOControl_Call::packHcardAndDispositionCall(QByteArray& buf, const HCardAndDisposition_Call& call, quint32& offset){
	uint32_t 	index = 0;
	quint32 	pbContextNdrPtr;
	quint32 	pbHcardNdrPtr;

	packRedirScardContext(buf, call._hCard._Context, index, pbContextNdrPtr, offset);
	packRedirScardHandle(buf, call._hCard, index, pbHcardNdrPtr, offset);

	buf << call._dwDisposition;
	offset += sizeof(call._dwDisposition);

	buf << call._hCard._Context._cbContext;
	buf.append(call._hCard._Context._pbContext); 
	offset += sizeof(call._hCard._Context._cbContext) + call._hCard._Context._pbContext.size();

	buf << call._hCard._cbHandle;
	buf.append(call._hCard._pbHandle); 
	offset += sizeof(call._hCard._cbHandle) + call._hCard._pbHandle.size();
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

	if (!ndrPointerRead(stream, index, pbContextNdrPtr)){
  
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

	if(!ndrPointerRead(stream, index, pbHandleNdrPtr)){ 
		return ERROR_INVALID_DATA;
    }
	return SCARD_S_SUCCESS;
}

int32_t smartcardIOControl_Call::unpackGetStatusChangeReturn(RdpStreamBuffer& stream, GetStatusChange_Return& ret, bool unicode) {

	int32_t status;
	quint32 cReaders = 0;
	uint32_t index = 0;
	quint32 ndrPtr = 0;
	quint32 len = 0;


	stream >> ret._returnCode;

	stream >> ret._cReaders;

	ndrPointerRead(stream, index, ndrPtr);

	stream >> len;

	auto expectedLength = len * (sizeof(ReaderState_Return::_dwCurrentState) 
											+ sizeof(ReaderState_Return::_dwEventState)
											+ sizeof(ReaderState_Return::_cbAtr)
											+ RGB_ATR_LEN); // размер _rgbAtr = 36 байт
	if (stream.remainingLength() < expectedLength){
		CWLOG_WRN(TAG, "SCARDHANDLE is too short: Actual: %" PRIuz ", Expected: %" PRIu32 "",
		          stream.remainingLength(), expectedLength);
		ret._returnCode = STATUS_BUFFER_TOO_SMALL;
		return ret._returnCode;
	}

	for(size_t i = 0; i < ret._cReaders; ++i){
		ReaderState_Return state;
		stream >> state._dwCurrentState;
		stream >> state._dwEventState;
		stream >> state._cbAtr;
		state._rgbAtr = QByteArray(stream.pointer(), RGB_ATR_LEN);
		ret._rgReaderStates.push_back(state);
		stream.seek(RGB_ATR_LEN); // размер _rgbAtr = 36 байт. Сдвинули на 36 байт
	}

	return ret._returnCode;
}

bool smartcardIOControl_Call::ndrPointerRead(RdpStreamBuffer& stream, uint32_t& index, quint32& ptr){
 
	const uint32_t expect = 0x20000 + index * 4;
	quint32 ndrPtr;

	if (!stream.verifyRemainingLength(4)) {
		return false;
    }

	stream >> ndrPtr; /* 4 bytes */
	ptr = ndrPtr;

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

bool smartcardIOControl_Call::ndrPointerWrite(QByteArray& buf, uint32_t& index, uint32_t length, quint32& ndrPtr, quint32& offset)
{
	ndrPtr = 0x20000 + index * 4;

	if (length > 0)
	{
		buf << ndrPtr; /* NdrPtr (4 bytes) */
		++index;
		offset += sizeof(ndrPtr);
	}
	else {
		quint32 zeroNDR = 0;
		buf << zeroNDR;
		ndrPtr = 0;
		offset += sizeof(zeroNDR);
	}
	return true;
}

uint32_t smartcardIOControl_Call::ndrWrite(QByteArray& buf, const QByteArray& data, quint32 size, uint32_t elementSize, ndr_ptr_t type, quint32& offset, bool unicode){
	
	quint32 len = size;
	quint32 dataLen = size * elementSize;
	quint32 offsetNdr = 0;
	QByteArray bufPadding;
// qInfo() << "########### data = " << hex << data;
	if (size == 0){
		return SCARD_S_SUCCESS;
    }

	switch (type)
	{
		case NDR_PTR_FULL:			
			buf << len;
			buf << offsetNdr;
			buf << len;
			offset += sizeof(len) + sizeof(offsetNdr) + sizeof(len);
			break;
		case NDR_PTR_SIMPLE:
			buf << len;
			offset += sizeof(len);
			break;
		case NDR_PTR_FIXED:
			break;
	}
// qInfo() << "########### buf = " << hex << buf;	
	if (data.data()) {
		if(unicode){
			// QByteArray tmp((const char*) (data.utf16()), dataLen); // when data is QString
			
			QByteArray tmp = QByteArray((const char*)QString(data).utf16(), dataLen);
			buf.append(tmp);			
		} else {
			//buf.append(data.toStdString().c_str(), dataLen); // when data is QString
			buf.append(data);
		}
	}
	else {		
		buf.append(dataLen, '0'); // заполним нулями
	}
// qInfo() << "########### buf = " << hex << buf;	
	offset +=  dataLen;

	quint32 paddingSize = getPadding(bufPadding, dataLen, 4);
	if(paddingSize){
		buf.append(bufPadding);
		offset += paddingSize;
	}

	return SCARD_S_SUCCESS;
}

uint32_t smartcardIOControl_Call::ndrRead(RdpStreamBuffer& stream, QByteArray& data, size_t min, size_t elementSize, ndr_ptr_t type)
{
	quint32 len, offset, len2;
	size_t required;

	switch (type)
	{
		case NDR_PTR_FULL:
			required = 12;
			break;
		case NDR_PTR_SIMPLE:
			required = 4;
			break;
		case NDR_PTR_FIXED:
			required = min;
			break;
	}

	if (stream.remainingLength() < required)
	{
		CWLOG_ERR(TAG, "Short data while trying to read NDR, expected %d, got %" PRIu64, required, stream.remainingLength());
        
		return STATUS_BUFFER_TOO_SMALL;
	}

	switch (type)
	{
		case NDR_PTR_FULL:
			stream >> len;
			stream >> offset;
			stream >> len2;
			
			if (len != offset + len2)
			{
				CWLOG_ERR(TAG,
				         "Invalid data when reading full NDR pointer: total=%" PRIu32
				         ", offset=%" PRIu32 ", remaining=%" PRIu32,
				         len, offset, len2);
                
				return STATUS_BUFFER_TOO_SMALL;
			}
			break;
		case NDR_PTR_SIMPLE:
			stream >> len;

			if ((len != min) && (min > 0))
			{
				CWLOG_ERR(TAG,
				         "Invalid data when reading simple NDR pointer: total=%" PRIu32
				         ", expected=%" PRIu32,
				         len, min);
                
				return STATUS_BUFFER_TOO_SMALL;
			}
			break;
		case NDR_PTR_FIXED:
			len = (quint32)min;
			break;
	}

	if (min > len)
	{
		CWLOG_ERR(TAG, "Invalid length read from NDR pointer, minimum %" PRIu32 ", got %" PRIu32,
		         min, len);

		return STATUS_DATA_ERROR;
	}

	if (len > SIZE_MAX / 2){
		return STATUS_BUFFER_TOO_SMALL;
    }

	if (stream.remainingLength() / elementSize < len)
	{
		CWLOG_ERR(TAG,
		         "Short data while trying to read data from NDR pointer, expected %" PRIu32
		         ", got %" PRIu32,
		         len, stream.remainingLength());
        
		return STATUS_BUFFER_TOO_SMALL;
	}
	len *= elementSize;

	data = QByteArray(stream.pointer(), len); 
	stream.seek(len);

	unpackReadSizeAlign(stream, len, 4);

	return STATUS_SUCCESS;
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
	quint32 	ndrPtr = 0;
	
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}

	rsb >> _response._returnCode;
	auto rv = unpackRedirScardContext(rsb, _response._hContext, index);
	if(rv != _response._returnCode){
		_response._returnCode = rv;
	}
	
	ndrPointerRead(rsb, index, ndrPtr);

	auto startContext = rsb.pointer();
	auto endContext = objectBufferLength - sizeof(_response._returnCode) - sizeof(_response._hContext._cbContext) - sizeof(ndrPtr);
	_response._hContext._pbContext = QByteArray(startContext, endContext); 
}

//==================================== ListReaders_Call =============================================
// MS-RDPESC 2.2.2.4
ListReaders_Call::ListReaders_Call(quint64 hContext, const std::string& readerName, quint32 ioControlCode) {
	uint32_t 	index = 0;
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	pbContextNdrPtr = 0x00020000;
	quint32 	mszGroupsNdrPtr = 0;
	QByteArray 	tmpInputBuffer;
	_mszGroups = QByteArray(readerName.c_str(), readerName.size() + 2); // почему +2 пока не понятно, должно быть +1, но иначе не хватает этого байта 
	// _mszGroups = readerName.c_str();
	// _mszGroups = _mszGroups.leftJustified(_mszGroups.size() + 2, '\0');

// QByteArray tmp((const char*) (_mszGroups.utf16()), _mszGroups.size() + 2);
// qInfo() << "########### _mszGroups = " << hex << _mszGroups << " byteArray = " << tmp;
// QByteArray baFromStdString = QByteArray(readerName.c_str(), readerName.size() + 2);
// qInfo() << "########### baFromStdString = " << hex << baFromStdString;
// auto tmpStr16 = QString(baFromStdString).utf16();
// QByteArray baUtf16 = QByteArray((const char*)tmpStr16, _mszGroups.size() + 2);
// qInfo() << "########### tmpStr16 = " << hex << tmpStr16 << " baUtf16 = " << hex << baUtf16;

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;

	_hContext._cbContext = sizeof(hContext); // 8 байт
	_hContext._pbContext << hContext;
	_cBytes = _mszGroups.size();

	if(_ioControlCode == SCARD_IOCTL_LISTREADERSW){	
		_cBytes = _cBytes * 2;	
	}
	
	_fmszReadersIsNULL = 0;
	_ccReaders = SCARD_AUTOALLOCATE;	

	packRedirScardContext(tmpInputBuffer, _hContext, index, pbContextNdrPtr, objectBufferLength);
	
	tmpInputBuffer << _cBytes;
	objectBufferLength += sizeof(_cBytes);

	ndrPointerWrite(tmpInputBuffer, index, 4, mszGroupsNdrPtr, objectBufferLength); // 4 - любое значение больше 0
	
	tmpInputBuffer << _fmszReadersIsNULL;
	objectBufferLength += sizeof(_fmszReadersIsNULL);

	tmpInputBuffer << _ccReaders;
	objectBufferLength += sizeof(_ccReaders);

	tmpInputBuffer << _hContext._cbContext;
	tmpInputBuffer << hContext; 
	objectBufferLength += sizeof(_hContext._cbContext) + _hContext._pbContext.size();
	
	if (mszGroupsNdrPtr){
		if(_ioControlCode == SCARD_IOCTL_LISTREADERSW){
			ndrWrite(tmpInputBuffer, _mszGroups, _cBytes , 1, NDR_PTR_SIMPLE, objectBufferLength, true);
		} else {
			ndrWrite(tmpInputBuffer, _mszGroups, _cBytes, 1, NDR_PTR_SIMPLE, objectBufferLength, false);
		}
	}

	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength);

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	_inputBuffer.append(tmpInputBuffer);	
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
		_response._returnCode = res;
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
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
	QByteArray 	tmpInputBuffer;

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;

	_hContext._cbContext = sizeof(hContext); // 8 байт
	_hContext._pbContext << hContext;

	_szReader = QByteArray(szReader.c_str(), szReader.size() + 1);
	// _szReader = szReader.c_str();
	// _szReader = _szReader.leftJustified(_szReader.size() + 1, '\0');

	_dwShareMode = dwShareMode;
	_dwPreferredProtocols = dwPreferredProtocols;

	ndrPointerWrite(tmpInputBuffer, index, 4, ndrPtr, objectBufferLength); // 4 - любое значение больше 0
		
	status = packRedirScardContext(tmpInputBuffer, _hContext, index, pbContextNdrPtr, objectBufferLength);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardContext fail");
	}
	tmpInputBuffer << _dwShareMode;
	objectBufferLength += sizeof(_dwShareMode);

	tmpInputBuffer << _dwPreferredProtocols;
	objectBufferLength += sizeof(_dwPreferredProtocols);
	
	if (ndrPtr){
		if(_ioControlCode == SCARD_IOCTL_CONNECTW){			
			ndrWrite(tmpInputBuffer, _szReader, _szReader.size(), sizeof(WCHAR), NDR_PTR_FULL, objectBufferLength, true); 
		} else {
			ndrWrite(tmpInputBuffer, _szReader, _szReader.size(), sizeof(CHAR), NDR_PTR_FULL, objectBufferLength, false);
		}
	}

	tmpInputBuffer << _hContext._cbContext;
	tmpInputBuffer << hContext; 
	objectBufferLength += sizeof(_hContext._cbContext) + _hContext._pbContext.size();

	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength);

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	_inputBuffer.append(tmpInputBuffer);
	_inputBuffer.append(padding); 	

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
		_response._returnCode = res;
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
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
	uint32_t 	index = 0;
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	ndrPtr = 0;
	quint32 	pbContextNdrPtr = 0x00020000;
	uint32_t 	status = SCARD_S_SUCCESS;
	QByteArray 	tmpInputBuffer;

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;

	_dwTimeOut = dwTimeout;
	_cReaders = cReaders;
	_hContext._cbContext = sizeof(hContext); // 8 байт
	_hContext._pbContext << hContext;

	for(int i = 0; i < cReaders; i++){
		
		ReaderState state;
		state._szReader = QByteArray(rgReaderStates[i].szReader.c_str(), rgReaderStates[i].szReader.size() + 1);

      	state._dwCurrentState = rgReaderStates[i].dwCurrentState;
      	state._dwEventState = rgReaderStates[i].dwEventState;
      	state._cbAtr = rgReaderStates[i].rgbAtr.length();
		state._rgbAtr.append(rgReaderStates[i].rgbAtr.c_str());

		_rgReaderStates.push_back(state);
	}

	packRedirScardContext(tmpInputBuffer, _hContext, index, pbContextNdrPtr, objectBufferLength);

	tmpInputBuffer << _dwTimeOut;
	objectBufferLength += sizeof(_dwTimeOut);

	tmpInputBuffer << _cReaders;
	objectBufferLength += sizeof(_cReaders);

	ndrPointerWrite(tmpInputBuffer, index, 4, ndrPtr, objectBufferLength); // 4 - любое значение больше 0

	tmpInputBuffer << _hContext._cbContext;
	tmpInputBuffer << hContext; 
	objectBufferLength += sizeof(_hContext._cbContext) + _hContext._pbContext.size();

	if (ndrPtr){
		if(_ioControlCode == SCARD_IOCTL_GETSTATUSCHANGEW){			
			packReaderState(tmpInputBuffer, _rgReaderStates, _cReaders, index, objectBufferLength, true);
		} else {
			packReaderState(tmpInputBuffer, _rgReaderStates, _cReaders, index, objectBufferLength, false);
		}
	}	

	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength); 

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	_inputBuffer.append(tmpInputBuffer);
	_inputBuffer.append(padding); 
}

void GetStatusChange_Call::setResponse(QByteArray& buf){
	uint32_t 	index = 0;
	quint32 objectBufferLength = 0;
	quint32 ndrPtr = 0;
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}

	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}

	if(_ioControlCode == SCARD_IOCTL_GETSTATUSCHANGEW){
		unpackGetStatusChangeReturn(rsb, _response, true);
	} else {
		unpackGetStatusChangeReturn(rsb, _response, false);
	}	
}

//==================================== Status_Call =============================================
Status_Call::Status_Call(quint64 hCard, quint64 hContext, int64_t cchReaderLen, int64_t cbAtrLen, quint32 ioControlCode){

	uint32_t 	index = 0;
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	pbContextNdrPtr = 0x00020000;
	uint32_t 	status = SCARD_S_SUCCESS;
	QByteArray 	tmpInputBuffer;

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;
	_cchReaderLen = cchReaderLen;
	_cbAtrLen = cbAtrLen;
	_hCard._cbHandle = sizeof(hCard); // 8 байт
	_hCard._pbHandle << hCard;
	_hCard._Context._cbContext = sizeof(hContext); // 8 байт
	_hCard._Context._pbContext << hContext;

	status = packRedirScardContext(tmpInputBuffer, _hCard._Context, index, pbContextNdrPtr, objectBufferLength);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardContext fail");
	}

	status = packRedirScardHandle(tmpInputBuffer, _hCard, index, pbContextNdrPtr, objectBufferLength);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardHandle fail");
	}

	tmpInputBuffer << _fmszReaderNamesIsNULL;
	objectBufferLength += sizeof(_fmszReaderNamesIsNULL);

	tmpInputBuffer << _cchReaderLen;
	objectBufferLength += sizeof(_cchReaderLen);

	tmpInputBuffer << _cbAtrLen;
	objectBufferLength += sizeof(_cbAtrLen);

	tmpInputBuffer << _hCard._Context._cbContext;
	tmpInputBuffer << hContext; 
	objectBufferLength += sizeof(_hCard._Context._cbContext) + _hCard._Context._pbContext.size();

	tmpInputBuffer << _hCard._cbHandle;
	tmpInputBuffer << hCard; 
	objectBufferLength += sizeof(_hCard._cbHandle) + _hCard._pbHandle.size();

	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength); 

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	_inputBuffer.append(tmpInputBuffer);
	_inputBuffer.append(padding); 
}

void Status_Call::setResponse(QByteArray& buf){
	uint32_t 	index = 0;
	quint32 objectBufferLength;
	quint32 ndrPtr = 0;
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}

	rsb >> _response._returnCode;

	rsb >> _response._cBytes;

	ndrPointerRead(rsb, index, ndrPtr);

	rsb >> _response._dwState;

	rsb >> _response._dwProtocol;

	_response._pbAtr = QByteArray(rsb.pointer(), PB_ATR_LEN); 	// прочитали 32 байта
	rsb.seek(PB_ATR_LEN); 										// сдвинули на 32 байта

	rsb >> _response._cbAtrLen;

	ndrRead(rsb, _response._mszReaderNames, _response._cBytes, 1, NDR_PTR_SIMPLE);

	// if(_ioControlCode == SCARD_IOCTL_STATUSW) {
	// 	// ndrRead(rsb, _response._mszReaderNames, _response._cBytes, 1, NDR_PTR_SIMPLE);
	// 	ndrRead(rsb, _response._mszReaderNames, _response._cBytes, sizeof(WCHAR), NDR_PTR_SIMPLE);		
	// }
	// else {
	// 	ndrRead(rsb, _response._mszReaderNames, _response._cBytes, sizeof(CHAR), NDR_PTR_SIMPLE);
	// }
}

//==================================== Transmit_Call =============================================
Transmit_Call::Transmit_Call(quint64 hCard, quint64 hContext, const scard_io_request_rpc&  pioSendPci, const std::string& pbSendBuffer, quint64 pcbRecvLength, quint32 ioControlCode){
	uint32_t 	index = 0;
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	pbContextNdrPtr;
	quint32 	pbExtraBytesNdrPtr = 0;
	quint32 	pbSendBufferNdrPtr = 0;
	quint32 	pioRecvPciNdrPtr = 0;
	uint32_t 	status = SCARD_S_SUCCESS;
	QByteArray 	tmpInputBuffer;

	_outputBufferLength = 2048;			// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;
	_hCard._cbHandle = sizeof(hCard); 	// 8 байт
	_hCard._pbHandle << hCard;
	_hCard._Context._cbContext = sizeof(hContext); // 8 байт
	_hCard._Context._pbContext << hContext;

	_ioSendPci._dwProtocol = pioSendPci.dwProtocol;
	_ioSendPci._cbExtraBytes = 0; //pioSendPci.cbPciLength - sizeof(SCARD_IO_REQUEST); // TODO: разобраться с формированием _cbExtraBytes и для чего нужен параметр pioSendPci.cbPciLength

	_fpbRecvBufferIsNULL = 0;
	_cbRecvLength = SHRT_MAX;
	_cbSendLength = pbSendBuffer.size();
	
	// _pbSendBuffer = QString::fromStdString(pbSendBuffer);
	// _pbSendBuffer = _pbSendBuffer.leftJustified(_cbSendLength, '\0');
	_pbSendBuffer = QByteArray(pbSendBuffer.c_str(), pbSendBuffer.size() /*+ 1*/);

// qInfo() << "########### _pbSendBuffer = " << hex << _pbSendBuffer;	
	
// QByteArray tmpByteArr1;
// tmpByteArr1.append(_pbSendBuffer);
// qInfo() << "########### _pbSendBuffer = " << _pbSendBuffer << " (" << hex  << tmpByteArr1 << ")";	
// QString tmp2 = QString::fromUtf8(pbSendBuffer.c_str(), pbSendBuffer.size());
// QByteArray tmpByteArr2;
// QByteArray tmpByteArr21;
// tmpByteArr2.append(tmp2.toStdString().c_str(), _cbSendLength);
// tmpByteArr21.append(tmp2.toUtf8());
// qInfo() << "########### tmp2 = " << tmp2 << " ("  << tmpByteArr2 << ") " << tmpByteArr21;	
// QString tmp3 = QString::fromLatin1(pbSendBuffer.c_str(), pbSendBuffer.size());
// QByteArray tmpByteArr3;
// QByteArray tmpByteArr31;
// tmpByteArr3.append(tmp3.toStdString().c_str(), _cbSendLength);
// tmpByteArr31.append(tmp3.toUtf8());
// qInfo() << "########### tmp3 = " << tmp3 << " (" << hex << tmpByteArr3 << ") " << tmpByteArr31;


	status = packRedirScardContext(tmpInputBuffer, _hCard._Context, index, pbContextNdrPtr, objectBufferLength);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardContext fail");
	}

	status = packRedirScardHandle(tmpInputBuffer, _hCard, index, pbContextNdrPtr, objectBufferLength);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardHandle fail");
	}

	tmpInputBuffer << _ioSendPci._dwProtocol;
	objectBufferLength += sizeof(_ioSendPci._dwProtocol);

	tmpInputBuffer << _ioSendPci._cbExtraBytes;
	objectBufferLength += sizeof(_ioSendPci._cbExtraBytes);
	ndrPointerWrite(tmpInputBuffer, index, _ioSendPci._cbExtraBytes, pbExtraBytesNdrPtr, objectBufferLength); 	// 0 - т.к. _cbExtraBytes нулевое значение. См. TODO для pbExtraBytesNdrPtr ниже


	tmpInputBuffer << _cbSendLength;
	objectBufferLength += sizeof(_cbSendLength);
	ndrPointerWrite(tmpInputBuffer, index, _cbSendLength, pbSendBufferNdrPtr, objectBufferLength); 	// 1 - любое значение больше 0 для формирования ненулевого Ndr

	ndrPointerWrite(tmpInputBuffer, index, 0, pioRecvPciNdrPtr, objectBufferLength); 	// 0 - см TODO для pioRecvPciNdrPtr ниже
	
	tmpInputBuffer << _fpbRecvBufferIsNULL;
	objectBufferLength += sizeof(_fpbRecvBufferIsNULL);

	tmpInputBuffer << _cbRecvLength;
	objectBufferLength += sizeof(_cbRecvLength);
	
	tmpInputBuffer << _hCard._Context._cbContext;
	tmpInputBuffer << hContext; 
	objectBufferLength += sizeof(_hCard._Context._cbContext) + _hCard._Context._pbContext.size();

	tmpInputBuffer << _hCard._cbHandle;
	tmpInputBuffer << hCard; 
	objectBufferLength += sizeof(_hCard._cbHandle) + _hCard._pbHandle.size();

	if (pbExtraBytesNdrPtr) {
		// TODO: см. код remmina функция smartcard_unpack_transmit_call() файл smartcard_pack.c строка 3805 блок if (pbExtraBytesNdrPtr)...
	}

	if (pbSendBufferNdrPtr) {
		ndrWrite(tmpInputBuffer, _pbSendBuffer, _cbSendLength, 1, NDR_PTR_SIMPLE, objectBufferLength, false);
  	}

	if (pioRecvPciNdrPtr) {
		// TODO: см. код remmina функция smartcard_unpack_transmit_call() файл smartcard_pack.c строка 3869 блок if (pioRecvPciNdrPtr)
	}

	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength); 

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	_inputBuffer.append(tmpInputBuffer);
	_inputBuffer.append(padding); 
}

void Transmit_Call::setResponse(QByteArray& buf){
	uint32_t 	index = 0;
	quint32 objectBufferLength;
	quint32 ndrPtr = 0;
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}

	rsb >> _response._returnCode;

	ndrPointerRead(rsb, index, ndrPtr);

	rsb >> _response._cbRecvLength;

	ndrPointerRead(rsb, index, ndrPtr);

	if(_response._pioRecvPci){
		// TODO: Разобраться по какому признаку можно понять нужно ли зачитывать _pioRecvPci
		//  после этого не забудь поменять присваиваемые значения в thrift.cpp для параметров:
		// 	ioRecvPciRPC.dwProtocol = 0;  // _response._pioRecvPci.dwProtocol;
    	// 	ioRecvPciRPC.cbPciLength = 0; // _response._pioRecvPci.cbPciLength;
	}

	ndrRead(rsb, _response._pbRecvBuffer, _response._cbRecvLength, 1, NDR_PTR_SIMPLE);
}


//==================================== Disconnect_Call =============================================
Disconnect_Call::Disconnect_Call(quint64 hCard, quint64 hContext, int64_t dwDisposition, quint32 ioControlCode ){
	uint32_t 	index = 0;
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	NdrPtr;
	uint32_t 	status = SCARD_S_SUCCESS;
	QByteArray 	tmpInputBuffer;

	_outputBufferLength = 2048;			// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;
	_call._hCard._cbHandle = sizeof(hCard); 	// 8 байт
	_call._hCard._pbHandle << hCard;
	_call._hCard._Context._cbContext = sizeof(hContext); // 8 байт
	_call._hCard._Context._pbContext << hContext;

	_call._dwDisposition = dwDisposition;	

	packHcardAndDispositionCall(tmpInputBuffer, _call, objectBufferLength);

	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength); 

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	_inputBuffer.append(tmpInputBuffer);
	_inputBuffer.append(padding); 
}

void Disconnect_Call::setResponse(QByteArray& buf){
	uint32_t 	index = 0;
	quint32 objectBufferLength;
	quint32 ndrPtr = 0;
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}

	rsb >> _response._returnCode;
}

//==================================== Disconnect_Call =============================================
Reconnect_Call::Reconnect_Call(quint64 hCard, quint64 hContext, int64_t dwShareMode, int64_t dwPreferredProtocols, int64_t dwInitialization, quint32 ioControlCode){
	
	uint32_t 	index = 0;
	quint32 	objectBufferLength = 0;
	QByteArray 	padding;
	quint32 	pbContextNdrPtr = 0x00020000;
	uint32_t 	status = SCARD_S_SUCCESS;
	QByteArray 	tmpInputBuffer;

	_outputBufferLength = 2048;	// [MS-RDPESC] 3.2.5.1
	_ioControlCode = ioControlCode;
	_dwShareMode = dwShareMode;
	_dwPreferredProtocols = dwPreferredProtocols;
	_dwInitialization = dwInitialization;
	_hCard._cbHandle = sizeof(hCard); // 8 байт
	_hCard._pbHandle << hCard;
	_hCard._Context._cbContext = sizeof(hContext); // 8 байт
	_hCard._Context._pbContext << hContext;

	status = packRedirScardContext(tmpInputBuffer, _hCard._Context, index, pbContextNdrPtr, objectBufferLength);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardContext fail");
	}

	status = packRedirScardHandle(tmpInputBuffer, _hCard, index, pbContextNdrPtr, objectBufferLength);
	if( status!= SCARD_S_SUCCESS ){
		CWLOG_WRN(TAG, "packRedirScardHandle fail");
	}

	tmpInputBuffer << _dwShareMode;
	objectBufferLength += sizeof(_dwShareMode);

	tmpInputBuffer << _dwPreferredProtocols;
	objectBufferLength += sizeof(_dwPreferredProtocols);

	tmpInputBuffer << _dwInitialization;
	objectBufferLength += sizeof(_dwInitialization);

	tmpInputBuffer << _hCard._Context._cbContext;
	tmpInputBuffer << hContext; 
	objectBufferLength += sizeof(_hCard._Context._cbContext) + _hCard._Context._pbContext.size();

	tmpInputBuffer << _hCard._cbHandle;
	tmpInputBuffer << hCard; 
	objectBufferLength += sizeof(_hCard._cbHandle) + _hCard._pbHandle.size();

	objectBufferLength += getPadding(padding, SMARTCARD_COMMON_TYPE_HEADER_LENGTH 
				+ SMARTCARD_PRIVATE_TYPE_HEADER_LENGTH 
				+ objectBufferLength); 

	packCommonTypeHeader(_inputBuffer);	
	packPrivateTypeHeader(_inputBuffer, objectBufferLength);
	_inputBuffer.append(tmpInputBuffer);
	_inputBuffer.append(padding); 
}

void Reconnect_Call::setResponse(QByteArray& buf){
	uint32_t 	index = 0;
	quint32 objectBufferLength;
	quint32 ndrPtr = 0;
	RdpStreamBuffer rsb(buf);
	rsb.sealLength(buf.size());

	qint32 res = unpackCommonTypeHeader(rsb);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}
	res = unpackPrivateTypeHeader(rsb, objectBufferLength);
	if(res != SCARD_S_SUCCESS){
		_response._returnCode = res;
		return;
	}

	rsb >> _response._returnCode;
	rsb >> _response._dwActiveProtocol;
}