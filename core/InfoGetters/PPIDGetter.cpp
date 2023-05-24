#include "PPIDGetter.h"
#include <iostream>
PPIDGetter::PPIDGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::string PPIDGetter::get()
{
    ProcFileReader file(pid, "status");

    auto lines = file.content();
    auto ppidLine = StringProcessing::filter(lines, "PPid");
    auto ppid = StringProcessing::split(ppidLine[0], "\t");

    return ppid[1];
}
