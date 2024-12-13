#include <iostream>
#include <vector>
#include <unordered_map>

#include "./src/headers/graph.h"


int main(){
    LogicSystem logicSystem;

    ENTRY* input1 = new ENTRY(1, State::HIGH, {3});
    ENTRY* input2 = new ENTRY(2, State::HIGH, {3});

    AND* node3 = new AND(3, {});
    logicSystem.addInputNode(input1);
    logicSystem.addInputNode(input2);
    logicSystem.addNode(node3);

    logicSystem.printConnections();

    input1->tryResolve();
    input2->tryResolve();

    node3->printInfo();
    node3->tryResolve();
    node3->printInfo();
    

    int a = static_cast<int>(State::LOW);

    return 0;
}