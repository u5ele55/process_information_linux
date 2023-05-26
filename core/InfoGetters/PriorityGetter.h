#pragma once

#include "AbstractInfoGetter.h"

class PriorityGetter : public AbstractInfoGetter {
public:
    PriorityGetter(std::string pid);
    std::vector<std::string> get() override;
};
