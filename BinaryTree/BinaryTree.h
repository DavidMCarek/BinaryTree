#pragma once
#include <string>

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void Insert(std::string input);
private:
	struct Node {
		Node* parent;
		Node* leftChild;
		Node* rightChild;
		std::string value;
		int count;
	};
	Node* Root;

};

