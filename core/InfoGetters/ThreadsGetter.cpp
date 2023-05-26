#include "ThreadsGetter.h"

ThreadsGetter::ThreadsGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> ThreadsGetter::get()
{
    ProcFileReader file(pid, "status");

    auto lines = file.content();
    auto threadsLine = StringProcessing::filter(lines, "Threads:");
    auto threads = StringProcessing::split(threadsLine[0], "\t");

    return {threads[1]};
}
