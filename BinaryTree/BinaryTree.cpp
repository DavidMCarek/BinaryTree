#include "stdafx.h"
#include "BinaryTree.h"
#include <iostream>
#include <string>


BinaryTree::BinaryTree()
{
	Root = nullptr;
}


BinaryTree::~BinaryTree()
{
}

void BinaryTree::Insert(std::string input)
{
	Node* currentNode = Root;
	Node* previousNode = nullptr;
	ChildDirection previousDirection = Unknown;
	bool nodeCreated = false;
	bool nodeCountIncremented = false;

	// loop will run until a node gets created or the count of a node is incremented
	while (!nodeCreated && !nodeCountIncremented) 
	{
		// if the current node is null then we have traveresed to a leaf of the root is null
		// in either case we need a new node for the tree and its value should be set to the
		// user input
		if (currentNode == nullptr)
		{
			currentNode = new Node();
			currentNode->value = input;

			// the previous node should either be null if the current node is the root or 
			// one node up in the tree which would be the parent 
			currentNode->parent = previousNode;
			PrintNodeInfo(currentNode);

			// now we have to set the parent to point to the new node based on the direction 
			// that was taken traveresing the tree
			if (previousDirection == Left)
				previousNode->leftChild = currentNode;
			else if (previousDirection == Right)
				previousNode->rightChild = currentNode;

			// if there is no root then the node created is the root
			if (Root == nullptr)
				Root = currentNode;
			nodeCreated = true;
		}
		else if (input.compare(currentNode->value) < 0) // input < node value | go left
		{
			previousNode = currentNode;
			currentNode = currentNode->leftChild;
			previousDirection = Left;
		}
		else if (input.compare(currentNode->value) > 0) //input > node value | go right
		{
			previousNode = currentNode;
			currentNode = currentNode->rightChild;
			previousDirection = Right;
		}
		else if (input.compare(currentNode->value) == 0) //input == node value | increment count
		{
			currentNode->count = currentNode->count++;
			nodeCountIncremented = true;
		}
	}	
}

void BinaryTree::PrintNodeInfo(Node* node)
{
	std::cout << "Value: " << node->value << " Count: " << node->count << std::endl;
}

void BinaryTree::List()
{
	// traverse to min point, then go up one, right one, left as far  
	Traverse(Root);
}

void BinaryTree::Traverse(Node* node)
{
	if (node->leftChild != nullptr)
		Traverse(node->leftChild);
	
	PrintNodeInfo(node);

	if (node->rightChild != nullptr)
		Traverse(node->rightChild);
}