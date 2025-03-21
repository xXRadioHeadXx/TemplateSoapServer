//
// Created by codeinside on 21.03.2025.
//

#ifndef NULLCONFIGURATION_H
#define NULLCONFIGURATION_H
#include "IConfiguration.h"


class NullConfiguration : public IConfiguration {
public:
    NullConfiguration() {

    }

    NullConfiguration(NullConfiguration const &) = delete;

    void operator=(NullConfiguration const &) = delete;

    virtual ~NullConfiguration() = default;

    bool loadConfiguration(const std::string &path) override {
        return false;
    }

};


#endif //NULLCONFIGURATION_H
