cmake_minimum_required(VERSION 3.29)
project(TemplateSoapServer)

set(CMAKE_CXX_STANDARD 20)

if (DEFINED Qt5_DIR)
    if (NOT "${Qt5_DIR}" STREQUAL "")
        set(Qt5_DIR "/home/codeinside/Qt/5.15.2/gcc_64/lib/cmake/Qt5")
    endif ()
endif ()

if (DEFINED Qt5)
    if (NOT "${Qt5}" STREQUAL "")
        set(Qt5 "/home/codeinside/Qt/5.15.2/gcc_64/lib/cmake")
    endif ()
endif ()

if (DEFINED CMAKE_PREFIX_PATH)
    if (NOT "${CMAKE_PREFIX_PATH}" STREQUAL "")
        set(CMAKE_PREFIX_PATH "/home/codeinside/Qt/5.15.2/gcc_64/lib/cmake")
    endif ()
endif ()

include(FetchContent)
FetchContent_Declare(figcone
        GIT_REPOSITORY "git@github.com:xXRadioHeadXx/figcone.git"
        GIT_TAG "origin/master"
)
#uncomment if you need to install figcone with your target
#set(INSTALL_FIGCONE ON)
set(FIGCONE_USE_ALL OFF)
set(FIGCONE_USE_JSON OFF)
set(FIGCONE_USE_YAML ON)
set(FIGCONE_USE_TOML OFF)
set(FIGCONE_USE_XML OFF)
set(FIGCONE_USE_INI OFF)
set(FIGCONE_USE_SHOAL OFF)

FetchContent_MakeAvailable(figcone)


set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_AUTOUIC ON)

set(KDSoap_DIR KDSoap)
set(KDSoap_BINARY_DIRS ${KDSoap_DIR}/build)
set(KDSoap_INCLUDE_DIRS
        ${KDSoap_DIR}/src
        ${KDSoap_DIR}/src/KDSoapClient
        ${KDSoap_DIR}/src/KDSoapServer
)

add_library(KDSoap::kdsoap STATIC IMPORTED)
set_property(TARGET KDSoap::kdsoap PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libkdsoap.a)

add_library(KDSoap::kdsoap-server STATIC IMPORTED)
set_property(TARGET KDSoap::kdsoap-server PROPERTY IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/lib/libkdsoap-server.a)

find_package(
        Qt5 COMPONENTS
        Core
        Network
        REQUIRED)

include_directories(
        ${KDSoap_INCLUDE_DIRS}
)

set(TemplateSoapServerSRCS
        ./src/main.cpp
        ./src/wsdl/wsdl_helloworld.h
        ./src/wsdl/wsdl_helloworld.cpp
        ./src/helloworld_serverobject.h
        ./src/helloworld_serverobject.cpp
        src/config/StructCfg.h
        src/config/IConfiguration.h
        src/config/YamlConfiguration.h
        src/config/LocatorConfiguration.cpp
        src/config/LocatorConfiguration.h
        src/config/ConfigurationService.h
)

#include(${KDSoap_BINARY_DIRS}/KDSoap/KDSoapMacros.cmake)
#kdsoap_generate_wsdl(TemplateSoapServerSRCS ./src/wsdl/helloworld.wsdl)

add_executable(
        ${PROJECT_NAME}
        ${TemplateSoapServerSRCS}
)

target_link_libraries(
        ${PROJECT_NAME}
        Qt5::Core
        Qt5::Network
        KDSoap::kdsoap
        KDSoap::kdsoap-server
        figcone::figcone
)

