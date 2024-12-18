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

    AND* node1 = new AND(4, {7});
    OR* node2 = new OR(5, {7});
    XOR* node3 = new XOR(6, {});
    OR* node4 = new OR(7, {8});
    NOT* node5 = new NOT(8, {});

    logicSystem.addEntryNode(input1);
    logicSystem.addEntryNode(input2);
    logicSystem.addEntryNode(input3);
    logicSystem.addNode(node1);
    logicSystem.addNode(node2);
    logicSystem.addNode(node3);
    logicSystem.addNode(node4);
    logicSystem.addNode(node5);

    logicSystem.setOutputNodeId(node5->id);

    logicSystem.printConnections();

    input1->printInfo();
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
    
    logicSystem.printOutput();

    int a = static_cast<int>(State::LOW);

    return 0;
}