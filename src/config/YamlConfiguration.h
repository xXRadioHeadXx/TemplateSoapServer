//
// Created by codeinside on 21.03.2025.
//

#ifndef YAMLCONFIGURATION_H
#define YAMLCONFIGURATION_H
#include "IConfiguration.h"


class YamlConfiguration : public IConfiguration {
public:
    YamlConfiguration() {

    }

    YamlConfiguration(YamlConfiguration const &) = delete;

    void operator=(YamlConfiguration const &) = delete;

    virtual ~YamlConfiguration() = default;

    std::vector<std::string> typeCfg() const override {
        return std::vector<std::string>{"yaml"};
    }

    bool loadConfiguration(const std::string &path) override {
        auto cfgReader = figcone::ConfigReader{};
        auto cfg = cfgReader.readYamlFile<Cfg>(std::filesystem::canonical(path));
        m_cfg = cfg;
        return m_cfg.has_value();
    }

};


#endif //YAMLCONFIGURATION_H
