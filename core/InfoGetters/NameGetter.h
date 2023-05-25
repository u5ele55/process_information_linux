#pragma once

#include "AbstractInfoGetter.h"

class NameGetter : public AbstractInfoGetter {
public:
    NameGetter(std::string pid);
    std::vector<std::string> get() override;
};