//
// Created by rodho on 2/22/2022.
//

#include "Transaction.h"

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

shared_ptr<Transaction> Transaction::getPrev() {
    return prev;
}

