#include "FileReader.h"

FileReader::FileReader(const std::string &filename)
{
    file.open(filename);
}

std::vector<std::string> FileReader::content() {
    std::string line;
    std::vector<std::string> res;
    if (file.is_open()) {
        while ( getline (file, line) ) {
            res.push_back(line);
        }
    }
    return res;
}

FileReader::~FileReader()
{
    file.close();
}
