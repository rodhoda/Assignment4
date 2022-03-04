//
// Created by rodho on 2/22/2022.
//

#include "State.h"

State::State() {
    nodeType = "STATE";
}

State::State(map<string, int>  newMap): ledgerSummary(newMap) {
    nodeType = "STATE";
}

map<string, int> State::getLedger() {
    return ledgerSummary;
}

void State::setLedger(map<string, int> newLedger) {
    ledgerSummary = newLedger;
}

