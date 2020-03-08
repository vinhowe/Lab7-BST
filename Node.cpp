//
// Created by vin on 3/5/20.
//

#include "Node.h"

Node::Node(int data) : data(data) {}
Node::~Node() {}

int Node::getData() const { return data; }

Node* Node::getLeftChild() const { return left; }

Node* Node::getRightChild() const { return right; }

void Node::setLeftChild(Node* child) {
  left = child;
}

void Node::setRightChild(Node* child) {
  right = child;
}

void Node::setData(int newData) {
  this->data = newData;
}
