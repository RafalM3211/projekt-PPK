#ifndef LOGIC_GATES
#define LOGIC_GATES

#include "./graph.h"

class ENTRY: public Node{
    public:
        using Node::Node;
};

class AND: public Node {
    private:
        State computeState(std::vector<State>) override;
    public:
        using Node::Node;
};

class NAND: public Node {
    private:
        State computeState(std::vector<State>) override;
    public:
        using Node::Node;
};

class OR: public Node {
    private:
        State computeState(std::vector<State>) override;
    public:
        using Node::Node;
};

class NOR: public Node {
    private:
        State computeState(std::vector<State>) override;
    public:
        using Node::Node;
};

class XOR: public Node {
    private:
        State computeState(std::vector<State>) override;
    public:
        using Node::Node;
};

class XNOR: public Node {
    private:
        State computeState(std::vector<State>) override;
    public:
        using Node::Node;
};

class NOT: public Node {
    private:
        State computeState(std::vector<State>) override;
    public:
        using Node::Node;
};



#endif