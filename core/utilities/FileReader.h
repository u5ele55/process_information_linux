#pragma once

#include <string>
#include <vector>
#include <fstream>

class FileReader {
public:
    FileReader(const std::string &filename);
    /// @brief Reads a file
    /// @return Vector of file lines
    std::vector<std::string> content();
    virtual ~FileReader();
protected:
    std::ifstream file;
};