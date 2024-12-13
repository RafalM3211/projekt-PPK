#include <iostream>
#include <vector>
#include <unordered_map>

#include "./src/headers/graph.h"

Node* createInputNode(int id, State state){
    return new Node(id, state, {3});
}


int main(){
    LogicSystem logicSystem;

    Node* input1 = createInputNode(1, State::LOW);
    Node* input2 = createInputNode(2, State::HIGH);
    Node* node3 = new Node{3, {0}};
    logicSystem.addInputNode(input1);
    logicSystem.addInputNode(input2);
    logicSystem.addNode(node3);

    logicSystem.printConnections();

    node3->printInfo();
    

    int a = static_cast<int>(State::LOW);

    return 0;
}