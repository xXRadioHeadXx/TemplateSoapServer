mkdir lib

mkdir kdwsdl2cpp

cd ./KDSoap

mkdir build

git submodule update --init --recursive

cmake \
-DCMAKE_PREFIX_PATH=/home/codeinside/Qt/5.15.2/gcc_64 \
-DQt5_DIR=/home/codeinside/Qt/5.15.2/gcc_64/lib/cmake/Qt5 \
-DKDSoap_QT6=False \
-DKDSoap_TESTS=False \
-DKDSoap_EXAMPLES=False \
-DKDSoap_DOCS=False \
-DKDSoap_STATIC=True \
-DCMAKE_BUILD_TYPE=Release \
-S . \
-B build \
-DXKB_INCLUDE_DIR:PATH=XKB_INCLUDE_DIR-NOTFOUND \
-DXKB_LIBRARY:FILEPATH=XKB_LIBRARY-NOTFOUND \
-DCMAKE_INSTALL_PREFIX=../lib

cmake \
--build build \
--target kdwsdl2cpp_lib

cmake \
--build build \
--target kdsoap

cmake \
--build build \
--target kdsoap-server

cmake \
--build build \
--target kdwsdl2cpp

cp ./build/lib/libkdsoap.a ../lib/libkdsoap.a

cp ./build/lib/libkdwsdl2cpp_lib.a ../lib/libkdwsdl2cpp_lib.a

cp ./build/lib/libkdsoap-server.a ../lib/libkdsoap-server.a

cp ./build/bin/kdwsdl2cpp ../kdwsdl2cpp/kdwsdl2cpp
