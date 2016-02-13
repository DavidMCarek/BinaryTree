#pragma once
#include <string>

class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	void insert(std::string input);
	void list();
	void min();
	void max();
	void search(std::string input);
	void next(std::string input);
	void previous(std::string input);
private:
	struct Node {
		Node* parent = nullptr;
		Node* leftChild = nullptr;
		Node* rightChild = nullptr;
		std::string value;
		int count = 1;
	};
	void printNodeInfo(Node* node);
	Node* Root;
	enum ChildDirection {Left, Right, Unknown};
	void traverse(Node* node);
	Node* nodeLookup(std::string input);
	Node* getLeftmostNode(Node* node);
	Node* getRightmostNode(Node* node);

};

