#pragma once

#include "AbstractInfoGetter.h"

class PolicyGetter : public AbstractInfoGetter {
public:
    PolicyGetter(std::string pid);
    std::vector<std::string> get() override;
};
