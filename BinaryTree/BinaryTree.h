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
		Node* parent = nullptr;
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
		std::string value;
		int count = 1;
	};
	void PrintNodeInfo(Node* node);
	Node* Root;

};

