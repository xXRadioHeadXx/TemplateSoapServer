#mkdir lib

#mkdir kdwsdl2cpp

cd ./KDSoap

#git submodule update --init --recursive

cmake \
-DCMAKE_PREFIX_PATH=/home/codeinside/Qt/6.8.2/gcc_64 \
-DQt6_DIR=/home/codeinside/Qt/6.8.2/gcc_64/lib/cmake/Qt6 \
-DKDSoap_STATIC=True \
-DCMAKE_BUILD_TYPE=Release \
-S ./ \
-B ./build-release-static \
-DXKB_INCLUDE_DIR:PATH=XKB_INCLUDE_DIR-NOTFOUND \
-DXKB_LIBRARY:FILEPATH=XKB_LIBRARY-NOTFOUND \
-DCMAKE_INSTALL_PREFIX=../lib

cmake \
--build ./build-release-static \
--target kdwsdl2cpp_lib

cmake \
--build ./build-release-static \
--target kdsoap

cmake \
--build ./build-release-static \
--target kdsoap-server

cmake \
--build ./build-release-static \
--target kdwsdl2cpp

cp ./build-release-static/lib/libkdsoap-qt6.a ../lib/libkdsoap-qt6.a

cp ./build-release-static/lib/libkdwsdl2cpp_lib.a ../lib/libkdwsdl2cpp_lib.a

cp ./build-release-static/lib/libkdsoap-server-qt6.a ../lib/libkdsoap-server-qt6.a

cp ./build-release-static/bin/kdwsdl2cpp-qt6 ../libkdwsdl2cpp/kdwsdl2cpp-qt6
