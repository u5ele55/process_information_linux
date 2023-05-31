#pragma once

#include "AbstractInfoGetter.h"

class DaemonGetter : public AbstractInfoGetter {
public:
    DaemonGetter(std::string pid);
    std::vector<std::string> get() override;
};