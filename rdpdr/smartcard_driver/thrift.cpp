#include "thrift.h"
#include "global_vars.h"

#include "gen-cpp/ogon.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

//#include <PCSC/winscard.h>
#include <mutex>
#include <iostream>

class ogonHandler : virtual public ogonIf {

  // This is code for current project only, it don't need into ogon
  // ------------- Begin -------------
  std::mutex mtx_;
  std::map<SCARDHANDLE_RPC, SCARDCONTEXT_RPC> Card2Context_;
  // -------------  End  -------------

public:
  ogonHandler() {
    // Your initialization goes here
  }

  void EstablishContext(return_ec& _return, const DWORD_RPC dwScope) {
    std::shared_ptr<smartcardIOControl_Call> establishContextCall = std::make_shared<EstablishContext_Call>();
    globalSmartCardOperationsThread->createHandle(establishContextCall);

    const char* ctxt = establishContextCall->getReturnReply().data();
    long *hContext = (long*) ctxt;

    _return.cardContext = *hContext;
    _return.retValue = establishContextCall->getReturnCode();
  }

  LONG_RPC ReleaseContext(const SCARDCONTEXT_RPC hContext) {
 
    std::shared_ptr<smartcardIOControl_Call> releaseContext_Call = std::make_shared<ReleaseContext_Call>(hContext);
    globalSmartCardOperationsThread->createHandle(releaseContext_Call);

    std::lock_guard<std::mutex> lock(mtx_);
    std::map<SCARDHANDLE_RPC, SCARDCONTEXT_RPC>::iterator itCard2Context = Card2Context_.begin();
    for(;itCard2Context != Card2Context_.end(); ++itCard2Context){
      if(itCard2Context->second == hContext){
        Card2Context_.erase(itCard2Context->first);
      }
    }

    return releaseContext_Call->getReturnCode();
  }

  void ListReaders(return_lr& _return, const SCARDCONTEXT_RPC hContext, const DWORD_RPC pcchReaders) {

    std::string szReaderName = "SCard$AllReaders";
    // LPSTR szReaderName = NULL;
    DWORD szReaderNameLen = pcchReaders;

    std::string readerBuf;

    if(SCARD_AUTOALLOCATE != szReaderNameLen) {
      readerBuf.resize(szReaderNameLen);
      szReaderName = readerBuf.data();
    }

    // LONG rv = SCardListReaders(hContext, NULL, (readerBuf.empty() ? (LPSTR)&szReaderName : szReaderName), &szReaderNameLen);

    std::shared_ptr<ListReaders_Call> listReaders_Call = std::make_shared<ListReaders_Call>(hContext, szReaderName, pcchReaders, SCARD_IOCTL_LISTREADERSA);
    globalSmartCardOperationsThread->createHandle(listReaders_Call);

    _return.retValue = listReaders_Call->getReturnCode();
    
    _return.mszReaders = std::string(listReaders_Call->getReturnReply().data(),listReaders_Call->getReturnCBytes());

    // auto sizeArr = listReaders_Call->getReturnReply().size();   // 57
    // auto sizeReaders = _return.mszReaders.size();               // 59
    // auto sizeCBytes = listReaders_Call->getReturnCBytes();      // 59

  }

  void ListReaderGroups(return_lrg& _return, const SCARDCONTEXT_RPC hContext, const DWORD_RPC pcchGroups) {

    std::shared_ptr<ListReaderGroups_Call> listReaderGroups_Call = std::make_shared<ListReaderGroups_Call>(hContext, pcchGroups, SCARD_IOCTL_LISTREADERGROUPSA);
    globalSmartCardOperationsThread->createHandle(listReaderGroups_Call);

    _return.retValue = listReaderGroups_Call->getReturnCode();
    _return.mszGroups = std::string(listReaderGroups_Call->getReturnReply().data(), listReaderGroups_Call->getReturnCBytes());
  }

