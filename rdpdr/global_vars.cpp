#include "global_vars.h"

RDPDrChannelServer *globalRDPDrChannelSmartCard = nullptr;
RDPDrChannelServer::RdpDrDevice *globalRdpDrDeviceSmartCard = nullptr;
RDPDrChannelServer::SmartCardOperationsThread *globalSmartCardOperationsThread = nullptr;

//std::shared_ptr<smartcardIOControl_Call> globalEstablishContextCall = std::make_shared<EstablishContext_Call>();

//std::shared_ptr<smartcardIOControl_Call> globalListReadersCall = std::make_shared<ListReaders_Call>();
