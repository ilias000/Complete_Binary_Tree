#ifndef __complete_bt__
#define __complete_bt__

#include <binary_treeTypes.h>
#include "complete_btTypes.h"

CBTTree CBTCreate(int maxelem); //create an empty binary tree (maxelem is ignored)

int CBTHeight(CBTTree tree); //return the height of the tree

int CBTSize(CBTTree tree); //return the number of elements in the tree

CBTNode CBTGetRoot(CBTTree tree); //returns the root node (can be Nil)

CBTNode CBTGetParent(CBTTree tree, CBTNode node);//returns the parent of a node (prints error if node is root)

CBTNode CBTGetChildLeft(CBTTree tree, CBTNode node); //returns the left child of a node (can be Nil)

CBTNode CBTGetChildRight(CBTTree tree, CBTNode node); //returns the right child of a node (can be Nil)

int CBTIsNil(CBTNode node); // returns true if the node is Nil, otherwise return false

CBTItem CBTGetItem(CBTTree tree, CBTNode node); //returns the value of the given node (error if node is Nil)

CBTNode CBTGetLast(CBTTree tree); // returns the ”last” node (rightmost leaf of the last level)

void CBTInsertLast(CBTTree tree, CBTItem item); // insert item as a new ”last” node

void CBTRemoveLast(CBTTree tree); //  removes the last node (error if the tree is empty)

void CBTChange(CBTTree tree, CBTNode node, CBTItem item); //sets item as the new value of the given node

void CBTPreOrder(CBTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void CBTInOrder(CBTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void CBTPostOrder(CBTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void CBTLevelOrder(CBTTree tree, BTFun visit); // traverse the tree and visit its nodes in the respective order

void CBTDestroy(CBTTree tree); // destroys the tree by freeing all its nodes

#endif