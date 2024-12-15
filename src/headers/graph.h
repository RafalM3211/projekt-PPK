#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <unordered_map>


enum State {
    LOW,
    HIGH,
    UNSET,
};

class Node;

using Graph = std::unordered_map<int, Node*>;

class LogicSystem{
    private:
        Graph _graph;
        std::vector<int> _startNodes;
    public:
        void printConnections();
        void addNode(Node*);
        void addEntryNode(Node*);
};

class Node{
    protected:
        Graph* _graph=nullptr;
        State _inputs[2]={State::UNSET, State::UNSET};
        State _state=State::UNSET;

        void setNextNodesInput();
        void printNodeError(std::string);
        void tryResolveNextNodes();
        virtual void computeState(){};
    public:
        virtual bool canResolve();
        int id;
        std::vector<int> outputNodes;
        void setNodeInput(State);
        void connectToSystemGraph(Graph*);
        void printInfo();
        void tryResolve();
        Node(int nodeId, std::vector<int> outNodes){id=nodeId, outNodes=outNodes;};
        Node(int nodeId, State outState, std::vector<int> outNodes={})
        : id(nodeId), _state(outState), outputNodes(outNodes) {};
};

#endif