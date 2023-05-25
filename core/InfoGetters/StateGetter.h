#pragma once

#include "AbstractInfoGetter.h"

class StateGetter : public AbstractInfoGetter {
public:
    StateGetter(std::string pid);
    std::vector<std::string> get() override;
};
