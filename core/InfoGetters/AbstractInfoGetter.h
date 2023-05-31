#pragma once

#include <string>
#include <vector>
#include "../utilities/FileReader.h"
#include "../utilities/ProcFileReader.h"
#include "../utilities/StringProcessing.h"

class AbstractInfoGetter {
public:
    AbstractInfoGetter(std::string pid);
    virtual std::vector<std::string> get() = 0;
protected:
    std::string pid;
};