//
// Created by rodho on 2/22/2022.
//

#pragma once
#include <memory>
#include <string>
#include <vector>
using namespace std;


class Node {
protected:
    shared_ptr<Node> prev;
    string nodeType;

public:
    Node();
    Node(shared_ptr<Node>);
    virtual ~Node();

    shared_ptr<Node> getPrev() const;
    virtual void setPrev(shared_ptr<Node>);
    string getType();


};

