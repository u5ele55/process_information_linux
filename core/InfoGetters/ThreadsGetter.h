#pragma once

#include "AbstractInfoGetter.h"

class ThreadsGetter : public AbstractInfoGetter {
public:
    ThreadsGetter(std::string pid);
    std::vector<std::string> get() override;
};
