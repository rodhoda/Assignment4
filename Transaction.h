//
// Created by rodho on 2/22/2022.
//

#pragma once
#include "Node.h"
using namespace std;

// Base #1: Transaction Node Class
class Transaction: public Node {
private:
    string toName;
    string fromName;
    int amount{};
public:
    Transaction();
    Transaction(string, string, int);


    string getToName() const;
    string getFromName() const;
    int getAmount() const;

    void setToName(string);
    void setFromName(string);
    void setAmount(int);

    shared_ptr<Node> getPrev();
    void setPrev(shared_ptr<Transaction>);
    bool operator==(shared_ptr<Transaction>);


    void print();
};
