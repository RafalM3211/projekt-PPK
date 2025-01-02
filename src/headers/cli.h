#include <iostream>
#include <string>


/**
 * @brief Przeowuje wartości przełączników -u -o -i lini poleceń
  */

class CliArgs{
    public:
        std::string graphFilePath;
        std::string inputStatesFilePath;
        std::string outputFilePath;
};

/**
 * @brief Parsuje przełączniki podawane w lini poleceń. Zwraca wyjątek gdy któregoś brakuje
 * @param argc ilośc argumentów
 * @param argv tablica stringów w stylu C zawierająca argumenty lini poleceń
 * @return obiekt klasy CliArgs zawierający wartości przełączników -i -u -o
  */

CliArgs* parseCliArguments(int argc, char* argv[]);

/// @brief Wypisuje pomoc do strumienia wyjścia
void printHelpMessage();