#include "./headers/graph.h"

void LogicSystem::printConnections(){
    for(auto& pair:_graph){
        std::cout<< "from " << pair.first << ": ";
        for(auto & nextId:pair.second->outputNodes){
            std::cout << nextId << " ";
        } 

        std::cout << std::endl;
    }
}

void LogicSystem::addNode(Node* node){
    node->connectToSystemGraph(&_graph);
    _graph[node->id]=node;   
}

void LogicSystem::addEntryNode(Node* node){
    addNode(node);
    _startNodes.push_back(node->id);
}

void Node::connectToSystemGraph(Graph* graph){
    _graph=graph;
}

void Node::setNodeInput(State state){
    if(_inputs[0]==State::UNSET){
        _inputs[0]=state;
    }
    else if(_inputs[1]==State::UNSET){
        _inputs[1]=state;
    }
    else{
        printNodeError("all two inputs already set");
    }
}

void Node::setNextNodesInput(){
    if(_state!=State::UNSET){
        for(const int& nextNodeId: outputNodes){
            Node* nextNode = _graph->at(nextNodeId);
            nextNode->setNodeInput(_state);
        }
    }
    else{
        printNodeError("attemt to set next node input without resolving current node.");
    }
}

void Node::printInfo(){
    std::cout<< "id: " << id << "\n inputs: " << _inputs[0] << " " << _inputs[1] << "\n state: " << _state << "\n output nodes: ";
    for(const int& nextNodeId: outputNodes){
            std::cout << nextNodeId << ", ";
    }
    std::cout << std::endl;
}

void Node::printNodeError(std::string text){
    std::cerr << "Error in node with id: " << id << std::endl << text << std::endl;
}


bool Node::canResolve(){
    return _inputs[0]!=State::UNSET && _inputs[1]!=State::UNSET;
}

void Node::tryResolveNextNodes(){
    for(const int& nextNodeId: outputNodes){
            Node* nextNode = _graph->at(nextNodeId);
            nextNode->tryResolve();
        }
}

void Node::tryResolve(){
    if(canResolve()){
        computeState();
        setNextNodesInput();
        tryResolveNextNodes();
    }
}


bool ENTRY::canResolve(){
    if(_state==State::UNSET){
        printNodeError("Entry node has unset state. It should have state set durning initialization");
    }
    return _state!=State::UNSET;
}

void AND::computeState(){
    _state=_inputs[0]==(State::HIGH && _inputs[1]==State::HIGH)? State::HIGH : State::LOW;
}