//Title: Binary Search Trees
// Author: Aysegul Yildiz
// ID: 22002591
// Section: 1
// Homework: 2
// Description: kmer tree header

#ifndef KMERTREE_H
#define KMERTREE_H

#include "BST.h"
#include "BSTNode.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class KmerTree{
public:
    KmerTree();
    ~KmerTree();

    void addKmer(string kmer);
    void generateTree(string fileName, int k);
    int getUniqueKmerCount();
    int getUniqueRecursive(BSTNode* node);
    int getNumberOfKmerThatStartWith(char ch);
    int getNumStartRecursive(BSTNode* node, char ch);
    void inorderTraverse(vector <string> &vec);
    void searchTreeDelete(string key);
    void printAll();
    int getHeight();
    int getHeightRecursive(BSTNode* node);

    BST tree;
};

#endif
