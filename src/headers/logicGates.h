#ifndef LOGIC_GATES
#define LOGIC_GATES

#include "./graph.h"

class ENTRY: public Node{
    public:
        using Node::Node;
};

class AND: public Node {
    private:
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        State computeState(const std::vector<State>&) override;
    public:
        using Node::Node;
};

class NAND: public Node {
    private:
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        State computeState(const std::vector<State>&) override;
    public:
        using Node::Node;
};

class OR: public Node {
    private:
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        State computeState(const std::vector<State>&) override;
    public:
        using Node::Node;
};

class NOR: public Node {
    private:
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        State computeState(const std::vector<State>&) override;
    public:
        using Node::Node;
};

class XOR: public Node {
    private:
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        State computeState(const std::vector<State>&) override;
    public:
        using Node::Node;
};

class XNOR: public Node {
    private:
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        State computeState(const std::vector<State>&) override;
    public:
        using Node::Node;
};

class NOT: public Node {
    private:
        /// @brief Oblicza stan węzła
        /// @param  inputStates Wektor stanów wejściowych. Wektor powinien zawierać tylko jeden element. W przeciwnym wypadku nie zwróci błędu ale obliczy stan tylko na podstawie pierwszego stanu wejściowego
        /// @return Stan węzła
        State computeState(const std::vector<State>&) override;

        /// @brief Sprawdza czy można obliczyć stan węzła
        /// @param  inputStates wektor stanów wejściowych. Wypisuje błąd gdy zawiera więcej niż jeden element
        /// @return Prawda lub fałsz w zależności czy wejście maj stan ustalony
        bool canResolve(const std::vector<State>&) override;
    public:
        using Node::Node;
};



#endif