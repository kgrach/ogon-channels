#pragma once

#include "rdpdrchannelserver.h"
#include "smartcard/smartcard_operations.h"


extern RDPDrChannelServer *globalRDPDrChannelSmartCard;
extern RDPDrChannelServer::RdpDrDevice *globalRdpDrDeviceSmartCard;
extern RDPDrChannelServer::SmartCardOperationsThread *globalSmartCardOperationsThread;

extern std::shared_ptr<smartcardIOControl_Call> globalEstablishContextCall;

//std::shared_ptr<smartcardIOControl_Call> globalListReadersCall = std::make_shared<ListReaders_Call>();
