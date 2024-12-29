#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <string>

#include "./src/headers/graph.h"
#include "./src/headers/logicGates.h"
#include "./src/headers/filesHandlers.h"

int main(){


    std::ifstream graph_structure_file("./data/graph_structure.txt");
    std::ifstream inputs_states_file("./data/inputs_states.txt");
    std::ofstream output_file("./data/outputs.txt");

    if(!graph_structure_file){
        std::cerr << "couldn't open graph structure file" << std::endl;
    }
    else if(!inputs_states_file){
        std::cerr << "couldn't open inputs states file" << std::endl;
    }
    else if(!output_file){
        std::cerr << "couldn't open output file" << std::endl;
    }
    else{
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

        logicSystem.setEntryNodeState(1, State::LOW);
        logicSystem.setEntryNodeState(6, State::LOW);

        logicSystem.resolve();
        
    }

    return 0;
}