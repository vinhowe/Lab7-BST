//
// Created by vin on 3/5/20.
//

#include "BST.h"

#include "Node.h"


BST::BST() {}

BST::~BST() {}

Node* BST::getRootNode() const { return root; }

bool BST::add(int data) {
  root = insert(root, data);
}

Node* BST::insert(Node* node, int data) {
  if (node == nullptr) {
    return new Node(data);
  }

  if (data < node->getData()) {
    node->setLeftChild(insert(node->getLeftChild(), data));
  } else if (data > node->getData()) {
    node->setRightChild(insert(node->getRightChild(), data));
  }

  return node;
}

bool BST::remove(int data) { return false; }

void BST::clear() {}
