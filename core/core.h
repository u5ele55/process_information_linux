#pragma once

#include <vector>
#include <string>

class Core {
public:
    Core(int argc, char *argv[]);
    void start();
private:
    void printHelp();
private:
    int inputSize;
    std::vector<std::string> input;
};