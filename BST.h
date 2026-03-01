//Title: Binary Search Trees
// Author: Aysegul Yildiz
// ID: 22002591
// Section: 1
// Homework: 2
// Description: binary search tree header file

#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class BST{
public:
    BST();
    ~BST();
    void destroyTree(BSTNode* node);
    bool isEmpty();
    void searchTreeInsert(string key);
    void insertItemRecursive(BSTNode*& treePtr, const string key);
    void searchTreeDelete(string key);
    void deleteItemRecursive(BSTNode * &treePtr, string searchKey);
    void deleteNodeItem(BSTNode * &nodePtr);
    void processLeftmost(BSTNode *&nodePtr, BSTNode* replacement);
    vector<string> inorderTraversal(BSTNode* root);
    void inorderTraversalRecursive(BSTNode* node, vector<string>& result);
    BSTNode* findKey(string key);
    BSTNode* findKeyRecursive(BSTNode* node, string key);
    vector<int> inorderTraversalF(BSTNode* root);
    void inorderTraversalFRecursive(BSTNode* node, vector<int>& frequencies);

    BSTNode* root;

};

#endif




