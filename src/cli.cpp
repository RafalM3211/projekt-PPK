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
    std::string helpMessage = 
    "Usage: main.exe [OPTIONS] \n\n"
    
    "Options:\n"
    "-u <file>       Specify the input file containing the logic system.\n"
    "-i <file>       Specify the input file containing the input states.\n"
    "-o <file>       Specify the output file for the output states.\n"
    "--help          Display this help message and exit.\n\n"

    "Example: \n"
    "\t program_name -u system.txt -i inputs.txt -o outputs.txt";
    std::cerr << helpMessage << std::endl;
}