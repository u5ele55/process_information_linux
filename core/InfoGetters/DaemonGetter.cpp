#include "DaemonGetter.h"

#include <unistd.h>
#include <cstring>
#include <iostream>

DaemonGetter::DaemonGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> DaemonGetter::get()
{
    // /proc/<pid>>/fd/0 link is tty (readlink())
    auto path = "/proc/" + pid + "/fd/0";
    
    std::string answer;
    char link[100];

    size_t len = readlink(path.c_str(), link, 100);

    if (len == -1) {
        answer = "Most likely daemon";
    } 
    else {
        answer = "Not a daemon";
    }

    return {answer};
}
