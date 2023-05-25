#pragma once

#include "InfoGetters/AbstractInfoGetter.h"

class GetterMaster {
public:
    GetterMaster(const std::string &pid);
    AbstractInfoGetter *operator()(const std::string &getterName);
private:
    std::string pid;
};