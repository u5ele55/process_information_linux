#pragma once

#include <string>
#include <vector>

using std::string;

class StringProcessing {
public:
    static bool isNumeric(const string &s);
    /// @brief Filter lines like grep
    /// @return vector of lines for which `substring` is a substring
    static std::vector<string> filter(const std::vector<string> &lines, const string &substring);

    static std::vector<std::string> split(const std::string &s, const std::string &delimiter);
};