#ifndef FILES_HANDLERS
#define FILES_HANDLERS

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

#include "graph.h"

/// @brief Pobiera linię z pliku i zamienia na stringstream
/// @param file Strumień wejściowy z pliku
/// @return Stringstream z lini z pliku
std::stringstream getLineToStringStream(std::ifstream &);

/// @brief Parsuje linię wejść z pliku 
/// @param graph_structure_file Plik z układem bramek logicznych
/// @return Wektor zawierający id węzłów wejściowych
std::vector<int> parseInputsLine(std::ifstream &);

/// @brief Parsuje linię wyjścia z pliku
/// @param  graph_structure_file Plik z układem bramek logicznych
/// @return Id węzła wyjściowego
int parseOutputLine(std::ifstream &);

/// @brief Pobiera id węzła wejściowego i jego stan z string
/// @param  inputStateString String zawierający id węzła i jego stan. Powinien mieć format <id_węzła>:<stan>. Taki string jest wyciągany z pliku stanów wejść
/// @return Para, której pierwszą częścią jest id węzła a drugą jego stan
std::pair<int, State> getInputIdAndStateFromString(std::string);

/// @brief Wypisuje zawartość podanego stringa do pliku
/// @param  file Strumień wyjściowy pliku
/// @param  text String, który będzie wpisany do pliku
void writeToOutputFile(std::ofstream &, std::string);

#endif