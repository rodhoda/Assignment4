//
// Created by rodho on 2/22/2022.
//

#include "Node.h"
#pragma once

//Base #2: State Node Class
class State: public Node {
private:
    // This will hold a pair of string and int that will be each
    // account member and their balance
    vector<pair<string, int>> ledgerSummary;
    shared_ptr<State> next;
public:
    State();
    State(vector<pair<string, int>>);

    vector<pair<string, int>> getLedger();
    shared_ptr<State> getNext();
};
