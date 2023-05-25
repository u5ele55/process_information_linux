#include "core.h"

#include <iostream>

#include "GetterMaster.h"
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
        std::cout << "You can use help keyword to print manual page\n";
        return;
    }

    auto dirState = DirectoryChecker::checkDirectory("/proc/" + pid);
    if (dirState != DirectoryState::OK) {
        std::cout << "Can't check process with this PID!\n";
        return;
    }

    GetterMaster info(pid);
    AbstractInfoGetter *getter;

    for (int i = 1; i < inputSize; i ++) {
        const std::string &keyword = input[i];
        std::vector<std::string> lines;
        bool getterCreated = false;

        try {
            getter = info(keyword);
            try {
                lines = getter->get();
            } catch (...) {
                lines.push_back("<Something went wrong>");
            }
        } catch (const std::invalid_argument &err) {
            lines.push_back(err.what());
        }


        if (lines.size() == 0) {
            std::cout << keyword << ": <Could't get info>" << "\n";
        }
        else if (lines.size() == 1) {
            std::cout << keyword << ": " << lines[0] << "\n";
        } 
        else {
            std::cout << keyword << ":\n";
            for (const auto &line : lines) {
                std::cout << '\t' << line << '\n';
            }
        }
        delete getter;
    }
}

void Core::printHelp()
{
    std::cout << "HELP PAGE FOR pInfo utility.\n";
}
