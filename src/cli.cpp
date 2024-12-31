#include "./headers/cli.h"

CliArgs* parseCliArguments(int argc, char* argv[]){
    CliArgs* arguments = new CliArgs();

    for(int i=1; i<argc; i++){
        std::string argument = argv[i];

        if(argument=="-u"){
            arguments->graphFilePath=argv[++i];
        }
        else if(argument=="-i"){
            arguments->inputStatesFilePath=argv[++i];
        }
        else if(argument=="-o"){
            arguments->outputFilePath=argv[++i];
        }
        else if(argument=="--help"){
            printHelpMessage();
            throw std::string();
        }
        else{
            throw std::string("Unknown argument '" + argument + "'");
        }
    }

    bool allNecessaryFlagsSet = !arguments->graphFilePath.empty() && !arguments->inputStatesFilePath.empty() && !arguments->outputFilePath.empty();
    if(!allNecessaryFlagsSet){
        printHelpMessage();
        throw std::string();
    }

    return arguments;
}

void printHelpMessage(){
    std::cerr << "help message" << std::endl;
}