  void Connect(return_c& _return, const SCARDCONTEXT_RPC hContext, const LPCSTR_RPC& szReader, const DWORD_RPC dwShareMode, const DWORD_RPC dwPreferredProtocols) {

    std::shared_ptr<Connect_Call> connect_Call = std::make_shared<Connect_Call>(hContext, szReader, dwShareMode, dwPreferredProtocols, SCARD_IOCTL_CONNECTA);
    globalSmartCardOperationsThread->createHandle(connect_Call);

    _return.retValue = connect_Call->getReturnCode();
    const char* chHandle = connect_Call->getReturnReply().data();
    SCARDHANDLE_RPC* handle = (SCARDHANDLE_RPC*) chHandle; 
    _return.phCard = *handle;
    _return.pdwActiveProtocol = connect_Call->getActiveProtocol();

    std::lock_guard<std::mutex> lock(mtx_);
    Card2Context_[_return.phCard] = hContext;
  }

  void Reconnect(return_r& _return, const SCARDHANDLE_RPC hCard, const DWORD_RPC dwShareMode, const DWORD_RPC dwPreferredProtocols, const DWORD_RPC dwInitialization) {

     SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<Reconnect_Call> reconnect_Call = std::make_shared<Reconnect_Call>(hCard, hContext, dwShareMode, dwPreferredProtocols, dwInitialization);
    globalSmartCardOperationsThread->createHandle(reconnect_Call);

    _return.retValue = reconnect_Call->getReturnCode();
    _return.pdwActiveProtocol = reconnect_Call->getDwActiveProtocol();
  }

  LONG_RPC Disconnect(const SCARDHANDLE_RPC hCard, const DWORD_RPC dwDisposition) {
    SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<Disconnect_Call> disconnect_Call = std::make_shared<Disconnect_Call>(hCard, hContext, dwDisposition);
    globalSmartCardOperationsThread->createHandle(disconnect_Call);
    
    return disconnect_Call->getReturnCode();
  }

  void Status(return_s& _return, const SCARDHANDLE_RPC hCard, const DWORD_RPC pcchReaderLen, const DWORD_RPC pcbAtrLen) {

    SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<Status_Call> status_Call = std::make_shared<Status_Call>(hCard, hContext, pcchReaderLen, pcbAtrLen, SCARD_IOCTL_STATUSA);
    globalSmartCardOperationsThread->createHandle(status_Call);

    _return.retValue = status_Call->getReturnCode();
    _return.szReaderName = std::string(status_Call->getReaderNames().data(), status_Call->getReaderNames().size());
    _return.pdwState = status_Call->getDwState();
    _return.pdwProtocol = status_Call->getDwProtocol();
    _return.pbAtr = std::string(status_Call->getReturnReply().data(), status_Call->getReturnReply().size());
  }

  void GetStatusChange(return_gsc& _return, const SCARDCONTEXT_RPC hContext, const DWORD_RPC dwTimeout, const std::vector<scard_readerstate_rpc> & rgReaderStates, const DWORD_RPC cReaders) {
      
      std::shared_ptr<GetStatusChange_Call> getStatusChange_Call = std::make_shared<GetStatusChange_Call>(hContext, dwTimeout, rgReaderStates, cReaders, SCARD_IOCTL_GETSTATUSCHANGEA);
      globalSmartCardOperationsThread->createHandle(getStatusChange_Call);

      std::vector<scard_readerstate_rpc> outReaderStates(cReaders);

      auto ret = getStatusChange_Call->getGetStatusChange_Return();
      if(getStatusChange_Call->getReturnCode() == SCARD_S_SUCCESS){
        for (int i = 0; i < cReaders; i++) {
          outReaderStates[i].dwEventState = ret[i]._dwEventState;
          outReaderStates[i].rgbAtr = std::string((char*)ret[i]._rgbAtr.data(), ret[i]._cbAtr);
        }
      }
      _return.retValue = getStatusChange_Call->getReturnCode();
      _return.rgReaderStates = outReaderStates;
  }

