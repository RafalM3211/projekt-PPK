#include "./headers/graph.h"
#include "./headers/logicGates.h"

// === Logic system

void LogicSystem::createEntryNode(int id){
    std::shared_ptr<Node> entryNode(new ENTRY(id));
    addNode(entryNode);
    _entryNodes.push_back(entryNode->id);
}

void LogicSystem::createNode(std::string gate, std::vector<int> inputNodesIds, int id){
    Node* node;

    if(gate=="AND"){
        node = new AND(id, inputNodesIds);
    }
    else if(gate=="NAND"){
        node = new NAND(id, inputNodesIds);
    }
    else if(gate=="OR"){
        node = new OR(id, inputNodesIds);
    }
    else if(gate=="NOR"){
        node = new NOR(id, inputNodesIds);
    }
    else if(gate=="XOR"){
        node = new XOR(id, inputNodesIds);
    }
    else if(gate=="XNOR"){
        node = new XNOR(id, inputNodesIds);
    }
    else if(gate=="NOT"){
        node = new NOT(id, inputNodesIds);
    }

    std::shared_ptr<Node> ptr_node(node);

    addNode(ptr_node);
}

void LogicSystem::addNode(std::shared_ptr<Node> node){
    node->connectToSystemGraph(&_graph);
    _graph[node->id]=node;   
}

void LogicSystem::setEntryNodeState(int id, State state){
    std::shared_ptr<Node> node = _graph.at(id);
    node->setState(state);
}

void LogicSystem::setOutputNodeId(int id){
    _outputNodeId=id;
}

void LogicSystem::resolve(){
    std::shared_ptr<Node> outputNode=_graph.at(_outputNodeId);
    outputNode->resolve();
}

void LogicSystem::reset(){
    for(const auto& idNodePair: _graph){
        std::shared_ptr<Node> node = idNodePair.second;
        node->setState(State::UNSET);
    }
}

std::string LogicSystem::createOutputString(){
    std::stringstream outputString;
    outputString << "IN: ";

    for(const auto& entryNodeId: _entryNodes){
        State entryNodeState =  _graph.at(entryNodeId)->getState();
        outputString << entryNodeId << ":" << entryNodeState << " ";
    }

    State outputState=_graph.at(_outputNodeId)->getState();
    outputString << "OUT: " << _outputNodeId << ":" << outputState;

    return outputString.str();
}


void LogicSystem::printConnections(){
    std::cout << "connections: " << std::endl;

    for(const auto& idNodePair: _graph){
        std::cout<< "to " << idNodePair.first << ": ";
        for(auto & inputId:idNodePair.second->inputNodes){
            std::cout << inputId << " ";
        } 

        std::cout << std::endl;
    }
}

void LogicSystem::printNodesInfo(std::vector<int> nodesIds){
    std::cout << "Nodes Info: " << std::endl;

    for(const auto& id: nodesIds){
        std::shared_ptr<Node> node = _graph.at(id);

        std::cout << "Node id:  " << id << std::endl;
        std::cout << "  state: " << node->getState() << std::endl;
        std::cout << "  input nodes: ";
        for(auto & inputId:node->inputNodes){
            std::cout << inputId << " ";
        } 

        std::cout << std::endl;
    }
}

void LogicSystem::printNodesInfo(){
    std::vector<int> allIds;
    for(const auto& pair: _graph){
        allIds.push_back(pair.first);
    }
    printNodesInfo(allIds);
}

void LogicSystem::printOutput(){
    State output=_graph.at(_outputNodeId)->getState();
    std::cout << "System output: " << output << std::endl;
}


// === Node

void Node::connectToSystemGraph(Graph* graph){
    _graph=graph;
}

void Node::addInputNode(int id){
    inputNodes.push_back(id);
}

void Node::resolve(){
    std::vector<State> inputStates{};

    for(const int & id: inputNodes){
        std::shared_ptr<Node> inputNode  =_graph->at(id);
        State inputNodeState = inputNode->getState();

        if(inputNodeState==State::UNSET){
            inputNode->resolve();
            inputNodeState = inputNode->getState();
            inputStates.push_back(inputNodeState);
        }
        else{
            inputStates.push_back(inputNodeState);
        }
    }

    if(canResolve(inputStates)){
        _state = computeState(inputStates);
    }
    else{
        printNodeError("Can't resolve node. Some inputs are not resolved");
    }
    
}

State Node::getState(){
    return _state;
}

void Node::setState(State state){
    _state=state;
}

bool Node::canResolve(const std::vector<State>& inputStates){
    return inputStates[0]!=State::UNSET && inputStates[1]!=State::UNSET;
}


void Node::printInfo(){
    std::cout << "Node: " << id << " State: " << _state << "\n Input nodes: \n";
    for(const int& inputNodeId: inputNodes){
            std::cout << "id: " << inputNodeId << ", state: " << _graph->at(inputNodeId)->getState() << std::endl;
    }
    std::cout << std::endl;
}

void Node::printNodeError(std::string text){
    std::cerr << "Error in node with id: " << id << std::endl << text << std::endl;
}

