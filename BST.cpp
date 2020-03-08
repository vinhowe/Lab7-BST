//
// Created by vin on 3/5/20.
//

#include "BST.h"

#include "Node.h"

BST::BST() {}

BST::~BST() {
  clear();
}

Node* BST::getRootNode() const { return root; }

bool BST::add(int data) { return insert(root, data); }

bool BST::insert(Node*& node, int data) {
  if (node == nullptr) {
    node = new Node(data);
    return true;
  }

  if (data < node->data) {
    return insert(node->left, data);
  } else if (data > node->data) {
    return insert(node->right, data);
  }

  return false;
}

bool BST::remove(int data) { return removeNode(root, data); }

void BST::clear() {
  removeSubtree(root);
}

void BST::removeSubtree(Node*& node) {
  if (node == nullptr) {
    return;
  }

  if (node->left != nullptr) {
    removeSubtree(node->left);
  }
  if (node->right != nullptr) {
    removeSubtree(node->right);
  }

  delete node;
  node = nullptr;
}

bool BST::removeNode(Node*& node, int data) {
  if (node == nullptr) {
    return false;
  }

  if (data < node->data) {
    return removeNode(node->left, data);
  } else if (data > node->data) {
    return removeNode(node->right, data);
  } else {
    Node* oldRoot = node;
    if (node->left == nullptr) {
      node = node->right;
    } else if (node->right == nullptr) {
      node = node->left;
    } else {
      replaceParent(oldRoot, oldRoot->left);
    }
    delete oldRoot;
    oldRoot = nullptr;
    return true;
  }
}

void BST::replaceParent(Node*& oldRoot, Node*& localRoot) {
  if (localRoot->right != nullptr) {
    replaceParent(oldRoot, localRoot->right);
  } else {
    oldRoot->data = localRoot->data;
    oldRoot = localRoot;
    localRoot = localRoot->left;
  }
}
