#pragma once

#include "AbstractInfoGetter.h"

class IsSystemGetter : public AbstractInfoGetter {
public:
    IsSystemGetter(std::string pid);
    std::vector<std::string> get() override;
};