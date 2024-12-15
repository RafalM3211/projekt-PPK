#ifndef LOGIC_GATES
#define LOGIC_GATES

#include "./graph.h"

class ENTRY: public Node{
    public:
        using Node::Node;
        bool canResolve() override;
};

class AND: public Node {
    public:
        using Node::Node;
        void computeState() override;
};

class NAND: public Node {
    public:
        using Node::Node;
        void computeState() override;
};

class OR: public Node {
    public:
        using Node::Node;
        void computeState() override;
};

class NOR: public Node {
    public:
        using Node::Node;
        void computeState() override;
};

class XOR: public Node {
    public:
        using Node::Node;
        void computeState() override;
};

class XNOR: public Node {
    public:
        using Node::Node;
        void computeState() override;
};

class NEG: public Node {
    public:
        using Node::Node;
        void computeState() override;
};



#endif