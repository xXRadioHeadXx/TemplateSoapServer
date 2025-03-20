#include <iostream>

#include <QCoreApplication>

#include "KDSoapServer.h"
#include "helloworld_serverobject.h"
#include <iostream>

class Server : public KDSoapServer
{
    Q_OBJECT
public:
    using KDSoapServer::KDSoapServer;

    QObject *createServerObject() override
    {
        return new HelloWorldServerObject;
    }
};

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    Server server;
    server.setLogLevel(Server::LogEveryCall);
    const bool listening = server.listen(QHostAddress::Any, 8081);
    if (!listening) {
        std::cerr << "Cannot start server: " << qPrintable(server.errorString()) << std::endl;
        return 1;
    } else {
        std::cout << "Listening..." << std::endl;
    }
    return app.exec();
}
#include "main.moc"