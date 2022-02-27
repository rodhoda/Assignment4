//
// Created by rodho on 2/25/2022.
//

#include "Ledger.h"

Ledger::Ledger() {}

Ledger Ledger::operator+=(Transaction newTxn) {
//    shared_ptr<Transaction> newNode;
//    newNode = newTxn.getPrev();
//    if (endPtr == nullptr)
//
//    newNode->getPrev() = endPtr->getPrev();
//    endPtr =
//return Ledger();
}

void Ledger::Add(Transaction newTxn) {
    shared_ptr<Transaction> newLedger = make_shared<Transaction>(newTxn);
    if (endPtr != nullptr) {
        newLedger->getPrev() = endPtr;
        endPtr = newLedger;
    }
    else
        endPtr = newLedger;


//    toName = newTxn.getToName();
//    fromName = newTxn.getFromName();
//    amount = newTxn.getAmount();
//    Transaction newNode;
//    newNode.setToName(toName);
//    newNode.setFromName(fromName);
//    newNode.setAmount(amount);

//    if (newLedger->endPtr == nullptr)
//        newLedger->endPtr = ;
//
//    return newNode;
}

//Ledger Ledger::operator=(shared_ptr<Transaction> aNode) {
//    this.
//}
