//
// Created by codeinside on 22.03.2025.
//

#ifndef CONFIGURATIONSERVICE_H
#define CONFIGURATIONSERVICE_H
#include <string>

#include "LocatorConfiguration.h"


class ConfigurationService {
public:
    static bool init(const std::string &path) {
        std::string base_filename = path.substr(path.find_last_of("/\\") + 1);
        std::string base_filename_type = base_filename.substr(base_filename.find_last_of('.') + 1);
        LocatorConfiguration::setTypeProvideConfiguration(base_filename_type);
        return LocatorConfiguration::getConfiguration()->loadConfiguration(path);
    }

    static std::optional<std::string> value(const std::string &path) {
        return LocatorConfiguration::getConfiguration()->getConfigurationValue(path);
    }

};



#endif //CONFIGURATIONSERVICE_H
