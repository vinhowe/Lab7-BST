#pragma once

#include <iostream>

#include "NodeInterface.h"

class Node : public NodeInterface {
 public:
  Node(int data);
  ~Node() override;

  /*
   * Returns the data that is stored in this node
   *
   * @return the data that is stored in this node.
   */
  [[nodiscard]] int getData() const override;

  /*
   * Returns the left child of this node or null if it doesn't have one.
   *
   * @return the left child of this node or null if it doesn't have one.
   */
  [[nodiscard]] Node* getLeftChild() const override;

  /*
   * Returns the right child of this node or null if it doesn't have one.
   *
   * @return the right child of this node or null if it doesn't have one.
   */
  [[nodiscard]] Node* getRightChild() const override;

  void setLeftChild(Node* child);
  void setRightChild(Node* child);

  void setData(int data);

 private:
  int data;
  Node* right = nullptr;
  Node* left = nullptr;
  friend class BST;
};