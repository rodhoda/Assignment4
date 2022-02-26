//
// Created by rodho on 2/22/2022.
//

#include "Transaction.h"

Transaction::Transaction() {
    nodeType = "TRANSACTION";
};
Transaction::Transaction(string newName, string newFromName, int amount) {
    nodeType = "TRANSACTION";
    prev = nullptr;
}