#include "ProcFileReader.h"

#include "FileReader.h"

#include <sstream>

ProcFileReader::ProcFileReader(std::string pid, const std::string &name)
{
    std::ostringstream ss;
    ss << "/proc/" << pid << "/" << name;
    filename = ss.str();
}

std::vector<std::string> ProcFileReader::content()
{
    FileReader reader(filename);
    return reader.content();
}
