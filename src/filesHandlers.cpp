#include "./headers/filesHandlers.h"

void printParsingError(std::string text){
    std::cout << "Error while parsing file. " << text << std::endl;
}

std::stringstream getLineToStringStream(std::ifstream & file){
    std::string line;
    std::getline(file, line);

    std::stringstream lineStream;
    lineStream << line;

    return lineStream;
}

std::vector<int> parseInputsLine(std::ifstream & graph_structure_file){
    std::stringstream lineStream = getLineToStringStream(graph_structure_file);

    std::string signature="";
    lineStream >> signature;

    std::vector<int> inputNodesIds{};

    if(signature=="IN:"){
        int id;
        while(lineStream>>id){
            inputNodesIds.push_back(id);
        }
    }
    else{
        printParsingError("Inputs line should start with 'IN:'");
    }

    return inputNodesIds;
}

int parseOutputLine(std::ifstream & graph_structure_file){
    std::stringstream lineStream = getLineToStringStream(graph_structure_file);

    std::string signature="";
    lineStream >> signature;

    int outputNodeId=0;

    if(signature=="OUT:"){
        lineStream >> outputNodeId;
    }
    else{
        printParsingError("Output line should start with 'OUT:'");
    }

    return outputNodeId;
}