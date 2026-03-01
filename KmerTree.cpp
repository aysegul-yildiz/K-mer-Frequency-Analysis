//Title: Binary Search Trees
// Author: Aysegul Yildiz
// ID: 22002591
// Section: 1
// Homework: 2
// Description: kmer tree

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "KmerTree.h"

using namespace std;

    KmerTree::KmerTree(){};
    KmerTree::~KmerTree(){
    };

    void KmerTree::addKmer(string kmer){
        BSTNode* nodeptr = tree.findKey(kmer);
        if( nodeptr != NULL ){
            nodeptr->incrementCount();
        }
        else{
            tree.searchTreeInsert(kmer);
        }
    }
    void KmerTree::generateTree(string fileName, int k){
        fstream file;
        string fileText = "";
        file.open(fileName, ios::in);
        if(file.is_open()){
            string fileLine;
            while(getline(file, fileLine)){
                fileText = fileText + fileLine;
            }
            file.close();
        }

        transform(fileText.begin(), fileText.end(), fileText.begin(), ::tolower);
        int len = fileText.length() - fileText.length()%k;
        for(int i=0; i < len;i+=k){
            addKmer(fileText.substr(i,k));
        }

    }
    int KmerTree::getUniqueKmerCount(){
        if(tree.isEmpty())
            return 0;
        return getUniqueRecursive(tree.root);
    }
int KmerTree::getUniqueRecursive(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }

    // Recursively count in left and right subtrees and add to this node's count
    return 1 + getUniqueRecursive(node->leftChildPtr) + getUniqueRecursive(node->rightChildPtr);
}



    int KmerTree::getNumberOfKmerThatStartWith(char ch){
        if(tree.isEmpty())
            return 0;
        return getNumStartRecursive(tree.root, ch);
    }

   int KmerTree::getNumStartRecursive(BSTNode* node, char ch) {
    if (node == nullptr) {
        // Base case: if the node is null, return 0
        return 0;
    }

    // Check if the current node's key starts with the character 'ch'
    int count = (node->key[0] == ch) ? 1 : 0;

    // Recursively count in left and right subtrees and add to this node's count
    return count + getNumStartRecursive(node->leftChildPtr, ch) + getNumStartRecursive(node->rightChildPtr, ch);
}

    void KmerTree::printAll(){
        vector <string> keys = tree.inorderTraversal(tree.root);
        vector<int> frequencies = tree.inorderTraversalF(tree.root);
        for(int i= 0; i < keys.size(); i++){
            cout<<keys[i]<< ", frequency = "<<frequencies[i]<<endl;
        }
    }
    void KmerTree::inorderTraverse(vector <string> &vec){
        vec = tree.inorderTraversal(tree.root);
    }
    void KmerTree::searchTreeDelete(string key){
        tree.searchTreeDelete(key);
    }
    int KmerTree::getHeight(){
        if(tree.isEmpty())
            return 0;
        return getHeightRecursive(tree.root);
    }

   int KmerTree::getHeightRecursive(BSTNode* node) {
    if (node == nullptr) {
        return 0;
    }
    int leftHeight = getHeightRecursive(node->leftChildPtr);
    int rightHeight = getHeightRecursive(node->rightChildPtr);
    return 1 +  max(leftHeight, rightHeight);
}

