#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <sstream>

/// @brief Reprezentuje stan logiczny
enum State {
    LOW,
    HIGH,
    UNSET,
};

class Node;

using Graph = std::unordered_map<int, std::shared_ptr<Node>>;

/// @brief Zawiera informacje o układzie logicznym oraz metody do obliczania jego stanu
class LogicSystem{
    private:
        Graph _graph;
        std::vector<int> _entryNodes;
        int _outputNodeId;

        /// @brief Dodaje węzeł do układu
        /// @param  Wskaźnik do węzła
        void addNode(std::shared_ptr<Node>);
    public:
        /// @brief Tworzy węzeł wejściowy i dodaje do układu
        /// @param id Id węzła
        void createEntryNode(int);

        /// @brief Tworzy węzeł (bramkę logiczną) i dodaje do układu
        /// @param  gate Typ bramki logicznej. Np "AND", "XOR" itd.
        /// @param  inputNodesIds Wekror zawierający id węzłów, które wchodzą do tworzonego węzła
        /// @param  id Id tworzonego węzła
        void createNode(std::string, std::vector<int>, int);

        /// @brief Ustawia węzeł jako węzeł wyjściowy uładu
        /// @param  id Id węzła
        void setOutputNodeId(int);

        /// @brief Ustawia stan węzła wejściowego
        /// @param  id Id węzła
        /// @param  state Stan węzła
        void setEntryNodeState(int, State);

        /// @brief Oblicza stan układu. Po wykonaniu zostają obliczane stany wszystkich węzłów układu. Stan wyjściowy układu to stan węzła ustawionego jako wyjściowy.
        void resolve();

        /// @brief Resetuje stan układu. Po wykonaniu wszystkie węzły mają stan nieustalony
        void reset();

        /// @brief Tworzy string z informacją o stanie wyjściowym układu oraz stanie wejść.
        /// @return String w formacie 'IN: <id_wezła_wejściowego>:<stan> <id_wezła_wejściowego>:<stan> ... OUT: <id_wezła_wejściowego>:<stan>'
        std::string createOutputString();

        /// @brief Wypisuje połączenia węzłów w układzie. Służy do debugowania
        void printConnections();

        /// @brief Wypisuje id węzłów wejściowych, stan i id podanych węzłów. Służy do debugowania
        /// @param  nodesIds Wektor zawierający id węzłów, dla których informacje są wypisywane
        void printNodesInfo(std::vector<int>);

        /// @brief Wypisuje id węzłów wejściowych, stan i id wszystkich węzłów. Służy do debugowania
        void printNodesInfo();
        
        /// @brief Wypisuje stan wyjściowy układu. Służy do debugowania
        void printOutput();
};

/// @brief Reprezentuje węzeł (Bramkę logiczną) w układzie logicznym. Ta klasa jest abstrakcyjna. Węzły reprezentujące konkretną bramkę są tworzone za pomocą klas dziedziczących od tej
class Node{
    protected:
        Graph* _graph=nullptr;
        State _state=State::UNSET;

        /// @brief Oblicza stan węzła
        /// @param inputStates Wektor stanów wejściowych
        /// @return Stan węzła
        virtual State computeState(const std::vector<State>&){return State::UNSET;};

        /// @brief Sprawdza czy można obliczyć stan węzła
        /// @param  inputStates wektor stanów wejściowych
        /// @return Prawda lub fałsz w zależności czy wejścia mają stan ustalony
        virtual bool canResolve(const std::vector<State>&);

        /// @brief Wypisuje błąd węzła
        /// @param  text Tekst błędu
        void printNodeError(std::string);
    public:
        const int id;
        std::vector<int> inputNodes;

        /// @brief Łączy węzeł z układem logicznym. Ustawia graf węzła na graf układu
        /// @param graph Graf układu logicznego (jego wartość _graph)
        void connectToSystemGraph(Graph*);

        /// @brief Dodaje węzeł wejściowy do aktualnego węzła
        /// @param  id Id węzła wejściowego
        void addInputNode(int);
        
        /// @brief Rozwiązuje węzeł. Jeśli węzły wejściowe mają stan ustalony ustawia stan węzła. W przeciwnym wypadku przed ustawieniem stanu rozwiązuje węzły wejściowe
        void resolve();

        /// @brief Pobiera stan węzła
        /// @return Stan węzła
        State getState();

        /// @brief Ustawia stan węzłą
        /// @param  state Stan 
        void setState(State);

        /// @brief Wypisuje informacje o węźle. Jego id, stan, węzły wejściowe oraz ich stany
        void printInfo();

        /// @brief Tworzy obiekt węzła. Służy do tworzenia obiektów bramek logicznych
        /// @param nodeId Id węzła
        /// @param inputNodesIds Id węzłów wejściowych
        Node(int nodeId, std::vector<int> inputNodesIds): id(nodeId), inputNodes(inputNodesIds){};

        /// @brief Tworzy obiekt węzła. Służy do tworzenia obiektu węzła wejściowego układu
        /// @param nodeId Id węzła
        Node(int nodeId)
        : id(nodeId){};
};

#endif