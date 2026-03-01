//Title: Binary Search Trees
// Author: Aysegul Yildiz
// ID: 22002591
// Section: 1
// Homework: 2
// Description: binary search tree node

#include "BSTNode.h"
#include <string>
#include <iostream>
using namespace std;

BSTNode::BSTNode(const string& nodeKey, const int& occurrence, BSTNode* left, BSTNode* right){
    key= nodeKey;
    frequency = occurrence;
    leftChildPtr = left;
    rightChildPtr = right;
    }
//when the key that is trying to be inserted already exists kmertree will call this method and increment the count of the node with the key
void BSTNode::incrementCount(){
    frequency++;
}
