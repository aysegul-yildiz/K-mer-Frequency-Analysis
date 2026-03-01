hw2: main.cpp BSTNode.h BSTNode.cpp BST.h BST.cpp KmerTree.h KmerTree.cpp
	g++ main.cpp BST.cpp BSTNode.cpp KmerTree.cpp -o hw2

clean:
	rm -f hw2