  void Transmit(return_t& _return, const SCARDHANDLE_RPC hCard, const scard_io_request_rpc& pioSendPci, const LPBYTE_RPC& pbSendBuffer, const DWORD_RPC pcbRecvLength) {
  
    SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<Transmit_Call> transmit_Call = std::make_shared<Transmit_Call>(hCard, hContext, pioSendPci, pbSendBuffer, pcbRecvLength);
    globalSmartCardOperationsThread->createHandle(transmit_Call);

    scard_io_request_rpc ioRecvPciRPC;

    ioRecvPciRPC.dwProtocol = 0;  // _response._pioRecvPci.dwProtocol;
    ioRecvPciRPC.cbPciLength = 0; // _response._pioRecvPci.cbPciLength;

    _return.retValue = transmit_Call->getReturnCode();;
    _return.pioRecvPci = ioRecvPciRPC;
    _return.pbRecvBuffer = std::string(transmit_Call->getReturnReply().data(), transmit_Call->getCbRecvLength());
  }

  LONG_RPC BeginTransaction(const SCARDHANDLE_RPC hCard) {

    SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<BeginTransaction_Call> beginTransaction_Call = std::make_shared<BeginTransaction_Call>(hCard, hContext);
    globalSmartCardOperationsThread->createHandle(beginTransaction_Call);
    
    return beginTransaction_Call->getReturnCode();

  }

  LONG_RPC EndTransaction(const SCARDHANDLE_RPC hCard, const DWORD_RPC dwDisposition) {

    SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<EndTransaction_Call> endTransaction_Call = std::make_shared<EndTransaction_Call>(hCard, hContext, dwDisposition);
    globalSmartCardOperationsThread->createHandle(endTransaction_Call);
    
    return endTransaction_Call->getReturnCode();
  }

  void GetAttrib(return_ga& _return, const SCARDHANDLE_RPC hCard, const DWORD_RPC dwAttrId, const DWORD_RPC pcbAttrLen) {

    SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<GetAttrib_Call> getAttrib_Call = std::make_shared<GetAttrib_Call>(hCard, hContext, dwAttrId, pcbAttrLen);
    globalSmartCardOperationsThread->createHandle(getAttrib_Call);
    
    _return.retValue = getAttrib_Call->getReturnCode();
    _return.pbAttr = std::string(getAttrib_Call->getReturnReply().data(), getAttrib_Call->getCbAttrLen());
  }

  void Control(return_ctrl& _return, const SCARDHANDLE_RPC hCard, const DWORD_RPC dwControlCode, const LPVOID_RPC& pbSendBuffer, const DWORD_RPC cbRecvLength) {

    SCARDCONTEXT_RPC hContext;
    {
      std::lock_guard<std::mutex> lock(mtx_);
      hContext = Card2Context_[hCard];
    }

    std::shared_ptr<Control_Call> control_Call = std::make_shared<Control_Call>(hCard, hContext, dwControlCode, pbSendBuffer, cbRecvLength);
    globalSmartCardOperationsThread->createHandle(control_Call);
    
    _return.retValue = control_Call->getReturnCode(); 
    _return.pbRecvBuffer = std::string(control_Call->getReturnReply().data(), control_Call->getCbOutBufferSize());
  }
  
  LONG_RPC Cancel(const SCARDCONTEXT_RPC hContext) {
    
    std::shared_ptr<Cancel_Call> cancel_Call = std::make_shared<Cancel_Call>(hContext);
    globalSmartCardOperationsThread->createHandle(cancel_Call);
    
    return cancel_Call->getReturnCode();
  }

  LONG_RPC IsValidContext(const SCARDCONTEXT_RPC hContext) {
    std::shared_ptr<IsValidContext_Call> isValidContext_Call = std::make_shared<IsValidContext_Call>(hContext);
    globalSmartCardOperationsThread->createHandle(isValidContext_Call);
    
    return isValidContext_Call->getReturnCode();
  }
};

void thrift_start_process() {
  int port = 9092;
  ::std::shared_ptr<ogonHandler> handler(new ogonHandler());
  ::std::shared_ptr<TProcessor> processor(new ogonProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  try{
    server.serve();
  }catch(...){
    std::cout << "here";
  }
}

