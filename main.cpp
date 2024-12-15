#include <iostream>
#include <vector>
#include <unordered_map>

#include "./src/headers/graph.h"
#include "./src/headers/logicGates.h"

int main(){
    LogicSystem logicSystem;

    ENTRY* input1 = new ENTRY(1, State::HIGH, {4, 5, 6});
    ENTRY* input2 = new ENTRY(2, State::HIGH, {4});
    ENTRY* input3 = new ENTRY(3, State::LOW, {5, 6});

    NAND* node1 = new NAND(4, {});
    NOR* node2 = new NOR(5, {});
    XNOR* node3 = new XNOR(6, {});

    logicSystem.addEntryNode(input1);
    logicSystem.addEntryNode(input2);
    logicSystem.addEntryNode(input3);
    logicSystem.addNode(node1);
    logicSystem.addNode(node2);
    logicSystem.addNode(node3);

    logicSystem.printConnections();

    node1->printInfo();
    node2->printInfo();
    node3->printInfo();

    input1->tryResolve();
    input2->tryResolve();
    input3->tryResolve();

    node1->printInfo();
    node2->printInfo();
    node3->printInfo();
    

    int a = static_cast<int>(State::LOW);

    return 0;
}