#pragma once

#include "AbstractInfoGetter.h"

class UIDGetter : public AbstractInfoGetter {
public:
    UIDGetter(std::string pid);
    std::vector<std::string> get() override;
};
