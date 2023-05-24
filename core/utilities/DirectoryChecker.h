#pragma once

#include <string>

enum class DirectoryState {
    NO_ACCESS, DOESNT_EXIST, OK
};

class DirectoryChecker {
public:
    static DirectoryState checkDirectory(const std::string &path);
};