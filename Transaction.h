//
// Created by rodho on 2/22/2022.
//
#include "Node.h"
#pragma once

// Base #1: Transaction Node Class
class Transaction: public Node {
private:
    string toName;
    string fromName;
    int amount;
    shared_ptr<Transaction> next;
public:
    Transaction();
    Transaction(string, string, int);

    string getToName() const;
    string getFromName() const;
    shared_ptr<Transaction> getNext();
};
