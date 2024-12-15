#include "./headers/logicGates.h"

bool ENTRY::canResolve(){
    if(_state==State::UNSET){
        printNodeError("Entry node has unset state. It should have state set durning initialization");
    }
    return _state!=State::UNSET;
}

bool NOT::canResolve(){
    return _inputs[0]!=State::UNSET;
}

void NOT::setNodeInput(State state){
    if(_inputs[0]==State::UNSET){
        _inputs[0]=state;
    }
    else{
        printNodeError("Input already set. NOT gate shouldn't have more than one input.");
    }
}



void AND::computeState(){
    _state=_inputs[0]==(State::HIGH && _inputs[1]==State::HIGH)? State::HIGH : State::LOW;
}

void NAND::computeState(){
    _state=_inputs[0]==(State::HIGH && _inputs[1]==State::HIGH)? State::LOW : State::HIGH;
}

void OR::computeState(){
    _state=_inputs[0]==(State::HIGH || _inputs[1]==State::HIGH)? State::HIGH : State::LOW;
}

void NOR::computeState(){
    _state=_inputs[0]==(State::HIGH || _inputs[1]==State::HIGH)? State::LOW : State::HIGH;
}

void XOR::computeState(){
    _state=_inputs[0]!=_inputs[1]? State::HIGH : State::LOW;
}

void XNOR::computeState(){
    _state=_inputs[0]!=_inputs[1]? State::LOW : State::HIGH;
}

void NOT::computeState(){
    _state=_inputs[0]==State::HIGH? State::LOW : State::HIGH;
}


