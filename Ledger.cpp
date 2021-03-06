//
// Created by rodho on 2/25/2022.
//

#include "Ledger.h"
#include <algorithm>
#include <map>

Ledger::Ledger() {}

Ledger& Ledger::operator+=(Transaction newTxn) {
    shared_ptr<Transaction> newTransaction = make_shared<Transaction>(newTxn);
//    shared_ptr<Node> newPointer = make_shared<Node>(newTxn);
    shared_ptr<Node> newP = dynamic_pointer_cast<Transaction>(newTransaction);


    toName = newTxn.getToName();
    fromName = newTxn.getFromName();
    amount = newTxn.getAmount();

    bool toNameExists = false;
    bool fromNameExists = false;

    if (ledgerVector.empty()) {
        ledgerVector.insert({toName, amount});
        if (fromName != "EXTERNAL")
            ledgerVector.insert({fromName, -amount});
    }
    else {
        for (auto & i : ledgerVector) {
            if (i.first == fromName) {
                i.second = i.second - amount;
                toNameExists = true;
            }
            if (i.first == toName) {
                i.second = i.second + amount;
                fromNameExists = true;
            }
        }
        if (!toNameExists)
            ledgerVector.insert({toName, amount});
        if (!fromNameExists && fromName != "EXTERNAL")
            ledgerVector.insert({fromName, -amount});

    }

    if (endPtr != nullptr) {
        newP->setPrev(endPtr);
        endPtr = newP;
    }
    else
        endPtr = newP;
//    endPtr->setPrev(newTransaction.lock());
    count++;
    if (count%10 == 0) {
        // Create a State Node and include all info from last 10 transactions
        shared_ptr<State> newState = make_shared<State>();
        newState->setLedger(ledgerVector);
        shared_ptr<Node> newS = dynamic_pointer_cast<State>(newState);
        newS->setPrev(newP);
        endPtr = newS;
//        ledgerVector.clear();
    }
}

ostream& operator<<(ostream& os, const Ledger& ledger) {
    if (ledger.endPtr != nullptr) {
        shared_ptr<Node> curNode = ledger.endPtr;
        while (curNode != nullptr) {
            string type = curNode->getType();
            if (type == "TRANSACTION") {
                auto tran = dynamic_pointer_cast<Transaction>(curNode);
                cout << "From: " << tran->getFromName() << endl;
                cout << "To: " << tran->getToName() << endl;
                cout << "Amount: $" << tran->getAmount() << endl;;
            }
            curNode = curNode->getPrev();
        }
    }
}

Ledger &Ledger::operator-=(Transaction newTxn) {
    shared_ptr<Transaction> newTransaction = make_shared<Transaction>(newTxn);
    weak_ptr<Node> tempNo = endPtr;
    weak_ptr<Node> tempN = endPtr->getPrev();
    shared_ptr<Node> curPrevNode = tempN.lock();
    shared_ptr<Node> curNode = tempNo.lock();

    auto curTran = dynamic_pointer_cast<Transaction>(curNode);

    if (curNode->getType() != "STATE") {
        if (newTransaction->getFromName() == curTran->getFromName() && newTransaction->getToName() == curTran->getToName() &&
            newTransaction->getAmount() == curTran->getAmount() && endPtr != nullptr)
            endPtr = endPtr->getPrev();
    }
    else {
        throw exception();
        }

    while (curPrevNode != nullptr && curNode != nullptr) {
        if (curPrevNode->getType() != "STATE") {

            auto curPrevTran = dynamic_pointer_cast<Transaction>(curPrevNode);

            auto curTran = dynamic_pointer_cast<Transaction>(curNode);


            if (newTransaction->getFromName() == curPrevTran->getFromName() && newTransaction->getToName() == curPrevTran->getToName() &&
                    newTransaction->getAmount() == curPrevTran->getAmount()) {
                curNode->setPrev(curPrevNode->getPrev());
                break;
                //            cout << curPrevNode.use_count() << endl;
            }
            else {
                curNode = curNode->getPrev();
                curPrevNode = curPrevNode->getPrev();
            }
        }
        else {
            break;
        }
    }
}

void Ledger::Clear() {
    endPtr = nullptr;
    ledgerVector.clear();
}

void Ledger::Settle() {
    shared_ptr<Node> curNode = endPtr;
    if (endPtr != nullptr) {
        while (curNode != nullptr) {
            string type = curNode->getType();
            if (type == "STATE") {
                auto tran = dynamic_pointer_cast<State>(curNode);
                for (const auto& i: tran->getLedger()) {
                    cout << "Account User: " << i.first << endl;
                    cout << "Balance: " << i.second << endl;
                }
                break;
            }
            curNode = curNode->getPrev();
        }
    }
}

void Ledger::InTheBlack() {
    shared_ptr<Node> curNode = endPtr;
    if (endPtr != nullptr) {
        while (curNode != nullptr) {
            string type = curNode->getType();
            if (type == "STATE") {
                auto tran = dynamic_pointer_cast<State>(curNode);
                for (const auto& i: tran->getLedger()) {
                    if (i.second >= 0) {
                        cout << "Account User: " << i.first << endl;
                        cout << "Balance: " << i.second << endl;
                    }
                }
                break;
            }
            curNode = curNode->getPrev();
        }
    }
}

void Ledger::InTheRed() {
    shared_ptr<Node> curNode = endPtr;
    if (endPtr != nullptr) {
        while (curNode != nullptr) {
            string type = curNode->getType();
            if (type == "STATE") {
                auto tran = dynamic_pointer_cast<State>(curNode);
                for (const auto& i: tran->getLedger()) {
                    if (i.second < 0) {
                        cout << "Account User: " << i.first << endl;
                        cout << "Balance: " << i.second << endl;
                    }
                }
                break;
            }
            curNode = curNode->getPrev();
        }
    }
}

//Ledger Ledger::operator=(shared_ptr<Transaction> aNode) {
//    this.
//}
