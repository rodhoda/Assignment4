//
// Created by rodho on 2/22/2022.
//

#include "Node.h"
#include <map>
#pragma once

//Base #2: State Node Class
class State: public Node {
private:
    // This will hold a pair of string and int that will be each
    // account member and their balance
    map<string, int> ledgerSummary;
public:
    State();
    State(map<string, int>);

    map<string, int> getLedger();
    void setLedger(map<string, int>);
};
