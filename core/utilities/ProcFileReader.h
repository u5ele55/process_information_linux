#pragma once

#include <string>
#include <vector>

class ProcFileReader {
public:
    ProcFileReader(std::string pid, const std::string &name);
    /// @brief Reads a file
    /// @return Vector of file lines
    std::vector<std::string> content();
private:
    std::string filename;
};