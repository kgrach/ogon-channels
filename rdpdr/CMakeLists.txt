set(MODULE_NAME "rdpdr")

include(FindQT5)

if (UNIX)
	find_package(FUSE REQUIRED)
endif()

find_package(PkgConfig)
pkg_check_modules(pcsc REQUIRED libpcsclite)

pkg_check_modules(thrift REQUIRED thrift)
#pkg_check_modules(thrift REQUIRED thrift_c_glib)

set(${MODULE_NAME}_SRCS
	rdpdr.cpp
	rdpdrchannelserver.cpp
	rdpdrchannelserver.h
	smartcard/smartcard_operations.h
	smartcard/smartcard_operations.cpp
	smartcard/QByteArrayWriteInteger.h
	smartcard_driver/UsbConfig.h
	smartcard_driver/UsbConfig.cpp
	smartcard_driver/thrift.h
	smartcard_driver/thrift.cpp
	# smartcard_driver/gen-c_glib/ogon_types.h
    # smartcard_driver/gen-c_glib/ogon.h
	# smartcard_driver/gen-c_glib/ogon_types.c
    # smartcard_driver/gen-c_glib/ogon.c
	smartcard_driver/gen-cpp/ogon_types.cpp
    smartcard_driver/gen-cpp/ogon.cpp
	smartcard/smartcard_message.h	
	smartcard/smartcard_message.cpp
	global_vars.h
	global_vars.cpp
    )

add_executable(${MODULE_NAME} ${${MODULE_NAME}_SRCS})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${QT_EXECUTEABLE_FLAGS}")

add_definitions(${FUSE_DEFINITIONS})
include_directories(${FUSE_INCLUDE_DIRS} ${thrift_INCLUDE_DIRS} ${pcsc_INCLUDE_DIRS})


target_link_libraries(${MODULE_NAME} ${QT_LIBRARIES} ${FUSE_LIBRARIES} ${thrift_LIBRARIES} ${pcsc_LIBRARIES} ogon-qtrdpchannelserver)

install(TARGETS ${MODULE_NAME} DESTINATION "${CMAKE_INSTALL_BINDIR}")

