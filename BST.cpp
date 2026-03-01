//Title: Binary Search Trees
// Author: Aysegul Yildiz
// ID: 22002591
// Section: 1
// Homework: 2
// Description: binary search tree

#include "BST.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//checks if tree is empty
bool BST::isEmpty(){
    if(root == nullptr)
        return true;
    return false;
}

BST::BST(){
    root = NULL;
}
// destructor, deletes the tree and frees the memory
BST::~BST(){
    destroyTree(root);
}

void BST::destroyTree(BSTNode* node) {
    if (node != nullptr) {
        destroyTree(node->leftChildPtr); // Recursively destroy left subtree
        destroyTree(node->rightChildPtr); // Recursively destroy right subtree
        delete node; // Delete current node
    }
}

// calls the recursive insert
void BST::searchTreeInsert(string key) {
    insertItemRecursive(root, key);
}

// recursively traverses the tree to find an empty spot corresponding to key's alphabetical place and places there
void BST::insertItemRecursive(BSTNode *& treePtr, const string key) {
    if (treePtr == nullptr) {
        treePtr = new BSTNode(key, 1, NULL, NULL);
    }
    else if ( key < treePtr->key)
        insertItemRecursive(treePtr->leftChildPtr, key);
    else
        insertItemRecursive(treePtr->rightChildPtr, key);
}

// calls the recursive delete method
void BST::searchTreeDelete(string searchKey) {
    deleteItemRecursive(root, searchKey);
}

// searches for the key recursively and when it finds the key it calls deleteNodeItem method
void BST::deleteItemRecursive(BSTNode * &treePtr, string searchKey) {
    if (treePtr == nullptr)
    return;

    else if (searchKey == treePtr->key)
        deleteNodeItem(treePtr);

    else if (searchKey < treePtr->key)
        deleteItemRecursive(treePtr->leftChildPtr, searchKey);
    else
        deleteItemRecursive(treePtr->rightChildPtr, searchKey);
}

// checks if the node is a leaf if it is it deletes the node, if it has one child swaps parent and child and deletes child, if it has two children finds it inorder successor
// and swaps them and then swaps it again with a leaf node then deletes it (for two children situation it uses helper method processLeftmost
void BST::deleteNodeItem(BSTNode * &nodePtr) {
    BSTNode *delPtr;
    BSTNode* replacement;

    if ( (nodePtr->leftChildPtr == nullptr) && (nodePtr->rightChildPtr == nullptr) ) {
        delete nodePtr;
        nodePtr = nullptr;
    }

    else if (nodePtr->leftChildPtr == nullptr){
        delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }

    else if (nodePtr->rightChildPtr == nullptr) {
        delPtr = nodePtr;
        nodePtr = nodePtr->leftChildPtr;
        delPtr->leftChildPtr = nullptr;
        delete delPtr;
    }
    // There are two children:
    else {
        processLeftmost(nodePtr->rightChildPtr, replacement);
        nodePtr = replacement;
    }
}

// finds inorder successor swaps delete the node
void BST::processLeftmost(BSTNode *&nodePtr, BSTNode* replacement){
    if (nodePtr->leftChildPtr == nullptr) {
        BSTNode *delPtr = nodePtr;
        nodePtr = nodePtr->rightChildPtr;
        delPtr->rightChildPtr = nullptr;
        delete delPtr;
    }
    else
        processLeftmost(nodePtr->leftChildPtr, replacement);
}

// calls the recursive traversal method returns the vector of tree element's keys
vector<string> BST::inorderTraversal(BSTNode* root) {
    vector<string> keys;
    inorderTraversalRecursive(root, keys);
    return keys;
}

// recursively traverses the tree fills the vector
void BST::inorderTraversalRecursive(BSTNode* node, vector<string>& result) {
    if (node != nullptr) {
        inorderTraversalRecursive(node->leftChildPtr, result);
        result.push_back(node->key);
        inorderTraversalRecursive(node->rightChildPtr, result);
    }
}

vector<int> BST::inorderTraversalF(BSTNode* root) {
    vector<int> frequencies;
    inorderTraversalFRecursive(root, frequencies);
    return frequencies;
}

// recursively traverses the tree fills the vector
void BST::inorderTraversalFRecursive(BSTNode* node, vector<int> & frequencies) {
    if (node != nullptr) {
        inorderTraversalFRecursive(node->leftChildPtr, frequencies);
        frequencies.push_back(node->frequency);
        inorderTraversalFRecursive(node->rightChildPtr, frequencies);
    }
}


BSTNode* BST::findKey(string key) {
    return findKeyRecursive(root, key);
}

BSTNode* BST::findKeyRecursive(BSTNode* node, string key) {
    if (node == nullptr) {
        // Key not found in the tree
        return nullptr;
    }

    if (key == node->key) {
        // Key found, return the node
        return node;
    } else if (key < node->key) {
        // Search in the left subtree
        return findKeyRecursive(node->leftChildPtr, key);
    } else {
        // Search in the right subtree
        return findKeyRecursive(node->rightChildPtr, key);
    }
}


