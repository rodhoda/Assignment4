//
// Created by rodho on 2/22/2022.
//

#include "Node.h"

Node::Node() {};
Node::Node(shared_ptr<Node> newPtr): prev(newPtr) {}

shared_ptr<Node> Node::getPrev() const {
    return prev;
}



