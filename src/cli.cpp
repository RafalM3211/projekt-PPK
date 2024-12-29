#include "./headers/cli.h"

CliArgs* parseCliArguments(int argc, char* argv[]){
    CliArgs* arguments = new CliArgs();

    for(int i=1; i<argc; i++){
        std::cout << argv[i] << " " << argv[i+1] << std::endl;
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
        else{
            printHelpMessage();
            break;
        }
    }

    return arguments;
}

void printHelpMessage(){
    std::cerr << "help message" << std::endl;
}