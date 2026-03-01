//Title: Binary Search Trees
// Author: Ayþegül Yýldýz
// ID: 22002591
// Section: 1
// Homework: 2
// Description: binary search tree node header file

#ifndef BSTNODE_H
#define BSTNODE_H

#include <iostream>
#include <string>
using namespace std;

class BSTNode{

public:
    BSTNode(){}
    BSTNode(const string &nodeKey,const int &occurence, BSTNode *left = NULL, BSTNode *right = NULL);

    int frequency;
    string key;
    BSTNode *leftChildPtr;
    BSTNode *rightChildPtr;
    void incrementCount();

};
#endif
