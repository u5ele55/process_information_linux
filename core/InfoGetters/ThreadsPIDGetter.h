#pragma once

#include "AbstractInfoGetter.h"

class ThreadsPIDGetter : public AbstractInfoGetter {
public:
    ThreadsPIDGetter(std::string pid);
    std::vector<std::string> get() override;
};
