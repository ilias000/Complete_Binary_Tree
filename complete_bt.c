#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include <binary_tree.h>

#include "complete_bt.h"
#include "complete_btTypes.h"

struct CBTTreeS
{
    BTTree btTree;//because the functions of binary tree returns BTTree and the new functions returns CBTTree 
    BTNode lastNode;
} CBTTreeS;


CBTTree CBTCreate(int maxlem)//create an empty binary tree (maxelem is ignored)
{
    CBTTree tree = malloc(sizeof(CBTTreeS));
    tree->btTree = BTCreate(maxlem);
    tree->lastNode = NULL;
    return tree;
}


int CBTHeight(CBTTree tree) //return the height of the tree
{
    return BTHeight(tree->btTree);
}


int CBTSize(CBTTree tree) //return the number of elements in the tree
{
    return BTSize(tree->btTree);
}


CBTNode CBTGetRoot(CBTTree tree) //returns the root node (can be Nil)
{
    return BTGetRoot(tree->btTree);
}

CBTNode CBTGetParent(CBTTree tree, CBTNode node) //returns the parent of a node (prints error if node is root)
{
    return BTGetParent(tree->btTree, node);
}


CBTNode CBTGetChildLeft(CBTTree tree, CBTNode node) //returns the left child of a node (can be Nil)
{
    return BTGetChildLeft(tree->btTree, node);
}


CBTNode CBTGetChildRight(CBTTree tree, CBTNode node) //returns the right child of a node (can be Nil)
{
    return BTGetChildRight(tree->btTree, node);
}


int CBTIsNil(CBTNode node) // returns true if the node is Nil, otherwise return false
{
    return BTIsNil(node);//Nil==1 Nil!=0
}


CBTItem CBTGetItem(CBTTree tree, CBTNode node) //returns the value of the given node (error if node is Nil)
{
    return BTGetItem(tree->btTree, node);
}


CBTNode CBTGetLast(CBTTree tree)
{
    return tree->lastNode;
}

void CBTInsertLast(CBTTree tree, CBTItem item)
{
    if (CBTSize(tree) == 0)
    {
        //tree is empty
        BTInsertRoot(tree->btTree, item);
        tree->lastNode = CBTGetRoot(tree);
    }
    else if (CBTSize(tree) == 1)
    {
        //tree has only root
        BTInsertLeft(tree->btTree, CBTGetRoot(tree), item);
        tree->lastNode = CBTGetChildLeft(tree, CBTGetRoot(tree));
    }
    else
    {
        if (CBTSize(tree) % 2 == 0)
        {
            // last node is a left child
            BTInsertRight(tree->btTree, CBTGetParent(tree, tree->lastNode), item);
            tree->lastNode = CBTGetChildRight(tree, CBTGetParent(tree, tree->lastNode));
        }
        else
        {
            // last node is a right child
            if (CBTSize(tree) == (pow(2, CBTHeight(tree) + 1) - 1))
            {
                // last node is the last node on the right, a new level of the tree must be created
                CBTNode node = CBTGetChildLeft(tree, CBTGetRoot(tree));

                // find the first node on the last level of the tree
                while (CBTIsNil(CBTGetChildLeft(tree, node)) == 0)
                {
                    node = CBTGetChildLeft(tree, node);
                }

                // add item as its new left child
                BTInsertLeft(tree->btTree, node, item);
                tree->lastNode = CBTGetChildLeft(tree, node);
            }
            else
            {
                // climb the tree up the first parent, where the kladi is not a right one but a left one

                CBTNode right_child = tree->lastNode;
                CBTNode parent = CBTGetParent(tree, right_child);
                while (right_child == CBTGetChildRight(tree, parent))
                {
                    right_child = parent;
                    parent = CBTGetParent(tree, right_child);
                }

                CBTNode left_child = CBTGetChildRight(tree, parent);
                while (CBTIsNil(CBTGetChildLeft(tree, left_child)) == 0)
                {
                    left_child = CBTGetChildLeft(tree, left_child);
                }

                // add item as its new left child
                BTInsertLeft(tree->btTree, left_child, item);
                tree->lastNode = CBTGetChildLeft(tree, left_child);
            }
        }
    }
}

void CBTRemoveLast(CBTTree tree)
{
    if (CBTSize(tree) == 0)
    {
        //tree is empty
        printf("Error: The tree is empty");
    }
    else if (CBTSize(tree) == 1)
    {
        //tree has only root
        BTRemove(tree->btTree, tree->lastNode);
        tree->lastNode = NULL;
    }
    else
    {
        if (CBTSize(tree) % 2 == 1)
        {
            // last node is a right child
            CBTNode temp = tree->lastNode;
            tree->lastNode = BTGetChildLeft(tree->btTree, BTGetParent(tree->btTree, tree->lastNode));
            BTRemove(tree->btTree, temp);
        }
        else
        {
            // last node is a left child
            if (CBTSize(tree) == pow(2, CBTHeight(tree)))
            {
                // last node is the last node on the left, a level of the tree must be deleted
                CBTNode node = CBTGetChildRight(tree, CBTGetRoot(tree));

                // find the last right node on the second to last level of the tree
                while (CBTIsNil(CBTGetChildRight(tree, node)) == 0)
                {
                    node = CBTGetChildRight(tree, node);
                }

                // remove the node
                BTRemove(tree->btTree, tree->lastNode);
                tree->lastNode = node;
            }
            else
            {
                //last node is a right node
                CBTNode temp = tree->lastNode;
                tree->lastNode = CBTGetChildRight(tree, CBTGetChildLeft(tree, CBTGetParent(tree, CBTGetParent(tree,tree->lastNode))));
                BTRemove(tree->btTree, temp);
            }
        }
    }
}


void CBTChange(CBTTree tree, CBTNode node, CBTItem item) //sets item as the new value of the given node
{
    BTChange(tree->btTree, node, item);
}

void CBTPreOrder(CBTTree tree, BTFun visit)
{
    BTPreOrder(tree->btTree, visit);
}

void CBTInOrder(CBTTree tree, BTFun visit)
{
    BTInOrder(tree->btTree, visit);
}


void CBTPostOrder(CBTTree tree, BTFun visit)
{
    BTPostOrder(tree->btTree, visit);
}


void CBTLevelOrder(CBTTree tree, BTFun visit)
{
    BTLevelOrder(tree->btTree, visit);
}

void CBTDestroy(CBTTree tree)
{
    BTDestroy(tree->btTree);
}
