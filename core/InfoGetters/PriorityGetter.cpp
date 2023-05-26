#include "PriorityGetter.h"

PriorityGetter::PriorityGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> PriorityGetter::get()
{
    ProcFileReader file(pid, "stat");

    auto lines = file.content();
    auto priority = StringProcessing::split(lines[0], " ")[17];

    return {priority};
}
