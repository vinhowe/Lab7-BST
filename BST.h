#pragma once

#include "BSTInterface.h"
#include "Node.h"
#include "NodeInterface.h"

using namespace std;

class BST : public BSTInterface {
 public:
  BST();
  ~BST() override;

  // Please note that the class that implements this interface must be made
  // of objects which implement the NodeInterface

  /*
   * Returns the root node for this tree
   *
   * @return the root node for this tree.
   */
  [[nodiscard]] Node* getRootNode() const override;

  /*
   * Attempts to add the given int to the BST tree
   *
   * @return true if added
   * @return false if unsuccessful (i.e. the int is already in tree)
   */
  bool add(int data) override;

  /*
   * Attempts to remove the given int from the BST tree
   *
   * @return true if successfully removed
   * @return false if remove is unsuccessful(i.e. the int is not in the tree)
   */
  bool remove(int data) override;

  /*
   * Removes all nodes from the tree, resulting in an empty tree.
   */
  void clear() override;

 private:
  Node* root = nullptr;

  static bool insert(Node*& node, int data);

  static bool removeNode(Node*& node, int data);

  static void replaceParent(Node*& oldRoot, Node*& localRoot);
};