#pragma once

#include "gen-c_glib/ogon.h"

#include <thrift/c_glib/server/thrift_simple_server.h>
#include <thrift/c_glib/transport/thrift_server_socket.h>
#include <thrift/c_glib/transport/thrift_buffered_transport_factory.h>
#include <thrift/c_glib/protocol/thrift_binary_protocol_factory.h>
#include <thrift/c_glib/protocol/thrift_protocol_factory.h>
#include <thrift/c_glib/transport/thrift_server_transport.h>
#include <thrift/c_glib/thrift.h>

#include <glib-object.h>
#include <glib.h>

#include <stdio.h>

#include "global_vars.h"

//#include <PCSC/winscard.h>
//#include <PCSC/pcsclite.h>

#ifdef __cplusplus
extern "C" {
#endif


int thrift_start_process (void);

#ifdef __cplusplus
};
#endif