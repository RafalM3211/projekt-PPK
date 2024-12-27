#include "./headers/graph.h"

// === Logic system

void LogicSystem::addEntryNode(Node* node){
    addNode(node);
    _startNodes.push_back(node->id);
}

void LogicSystem::addNode(Node* node){
    node->connectToSystemGraph(&_graph);
    _graph[node->id]=node;   
}

void LogicSystem::setOutputNodeId(int id){
    _outputNodeId=id;
}

void LogicSystem::printConnections(){
    std::cout << "connections: " << std::endl;

    for(auto& pair:_graph){
        std::cout<< "to " << pair.first << ": ";
        for(auto & inputId:pair.second->inputNodes){
            std::cout << inputId << " ";
        } 

        std::cout << std::endl;
    }
}

void LogicSystem::printOutput(){
    State output=_graph.at(_outputNodeId)->getState();
    std::cout << "System output: " << output;
}


// === Node

void Node::connectToSystemGraph(Graph* graph){
    _graph=graph;
}

void Node::addInputNode(int id){
    inputNodes.push_back(id);
}

void Node::tryResolve(){
    std::vector<State> inputStates{};

    for(const int & id: inputNodes){
        Node* inputNode  =_graph->at(id);
        State inputNodeState = inputNode->getState();

        if(inputNodeState!=State::UNSET){
            inputStates.push_back(inputNodeState);
        }
        else{
            inputNode->tryResolve();
            inputNodeState = inputNode->getState();
            inputStates.push_back(inputNodeState);
        }
    }

    _state = computeState(inputStates);
}

State Node::getState(){
    return _state;
}


/* void Node::printInfo(){
    std::cout<< "id: " << id << "\n inputs states: " << _inputs[0] << " " << _inputs[1] << "\n state: " << _state << "\n output nodes: ";
    for(const int& nextNodeId: outputNodes){
            std::cout << nextNodeId << ", ";
    }
    std::cout << std::endl;
} */

void Node::printNodeError(std::string text){
    std::cerr << "Error in node with id: " << id << std::endl << text << std::endl;
}

