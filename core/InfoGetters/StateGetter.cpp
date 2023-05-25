#include "StateGetter.h"

StateGetter::StateGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> StateGetter::get()
{
    ProcFileReader file(pid, "status");
    auto lines = file.content();
    auto stateLine = StringProcessing::filter(lines, "State:");
    auto state = StringProcessing::split(stateLine[0], "\t")[1];

    return {state};
}