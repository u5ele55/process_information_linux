#include "PolicyGetter.h"

#include <linux/sched.h>
#include <map>

PolicyGetter::PolicyGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> PolicyGetter::get()
{
    ProcFileReader file(pid, "stat");

    auto lines = file.content();
    auto policy = StringProcessing::split(lines[0], " ")[40];

    int plc = atoi(policy.c_str());


    std::map<int, std::string> conversion = {
        {SCHED_FIFO, "SCHED_FIFO"},
        {SCHED_RR, "SCHED_RR"},
        {SCHED_OTHER, "SCHED_OTHER"},
        {SCHED_BATCH, "SCHED_BATCH"},
        {SCHED_IDLE, "SCHED_IDLE"}
    };

    if (conversion.count(plc)) {
        return {conversion[plc]};
    }

    return {"UNKNOWN"};
}
