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
    shared_ptr<Transaction> prev;
public:
    Transaction();
    Transaction(string, string, int);

    string getToName() const;
    string getFromName() const;
    int getAmount() const;

    void setToName(string);
    void setFromName(string);
    void setAmount(int);

    shared_ptr<Transaction> getPrev();
};
