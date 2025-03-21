cd ./src/wsdl/

../../kdwsdl2cpp/kdwsdl2cpp \
-server \
-o wsdl_helloworld.h helloworld.wsdl

../../kdwsdl2cpp/kdwsdl2cpp \
-server \
-o wsdl_helloworld.cpp \
-impl wsdl_helloworld.h helloworld.wsdl
