#include "core.h"

#include <iostream>

#include "InfoGetters/PPIDGetter.h"
#include "utilities/StringProcessing.h"
#include "utilities/DirectoryChecker.h"

Core::Core(int argc, char *argv[])
    : inputSize(argc-1)
{
    for (int i = 1; i < argc; i++){
        input.emplace_back(argv[i]);
    }
}

void Core::start()
{
    if (inputSize == 0) {
        std::cout << "You must provide PID of process!\n";
        return;
    }
    if (input[0] == "help") {
        printHelp();
        return;
    }

    std::string pid = input[0];

    if (!StringProcessing::isNumeric(pid)) {
        std::cout << "PID must be a number!\n";
        return;
    }

    auto dirState = DirectoryChecker::checkDirectory("/proc/" + pid);
    if (dirState != DirectoryState::OK) {
        std::cout << "Can't check process with this PID!\n";
        return;
    }


    PPIDGetter ppidg(pid);
    std::cout << ppidg.get() << '\n';
}

void Core::printHelp()
{
    std::cout << "HELP PAGE FOR pInfo utility.";
}
