#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <sstream>

enum State {
    LOW,
    HIGH,
    UNSET,
};

class Node;

using Graph = std::unordered_map<int, std::shared_ptr<Node>>;

class LogicSystem{
    private:
        Graph _graph;
        std::vector<int> _startNodes;       //todo: change name to _entryNodes
        int _outputNodeId;
        void addNode(std::shared_ptr<Node>);
    public:
        void createEntryNode(int);
        void createNode(std::string, std::vector<int>, int);
        void setOutputNodeId(int);
        void setEntryNodeState(int, State);
        void resolve();
        void reset();
        std::string createOutputString();

        void printConnections();
        void printNodesInfo(std::vector<int>);
        void printNodesInfo();
        void printOutput();
};

class Node{
    protected:
        Graph* _graph=nullptr;
        State _state=State::UNSET;

        virtual State computeState(const std::vector<State>&){return State::UNSET;};
        virtual bool canResolve(const std::vector<State>&);
        void printNodeError(std::string);
    public:
        const int id;
        std::vector<int> inputNodes;

        void connectToSystemGraph(Graph*);
        void addInputNode(int);
        void resolve();
        State getState();
        void setState(State);
        void printInfo();

        Node(int nodeId, std::vector<int> inputNodesIds): id(nodeId), inputNodes(inputNodesIds){};
        Node(int nodeId)
        : id(nodeId){};
};

#endif