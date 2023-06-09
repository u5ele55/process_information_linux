#pragma once

#include "AbstractInfoGetter.h"

class PPIDGetter : public AbstractInfoGetter {
public:
    PPIDGetter(std::string pid);
    std::vector<std::string> get() override;
};