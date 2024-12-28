#include "./headers/logicGates.h"


void ENTRY::setState(State state){
    _state=state;
}

bool NOT::canResolve(const std::vector<State>& inputStates){
    if(inputStates.size()>1){
        printNodeError("Not gate should have only one input but has " + std::to_string(inputStates.size()));
    }
    return inputStates[0]!=State::UNSET;
}


State AND::computeState(const std::vector<State>& inputStates){
    State state=(inputStates[0]==State::HIGH && inputStates[1]==State::HIGH)? State::HIGH : State::LOW;

    return state;
}

State NAND::computeState(const std::vector<State>& inputStates){
    State state=(inputStates[0]==State::HIGH && inputStates[1]==State::HIGH)? State::LOW : State::HIGH;

    return state;
}

State OR::computeState(const std::vector<State>& inputStates){
    State state=(inputStates[0]==State::HIGH || inputStates[1]==State::HIGH)? State::HIGH : State::LOW;

    return state;
}

State NOR::computeState(const std::vector<State>& inputStates){
    State state=(inputStates[0]==State::HIGH || inputStates[1]==State::HIGH)? State::LOW : State::HIGH;

    return state;
}

State XOR::computeState(const std::vector<State>& inputStates){
    State state=inputStates[0]!=inputStates[1]? State::HIGH : State::LOW;

    return state;
}

State XNOR::computeState(const std::vector<State>& inputStates){
    State state=inputStates[0]!=inputStates[1]? State::LOW : State::HIGH;

    return state;
}

State NOT::computeState(const std::vector<State>& inputStates){
    State state=inputStates[0]==State::HIGH? State::LOW : State::HIGH;

    return state;
}


