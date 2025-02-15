#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

#include "./src/headers/graph.h"
#include "./src/headers/logicGates.h"
#include "./src/headers/filesHandlers.h"
#include "./src/headers/cli.h"

int main(int argc, char* argv[]){
    try{
        CliArgs* arguments = parseCliArguments(argc, argv);

        std::ifstream graph_structure_file(arguments->graphFilePath);
        std::ifstream inputs_states_file(arguments->inputStatesFilePath);
        std::ofstream output_file(arguments->outputFilePath);

        if(!graph_structure_file){
            throw std::string("couldn't open graph structure file with given path: " + arguments->graphFilePath);
        }
        if(!inputs_states_file){
            throw std::string("couldn't open inputs states file with given path: " + arguments->inputStatesFilePath);
        }
        if(!output_file){
            throw std::string("couldn't open output file with given path: " + arguments->outputFilePath);
        }


        LogicSystem logicSystem;
            
        std::vector<int> entryNodesIds = parseInputsLine(graph_structure_file);
        for(const int & id: entryNodesIds){
            logicSystem.createEntryNode(id);
        }

        int outputNodeId = parseOutputLine(graph_structure_file);
        logicSystem.setOutputNodeId(outputNodeId);

        std::stringstream line=getLineToStringStream(graph_structure_file);
        while(!line.str().empty()) {
            std::string gateName;
            line >> gateName;

            std::vector<int> inputNodesIds;
            int inputNodeId;
            while(line >> inputNodeId){
                inputNodesIds.push_back(inputNodeId);
            }

            int thisNodeId = inputNodesIds.back();
            inputNodesIds.pop_back();
            
            logicSystem.createNode(gateName, inputNodesIds, thisNodeId);
            
            line=getLineToStringStream(graph_structure_file);
        };

        line=getLineToStringStream(inputs_states_file);
        while(!line.str().empty()){
            std::string inputStateString;
            while(line>>inputStateString){
                std::pair<int, State> input = getInputIdAndStateFromString(inputStateString);
                logicSystem.setEntryNodeState(input.first, input.second);
            }

            logicSystem.resolve();

            std::string outputString = logicSystem.createOutputString();
            writeToOutputFile(output_file, outputString);

            logicSystem.reset();

            line=getLineToStringStream(inputs_states_file);
        }
    }
    catch(std::string text){
        std::cerr << text << std::endl;
    }

    return 0;
}