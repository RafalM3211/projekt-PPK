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
        void addEntryNode(Node*); 
        void addNode(Node*);
        void setOutputNodeId(int);
        void printConnections();
        void printOutput();
};

class Node{
    protected:
        Graph* _graph=nullptr;
        State _inputs[2]={State::UNSET, State::UNSET};
        State _state=State::UNSET;

        virtual State computeState(std::vector<State>){return State::UNSET;};
        virtual bool canResolve(std::vector<State>);
        void printNodeError(std::string);
    public:
        const int id;
        std::vector<int> inputNodes;

        void connectToSystemGraph(Graph*);
        void addInputNode(int);
        void tryResolve();
        State getState();
        void printInfo();

        Node(int nodeId): id(nodeId){};
        Node(int nodeId, State outState)
        : id(nodeId), _state(outState){};
};

#endif