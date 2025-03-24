#include <iostream>

#include <QCoreApplication>

#include <KDSoapServer.h>
#include "helloworld_serverobject.h"
#include <iostream>
#include <QHostAddress>

#include <boost/program_options.hpp>

#include "config/ConfigurationService.h"
#include "config/LocatorConfiguration.h"

class Server : public KDSoapServer {
    Q_OBJECT

public:
    using KDSoapServer::KDSoapServer;

    QObject *createServerObject() override {
        return new HelloWorldServerObject;
    }
};

// using namespace boost::program_options;

int main(int argc, char **argv) {
    try {
        boost::program_options::options_description generalOptions{"General"};
        generalOptions.add_options()
                ("help,h", "Help screen")
                ("config,c", boost::program_options::value<std::string>(), "Config file");

        boost::program_options::options_description fileOptions{"File"};
        fileOptions.add_options()
                ("age", boost::program_options::value<int>(), "Age");

        boost::program_options::variables_map vm;
        boost::program_options::store(boost::program_options::parse_command_line(argc, argv, generalOptions), vm);
        if (vm.count("config")) {
            std::ifstream ifs{vm["config"].as<std::string>().c_str()};
            if (ifs) {
                ConfigurationService::init(vm["config"].as<std::string>().c_str());

                QCoreApplication app(argc, argv);
                /**
                 * main programm
                 */

                Server server;
                server.setLogLevel(Server::LogEveryCall);
                const bool listening = server.listen(QHostAddress::Any,
                                                     std::stoi(ConfigurationService::value("server.port").value()));
                if (!listening) {
                    std::cerr << "Cannot start server: " << qPrintable(server.errorString()) << std::endl;
                    return 1;
                } else {
                    std::cout << "Listening..." << std::endl;
                }

                return app.exec();
            }
        }
        notify(vm);

        if (vm.count("help")) {
            std::cout << generalOptions << '\n';
        }
    } catch (const boost::program_options::error &ex) {
        std::cerr << ex.what() << '\n';
    }
}

#include "main.moc"
