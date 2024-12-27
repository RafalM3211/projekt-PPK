#include "./headers/logicGates.h"



State AND::computeState(std::vector<State>){
    _state=_inputs[0]==(State::HIGH && _inputs[1]==State::HIGH)? State::HIGH : State::LOW;
    return State::UNSET;
}

State NAND::computeState(std::vector<State>){
    _state=_inputs[0]==(State::HIGH && _inputs[1]==State::HIGH)? State::LOW : State::HIGH;
    return State::UNSET;
}

State OR::computeState(std::vector<State>){
    _state=_inputs[0]==(State::HIGH || _inputs[1]==State::HIGH)? State::HIGH : State::LOW;
    return State::UNSET;
}

State NOR::computeState(std::vector<State>){
    _state=_inputs[0]==(State::HIGH || _inputs[1]==State::HIGH)? State::LOW : State::HIGH;
    return State::UNSET;
}

State XOR::computeState(std::vector<State>){
    _state=_inputs[0]!=_inputs[1]? State::HIGH : State::LOW;
    return State::UNSET;
}

State XNOR::computeState(std::vector<State>){
    _state=_inputs[0]!=_inputs[1]? State::LOW : State::HIGH;
    return State::UNSET;
}

State NOT::computeState(std::vector<State>){
    _state=_inputs[0]==State::HIGH? State::LOW : State::HIGH;
    return State::UNSET;
}


