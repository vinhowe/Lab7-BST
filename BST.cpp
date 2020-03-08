//
// Created by vin on 3/5/20.
//

#include "BST.h"

#include "Node.h"

BST::BST() {}

BST::~BST() {}

Node* BST::getRootNode() const { return root; }

bool BST::add(int data) { return insert(root, data); }

bool BST::insert(Node*& node, int data) {
  if (node == nullptr) {
    node = new Node(data);
    return true;
  }

  if (data < node->getData()) {
    return insert(node->left, data);
  } else if (data > node->getData()) {
    return insert(node->right, data);
  }

  return false;
}

bool BST::remove(int data) {
  return removeNode(root, data);
}

void BST::clear() {}

bool BST::removeNode(Node*& node, int data) {
  if (node == nullptr) {
    return false;
  }

  if (data < node->getData()) {
    return removeNode(node->left, data);
  } else if (data > node->getData()) {
    return removeNode(node->right, data);
  } else {
    Node *oldRoot = node;
    if (node->left == nullptr) {
      node = node->right;
    } else if (node->right == nullptr) {
      node = node->left;
    } else {
      replaceParent(oldRoot, oldRoot->right);
    }
    // TODO: possible problem area
    delete oldRoot;
    return true;
  }
}

void BST::replaceParent(Node*& oldRoot, Node*& localRoot) {
  if (localRoot->right != nullptr) {
    replaceParent(oldRoot, localRoot->right);
  } else {
    oldRoot->data = localRoot->data;
    removeNode(oldRoot, localRoot->data);
  }
}
