//
// Created by codeinside on 21.03.2025.
//

#ifndef STRUCTCFG_H
#define STRUCTCFG_H

#include <figcone/config.h>
#include <string>

struct ApplicationCfg : public figcone::Config {
    std::string name = param<&ApplicationCfg::name>();
};

struct SecurityCfg : public figcone::Config {
    std::string protocol = param<&SecurityCfg::protocol>();
};

struct ServerCfg : public figcone::Config {
    std::string host = param<&ServerCfg::host>();
    std::string port = param<&ServerCfg::port>();
    figcone::optional<SecurityCfg> security = node<&ServerCfg::security>();

    // using traits = figcone::FieldTraits<
        // figcone::OptionalField<&ServerCfg::security>>;
};

struct DatasourceCfg : public figcone::Config {
    std::string driver = param<&DatasourceCfg::driver>();
    std::string url = param<&DatasourceCfg::url>();
    std::string username = param<&DatasourceCfg::username>();
    std::string password = param<&DatasourceCfg::password>();
};

struct Cfg : public figcone::Config {
    ApplicationCfg application = node<&Cfg::application>();
    ServerCfg server = node<&Cfg::server>();
    figcone::optional<DatasourceCfg> datasource = node<&Cfg::datasource>();

    // using traits = figcone::FieldTraits<
        // figcone::OptionalField<&Cfg::application>,
        // figcone::OptionalField<&Cfg::server>,
        // figcone::CopyNodeListField<&Cfg::datasource>>;
};

#endif //STRUCTCFG_H
