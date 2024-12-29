#include <iostream>
#include <string>

class CliArgs{
    public:
        std::string graphFilePath;
        std::string inputStatesFilePath;
        std::string outputFilePath;
};

CliArgs* parseCliArguments(int argc, char* argv[]);

void printHelpMessage();