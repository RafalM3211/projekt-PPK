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
        /* 
        std::vector<int> entryNodesIds = parseInputsLine(graph_structure_file);
        for(const int & id: entryNodesIds){
            ENTRY* entryNode = new ENTRY(id);
            logicSystem.addEntryNode(entryNode);
        }

        int outputNodeId = parseOutputLine(graph_structure_file);
        logicSystem.setOutputNodeId(outputNodeId);
  */

        ENTRY* input1 = new ENTRY(1, State::HIGH);

        ENTRY* input2 = new ENTRY(2, State::HIGH);

        //ENTRY* input3 = new ENTRY(3, State::LOW);

        AND* node1 = new AND(4);
        node1->addInputNode(1);
        node1->addInputNode(2);

        //OR* node2 = new OR(5);

        //XOR* node3 = new XOR(6);
        //OR* node4 = new OR(7);
       // node4->addInputNode(8);

        //NOT* node5 = new NOT(8);

        logicSystem.addEntryNode(input1);
        logicSystem.addEntryNode(input2);
        //logicSystem.addEntryNode(input3);
        logicSystem.addNode(node1);
       /*  logicSystem.addNode(node2);
        logicSystem.addNode(node3);
        logicSystem.addNode(node4);
        logicSystem.addNode(node5); */

        logicSystem.setOutputNodeId(node1->id);

        logicSystem.printConnections();

        node1->printInfo();

        node1->tryResolve();

        node1->printInfo();

        logicSystem.printOutput();

       /*  input1->printInfo();
        node1->printInfo();
        node2->printInfo();
        node3->printInfo();
        node4->printInfo();
        node5->printInfo();

        input1->tryResolve();
        input2->tryResolve();
        input3->tryResolve();

        node1->printInfo();
        node2->printInfo();
        node3->printInfo();
        node4->printInfo();
        node5->printInfo();
        
        logicSystem.printOutput(); */
    }


    int a = static_cast<int>(State::LOW);

    return 0;
}