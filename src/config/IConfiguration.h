//
// Created by codeinside on 21.03.2025.
//

#ifndef ICONFIGURATION_H
#define ICONFIGURATION_H
#include <optional>
#include <string>
#include <vector>

#include "StructCfg.h"

class IConfiguration
{
protected:
    std::optional<Cfg> m_cfg;
public:
    virtual std::vector<std::string> typeCfg() const {
        return std::vector<std::string>();
    }
    virtual bool loadConfiguration(const std::string &path) = 0;
    virtual std::optional<std::string> getConfigurationValue(const std::string &name)  {
        if (!m_cfg.has_value()) {
            return std::nullopt;
        }

        if (name.starts_with("application")) {
            if (name.starts_with("application.name")) {
                return std::optional<std::string>{m_cfg.value().application.name};
            }
        } else if (name.starts_with("server")) {
            if (name.starts_with("server.host")) {
                return std::optional<std::string>{m_cfg.value().server.host};
            } else if (name.starts_with("server.port")) {
                return std::optional<std::string>{m_cfg.value().server.port};
            } else if (name.starts_with("server.security")) {
                auto &security = m_cfg.value().server.security;
                if (!security.has_value()) {
                    return std::nullopt;
                } else if (name.starts_with("server.security.protocol")) {
                    return std::optional<std::string>{security.value().protocol};
                }
            }
        } else if (name.starts_with("datasource")) {
            auto &dataSource = m_cfg.value().datasource;
            if (!dataSource.has_value()) {
                return std::nullopt;
            } else if (name.starts_with("datasource.driver")) {
                return std::optional<std::string>{dataSource.value().driver};
            } else if (name.starts_with("datasource.url")) {
                return std::optional<std::string>{dataSource.value().url};
            } else if (name.starts_with("datasource.username")) {
                return std::optional<std::string>{dataSource.value().username};
            } else if (name.starts_with("datasource.password")) {
                return std::optional<std::string>{dataSource.value().password};
            }
        }

        return std::nullopt;
    }
};

#endif //ICONFIGURATION_H
