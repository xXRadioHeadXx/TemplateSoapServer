cmake_minimum_required(VERSION 3.29)
project(TemplateSoapServer)


set(KSWSDL2CPP_OPTION "-server")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

#set(CMAKE_PREFIX_PATH "/home/codeinside/Qt/6.8.2/gcc_64/bin")
set(Qt6 "/home/codeinside/Qt/6.8.2/gcc_64/lib/cmake/Qt6")
set(Qt6_DIR "/home/codeinside/Qt/6.8.2/gcc_64/lib/cmake/Qt6")
set(CMAKE_PREFIX_PATH "/home/codeinside/Qt/6.8.2/gcc_64")

set(KDSoap_DIR ./KDSoap)
set(KDSoap-qt6_DIR ./KDSoap/build-release-static)
include(${KDSoap-qt6_DIR}/KDSoap/KDSoapMacros.cmake)



set(KDSoap_INCLUDE_DIRS
        ./KDSoap/src/
        ./KDSoap/src/KDSoapClient/
        ./KDSoap/src/KDSoapServer/
        ./KDSoap/testtools/
        ./KDSoap/kdwsdl2cpp/
        ./KDSoap/kdwsdl2cpp/src/
        ./KDSoap/kdwsdl2cpp/libkode/code_generation/
        ./KDSoap/kdwsdl2cpp/libkode/
        ./KDSoap/kdwsdl2cpp/libkode/schema/
        ./KDSoap/kdwsdl2cpp/wsdl/)
#set(KDSoap_LIBRARY_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/lib/libkdsoap-qt6.a ${CMAKE_CURRENT_SOURCE_DIR}/lib/libkdwsdl2cpp_lib.a)

add_library(kdsoap SHARED IMPORTED)
set_property(TARGET kdsoap PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libkdsoap-qt6.a)

add_library(kdwsdl2cpp SHARED IMPORTED)
set_property(TARGET kdwsdl2cpp PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libkdwsdl2cpp_lib.a)


#include(${KDSoap-qt6_DIR}/KDSoap/KDSoapMacros.cmake)
include_directories( ${KDSoap_INCLUDE_DIRS} )
#link_directories( ${KDSoap_LIBRARY_DIRS} )

#find_package(KDSoap-qt6 CONFIG REQUIRED)



find_package(
        Qt6 COMPONENTS
        Core
        REQUIRED)
set(TemplateSoapServerSRCS
        ./src/main.cpp
        ./src/wsdl_helloworld.h
        src/wsdl_helloworld.cpp
)


#set(KDWSDL2CPP ./KDSoap/build-release-static/bin/kdwsdl2cpp-qt6)
#kdsoap_generate_wsdl(TemplateSoapServerSRCS ./src/helloworld.wsdl)

add_executable(
        TemplateSoapServer
        ${TemplateSoapServerSRCS}
)

target_link_libraries(
        TemplateSoapServer
        Qt::Core
        kdsoap
        kdwsdl2cpp
#        kdsoap-server
)

