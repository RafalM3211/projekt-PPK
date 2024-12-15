#ifndef LOGIC_GATES
#define LOGIC_GATES

#include "./graph.h"

class ENTRY: public Node{
    public:
        using Node::Node;
        bool canResolve() override;
};

class AND: public Node {
    private:
        void computeState() override;
    public:
        using Node::Node;
};

class NAND: public Node {
    private:
        void computeState() override;
    public:
        using Node::Node;
};

class OR: public Node {
    private:
        void computeState() override;
    public:
        using Node::Node;
};

class NOR: public Node {
    private:
        void computeState() override;
    public:
        using Node::Node;
};

class XOR: public Node {
    private:
        void computeState() override;
    public:
        using Node::Node;
};

class XNOR: public Node {
    private:
        void computeState() override;
    public:
        using Node::Node;
};

class NOT: public Node {
    private:
        void computeState() override;
        bool canResolve() override;
        void setNodeInput(State state) override;
    public:
        using Node::Node;
};



#endif