//
// Created by rodho on 2/25/2022.
//

#include "Node.h"
#include "Transaction.h"
#include "State.h"
#include <iostream>
#include <sstream>
using namespace std;

class Ledger {
private:
    string toName;
    string fromName;
    int amount;
    map<string, int> ledgerVector;
    shared_ptr<Node> endPtr;
    int count = 0;
public:
    Ledger();


    Ledger& operator+=(Transaction);
    Ledger& operator-=(Transaction);
    void Add(Transaction);
    friend ostream& operator<<(ostream& os, const Ledger&);
    void Clear();
    void Settle();
    void inTheBlack();
    void inTheRed();
};