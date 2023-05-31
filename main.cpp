#include "core/core.h"

int main(int argc, char* argv[]) {
    Core core(argc, argv);

    core.start();

    return 0;
}

/* 
/proc/<pid>/cmdline - empty for kernel processes

daemon:
/proc/<pid>>/fd/0 link is tty (readlink())
most likely process with no tty is a daemon.

*/ 