//
// Created by rodho on 2/22/2022.
//

#include "Node.h"

Node::Node() {};
Node::Node(int newData): data(newData) {}
Node::Node(int newData, shared_ptr<Node> newPtr): data(newData),
                                                  next(newPtr) {}


int Node::getValue() const {
    return data;
}

shared_ptr<Node> Node::getNext() const {
    return next;
}


