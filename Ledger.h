//
// Created by rodho on 2/25/2022.
//

#include "Node.h"
#include "Transaction.h"
#include "State.h"
#include <iostream>
using namespace std;

class Ledger {
private:
    string toName;
    string fromName;
    int amount{};
    vector<pair<string, int>> ledgerVector;
    shared_ptr<Node> endPtr;
    int count{};
public:
    Ledger();

    Ledger operator+=(Transaction);
    Ledger operator=(shared_ptr<Transaction>);
    void Add(Transaction);

};