#pragma once

#include "AbstractInfoGetter.h"

class FlagsGetter : public AbstractInfoGetter {
public:
    FlagsGetter(std::string pid);
    std::vector<std::string> get() override;
};