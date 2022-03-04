//
// Created by rodho on 2/22/2022.
//

#include "Node.h"

Node::Node(): prev(nullptr) {};
Node::Node(shared_ptr<Node> newPtr): prev(newPtr) {}
Node::~Node() {}

shared_ptr<Node> Node::getPrev() const {
    return prev;
}
 void Node::setPrev(shared_ptr<Node> newPtr) {
    prev = move(newPtr);
}
string Node::getType() {
    return nodeType;
}



