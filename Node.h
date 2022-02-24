//
// Created by rodho on 2/22/2022.
//

#pragma once
#include <memory>
#include <string>
#include <vector>
using namespace std;

class Node {
private:
    int data;
    shared_ptr<Node> next;
public:
    Node();
    Node(int);
    Node(int, shared_ptr<Node>);

    shared_ptr<Node> getNext() const;
    int getValue() const;
};

