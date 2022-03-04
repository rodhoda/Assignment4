//
// Created by rodho on 2/22/2022.
//

#include "Transaction.h"
#include <string>
#include <iostream>

Transaction::Transaction() {
    nodeType = "TRANSACTION";
};

Transaction::Transaction(string newName, string newFromName, int newAmount): toName(newName),
                                                                             fromName(newFromName),
                                                                             amount(newAmount)
{
    nodeType = "TRANSACTION";
    prev = nullptr;
}


string Transaction::getToName() const {
    return toName;
}
string Transaction::getFromName() const {
    return fromName;
}
int Transaction::getAmount() const {
    return amount;
}

void Transaction::setToName(string newToName) {
    toName = move(newToName);
}
void Transaction::setFromName(string newFromName) {
    fromName = move(newFromName);
}

void Transaction::setAmount(int newAmount) {
    amount = newAmount;
}

void Transaction::setPrev(shared_ptr<Transaction> newPtr) {
    prev = move(newPtr);
}

// This used to return shared_ptr<Transaction>
shared_ptr<Node> Transaction::getPrev() {
    return prev;
}
void Transaction::print() {
    cout << "From: " << this->fromName << endl;
    cout << "To: " << this->toName << endl;
    cout << "Amount: $" << this->amount << endl;
}
bool Transaction::operator==(shared_ptr<Transaction> t) {
    shared_ptr<Transaction> newT = dynamic_pointer_cast<Transaction>(t);
}


