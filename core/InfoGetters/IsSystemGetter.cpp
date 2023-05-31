#include "IsSystemGetter.h"
#include <iostream>

IsSystemGetter::IsSystemGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> IsSystemGetter::get()
{
    // read /proc/pid/cmdline - empty for kernel process
    FileReader reader("/proc/" + pid + "/cmdline");

    auto content = reader.content();
    std::string answer;

    if (content.size() == 0) {
        answer = "Kernel process";
    } 
    else {
        answer = "Not a kernel process";
    }

    return {answer};
}
