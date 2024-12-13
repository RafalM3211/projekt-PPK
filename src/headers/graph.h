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
        void addInputNode(Node*);
        LogicSystem();
};

class Node{
    protected:
        Graph* _graph=nullptr;
        State _inputs[2]={State::UNSET, State::UNSET};
        State _state=State::UNSET;
        
    public:
        const int id;
        std::vector<int> outputNodes;
        void setInput(State);
        void setNextNodesInput();
        void connectToSystemGraph(Graph* graph);
        void canResolve();
        void printInfo();
        Node(int nodeId, std::vector<int> outNodes={})
        : id(nodeId), outputNodes(outNodes) {};
        Node(int nodeId, State outState, std::vector<int> outNodes={})
        : id(nodeId), _state(outState), outputNodes(outNodes) {}
};

class AND: public Node {
    public:
        void tryResolve();
}