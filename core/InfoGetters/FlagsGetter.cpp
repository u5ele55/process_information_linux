#include "FlagsGetter.h"

#include <map>

// from https://github.com/torvalds/linux/blob/master/include/linux/sched.h PF_* defines

static std::map<int, std::string> flag_converter = {
    {0x00000001,"I'm a virtual CPU"},
    {0x00000002,"I am an IDLE thread"},
    {0x00000004,"Getting shut down"},
    {0x00000008,"Coredumps should ignore this task"},
    {0x00000010,"Task is an IO worker"},
    {0x00000020,"I'm a workqueue worker"},
    {0x00000040,"Forked but didn't exec"},
    {0x00000080,"Process policy on mce errors"},
    {0x00000100,"Used super-user privileges"},
    {0x00000200,"Dumped core"},
    {0x00000400,"Killed by a signal"},
    {0x00000800,"Allocating memory"},
    {0x00001000,"set_user() noticed that RLIMIT_NPROC was exceeded"},
    {0x00002000,"If unset the fpu must be initialized before use"},
    {0x00004000,"Kernel thread cloned from userspace thread"},
    {0x00008000,"This thread should not be frozen"},
    {0x00020000,"I am kswapd"},
    {0x00040000,"All allocation requests will inherit GFP_NOFS"},
    {0x00080000,"All allocation requests will inherit GFP_NOIO"},
    {0x00100000,"Throttle writes only against the bdi I write to, I am cleaning dirty pages from some other bdi."},
    {0x00200000,"I am a kernel thread"},
    {0x00400000,"Randomize virtual address space"},
    {0x04000000,"Userland is not allowed to meddle with cpus_mask"},
    {0x08000000,"Early kill for mce process policy"},
    {0x10000000,"Allocation context constrained to zones which allow long term pinning."},
    {0x80000000,"This thread called freeze_processes() and should not be frozen"}
};


FlagsGetter::FlagsGetter(std::string pid) : AbstractInfoGetter(pid) {}

std::vector<std::string> FlagsGetter::get()
{
    ProcFileReader file(pid, "stat");

    int flags = std::stoi(StringProcessing::split(file.content()[0], " ")[8]);
    std::vector<std::string> ans;

    for (int i = 1; i < 0x80000000; i *= 2) {
        if (flags & i) {
            ans.push_back(flag_converter[i]);
        }
    }

    if (flags & 0x80000000) {
        ans.push_back(flag_converter[0x80000000]);
    }

    return ans;
}
