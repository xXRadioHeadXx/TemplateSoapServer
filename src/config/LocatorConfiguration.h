//
// Created by codeinside on 22.03.2025.
//

#ifndef LOCATORCONFIGURATION_H
#define LOCATORCONFIGURATION_H
#include "IConfiguration.h"

class LocatorConfiguration {
private:
    static const std::vector<std::shared_ptr<IConfiguration> > provideConfigurationVector;
    static const std::shared_ptr<IConfiguration> nullConfiguration;
    static std::shared_ptr<IConfiguration> configuration;
    static void init() {
        configuration = nullConfiguration;
    }

public:
    static std::shared_ptr<IConfiguration> getConfiguration() {
        if (LocatorConfiguration::configuration == nullptr) {
            LocatorConfiguration::init();
        }

        return LocatorConfiguration::configuration;
    }

    static void setTypeProvideConfiguration(std::string type) {
        if (type.empty()) {
            LocatorConfiguration::configuration = LocatorConfiguration::nullConfiguration;
            return;
        }

        if (LocatorConfiguration::configuration == nullptr) {
            LocatorConfiguration::init();
        }

        for (auto provideConfiguration: LocatorConfiguration::provideConfigurationVector) {
            auto v = provideConfiguration->typeCfg();
            if (std::find(v.begin(), v.end(), type) != v.end()) {
                LocatorConfiguration::configuration = provideConfiguration;
                return;
            }
        }
    }
};

#endif //LOCATORCONFIGURATION_H
