#include "NameGetter.h"

NameGetter::NameGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> NameGetter::get()
{
    ProcFileReader file(pid, "status");
    auto lines = file.content();
    auto nameLine = StringProcessing::filter(lines, "Name:");
    auto name = StringProcessing::split(nameLine[0], "\t")[1];

    return {name};
}