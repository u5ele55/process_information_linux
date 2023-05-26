#include "ThreadsPIDGetter.h"

#include <string>
#include <iostream>
#include <filesystem>

#include "../utilities/StringProcessing.h"

namespace fs = std::filesystem;

ThreadsPIDGetter::ThreadsPIDGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> ThreadsPIDGetter::get()
{
    std::string path = "/proc/" + pid + "/task";
    std::vector<std::string> res;
    
    for (const auto & entry : fs::directory_iterator(path)) {
        res.push_back(StringProcessing::split(entry.path(), "/")[4]);
    }
    return res;
}
