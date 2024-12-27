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
        int _outputNodeId;
    public:
        void printConnections();
        void addNode(Node*);
        void addEntryNode(Node*);
        void setOutputNodeId(int);
        void printOutput();
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
        virtual bool canResolve();
    public:
        const int id;
        std::vector<int> inputNodes;

        virtual void setNodeInput(State);
        void addOutputNode(int);
        void connectToSystemGraph(Graph*);
        void printInfo();
        void tryResolve();
        State getState();

        Node(int nodeId): id(nodeId){};
        Node(int nodeId, State outState)
        : id(nodeId), _state(outState){};
};

#endif