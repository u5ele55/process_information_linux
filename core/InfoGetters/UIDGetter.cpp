#include "UIDGetter.h"

UIDGetter::UIDGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> UIDGetter::get()
{
    ProcFileReader file(pid, "loginuid");

    return {file.content()[0]};
}
