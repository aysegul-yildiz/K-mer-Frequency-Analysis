//Title: Binary Search Trees
// Author: Aysegul Yildiz
// ID: 22002591
// Section: 1
// Homework: 2
// Description: main

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <algorithm>
#include "KmerTree.h"
using namespace std;
void timeAnalysis(string inputfilename, int k);

int main(int argc, char *argv[]) {

        if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <k> <input_file>" << endl;
        return 1;
    }


        int k = atoi(argv[1]); // assuming k is an integer
        string inputFileName = argv[2];

        KmerTree kmer_tree = KmerTree();
        kmer_tree.generateTree(inputFileName, k);


        cout << "All kmers in alphabetical order: " << endl;
        kmer_tree.printAll();
        cout << "------------------------------------------------" << endl;

        // Inorder Traversal
        cout << "Inorder traversal: " << endl;
        vector<string> inorder_vect;
        kmer_tree.inorderTraverse(inorder_vect);
        for (auto itr : inorder_vect){
            cout << itr << " ";}
        cout << endl;
        cout << "------------------------------------------------" << endl;

        // Adding a kmer to the existing tree
        string str1 = "one";
        kmer_tree.addKmer(str1);

        cout << "After adding " << str1 << ": "  << endl;
        vector<string> inorder_vect_2;
        kmer_tree.inorderTraverse(inorder_vect_2);
        for (auto itr : inorder_vect_2){
            cout << itr << " ";}
        cout << endl;
        cout << "------------------------------------------------" << endl;

        // Deleting the kmers.
        // Notice that deleting the kmer deletes the node from the tree completely.
        kmer_tree.searchTreeDelete("ood");
        kmer_tree.searchTreeDelete("has");
        kmer_tree.searchTreeDelete("woo");
        kmer_tree.searchTreeDelete("one");

        cout << "After deleting ood, has, woo, and one: " << endl;
        vector<string> inorder_vect_3;
        kmer_tree.inorderTraverse(inorder_vect_3);
        for (auto itr : inorder_vect_3){
            cout << itr << " ";}
        cout << endl;
        cout << "------------------------------------------------" << endl;

        // Number of unique kmers in the tree
        cout << "Number of unique kmers = " << kmer_tree.getUniqueKmerCount() << endl;
        cout << "------------------------------------------------" << endl;

        // Adding the kmer "xyz" to the existing tree
        str1 = "xyz";
        kmer_tree.addKmer(str1);

        // Number of  kmers in the tree now
        cout << "After adding " << str1 << "...";
        cout << "Number of unique kmers = " << kmer_tree.getUniqueKmerCount() << endl;
        cout << "------------------------------------------------" << endl;

        // Number of kmers that start with the character "h"
        char ch = 'h';
        cout << "Number of kmers that start with " << ch << " = " << kmer_tree.getNumberOfKmerThatStartWith(ch) << endl;
        cout << "------------------------------------------------" << endl;

        // Printing all kmers with their frequencies
        cout << "All kmers in alphabetical order: " << endl;
        kmer_tree.printAll();
        cout << "------------------------------------------------" << endl;

        // Kmer Tree Height
        cout << "Kmer Tree height is = " << kmer_tree.getHeight() << endl;

        timeAnalysis(inputFileName,k);
        timeAnalysis(inputFileName,k+15);



    return 0;
}

void timeAnalysis(string inputFileName, int k){
        std::chrono::time_point< std::chrono::system_clock > startTime;
        std::chrono::duration< double, milli > elapsedTime;
        startTime = std::chrono::system_clock::now();

        fstream file;
        string fileText = "";
        file.open(inputFileName, ios::in);
        if(file.is_open()){
            string fileLine;
            while(getline(file, fileLine)){
                fileText = fileText + fileLine;
            }
            file.close();
        }

        transform(fileText.begin(), fileText.end(), fileText.begin(), ::tolower);
        int len = fileText.length() - fileText.length()%k;
        KmerTree tree = KmerTree();
        int sub = len / 1000;
        int index = 0;

        if(sub<1){
                cout<<"After adding "<< len<< " length string with k value "<< k <<" :"<<endl;
            tree.generateTree(inputFileName,k);
             elapsedTime = std::chrono::system_clock::now() - startTime;
                    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

                    cout << "Number of unique kmers = " << tree.getUniqueKmerCount() << endl;
                    cout << "Kmer Tree height is = " << tree.getHeight() << endl;
                    elapsedTime = std::chrono::system_clock::now() - startTime;
                    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
                    return;

        }
        for(int i=1; (i*(i+1)/2)*1000 <= len ;i++){
                cout<<"After adding "<< 1000*(i)<< " length string with k value "<< k <<" :"<<endl;
                for(int j = 0; j < 1000*(i); j+=k ){
                    index = (1000*(i-1)) + j;
                    tree.addKmer(fileText.substr(index,k));
                }
                    elapsedTime = std::chrono::system_clock::now() - startTime;
                    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

                    cout << "Number of unique kmers = " << tree.getUniqueKmerCount() << endl;
                    cout << "Kmer Tree height is = " << tree.getHeight() << endl;
                    elapsedTime = std::chrono::system_clock::now() - startTime;
                    cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

        }


}
