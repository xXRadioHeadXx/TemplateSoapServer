//
// Created by codeinside on 22.03.2025.
//

#include "LocatorConfiguration.h"

#include "YamlConfiguration.h"
#include "NullConfiguration.h"

const std::vector<std::shared_ptr<IConfiguration>> LocatorConfiguration::provideConfigurationVector = std::vector<std::shared_ptr<IConfiguration>>{std::make_shared<YamlConfiguration>()};
const std::shared_ptr<IConfiguration> LocatorConfiguration::nullConfiguration = std::make_shared<NullConfiguration>();
std::shared_ptr<IConfiguration> LocatorConfiguration::configuration = nullptr;