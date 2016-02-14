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
	delete Root;
}

void BinaryTree::insert(std::string input)
{
	Node* currentNode = Root;
	Node* previousNode = nullptr;
	ChildDirection previousDirection = Unknown;

	// loop will run until a node gets created or the count of a node is incremented
	while (true) 
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
			printNodeInfo(currentNode);

			// now we have to set the parent to point to the new node based on the direction 
			// that was taken traveresing the tree
			if (previousDirection == Left)
				previousNode->leftChild = currentNode;
			else if (previousDirection == Right)
				previousNode->rightChild = currentNode;

			// if there is no root then the node created is the root
			if (Root == nullptr)
				Root = currentNode;
			return;
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
			printNodeInfo(currentNode);
			return;
		}
	}	
}

void BinaryTree::printNodeInfo(Node* node)
{
	std::cout << node->value << " " << node->count << std::endl;
}

void BinaryTree::list()
{ 
	if (Root == nullptr)
	{
		std::cout << std::endl;
		return;
	}
	traverse(Root);
}

void BinaryTree::traverse(Node* node)
{
	if (node->leftChild != nullptr)
		traverse(node->leftChild);
	
	printNodeInfo(node);

	if (node->rightChild != nullptr)
		traverse(node->rightChild);
}

// takes in a node and get the leftmost node based off of that nodes children
BinaryTree::Node* BinaryTree::getLeftmostNode(Node* node)
{
	while (true)
	{
		if (node->leftChild == nullptr)
			return node;
		else
			node = node->leftChild;
	}
}

// takes in a node and get the rightmost node based off of that nodes children
BinaryTree::Node* BinaryTree::getRightmostNode(Node* node)
{
	while (true)
	{
		if (node->rightChild == nullptr)
			return node;
		else
			node = node->rightChild;
	}
}

void BinaryTree::min()
{
	// start at the root and go left until the left pointer is null
	if (Root == nullptr)
		std::cout << std::endl;
	else
	{
		Node* node = getLeftmostNode(Root);
		std::cout << node->value << std::endl;
	}
}

void BinaryTree::max()
{
	// start at the root and go right until the right pointer is null
	if (Root == nullptr)
		std::cout << std::endl;
	else
	{
		Node* node = getRightmostNode(Root);
		std::cout << node->value << std::endl;
	}
}

void BinaryTree::search(std::string input)
{
	Node* node = nodeLookup(input);
	if (node == nullptr)
		std::cout << input << " 0" << std::endl;
	else
		printNodeInfo(node);
}

BinaryTree::Node* BinaryTree::nodeLookup(std::string input)
{
	Node* currentNode = Root;

	while (true)
	{
		if (input.compare(currentNode->value) < 0)
		{
			if (currentNode->leftChild == nullptr)
			{
				std::cout << std::endl;
				return nullptr;
			}
			currentNode = currentNode->leftChild;
		}
		else if (input.compare(currentNode->value) > 0)
		{
			if (currentNode->rightChild == nullptr)
			{
				std::cout << std::endl;
				return nullptr;
			}
			currentNode = currentNode->rightChild;
		}
		else
		{
			return currentNode;
		}
	}
}

void BinaryTree::next(std::string input)
{
	Node* node = nodeLookup(input);

	if (node == nullptr)
	{
		std::cout << std::endl;
		return;
	}
	
	// if node has right child go as far left as possible from that child

	if (node->rightChild != nullptr)
		node = getLeftmostNode(node->rightChild);
	else
	{
		std::string nodeValue = node->value;

		do
		{
			if (node->parent != nullptr)
				node = node->parent;
			else
			{
				std::cout << std::endl;
				return;
			}
		} while (nodeValue.compare(node->value) > 0);
	}

	std::cout << node->value << std::endl;
}

void BinaryTree::previous(std::string input)
{
	Node* node = nodeLookup(input);

	if (node == nullptr)
	{
		std::cout << std::endl;
		return;
	}

	// if node has left child go as far right as possible from that child

	if (node->leftChild != nullptr)
		node = getRightmostNode(node->leftChild);
	else
	{
		std::string nodeValue = node->value;

		do
		{
			if (node->parent != nullptr)
				node = node->parent;
			else
			{
				std::cout << std::endl;
				return;
			}
		} while (nodeValue.compare(node->value) < 0);
	}

	std::cout << node->value << std::endl;
}

void BinaryTree::deleteInput(std::string input)
{
	Node* node = nodeLookup(input);

	// if node not found then print out the input string and -1
	if (node == nullptr)
	{
		std::cout << input << " -1" << std::endl;
		return;
	}
	else
	{
		node->count = node->count--;
		printNodeInfo(node);

		if (node->count < 1)
			removeNode(node);
	}
}

void BinaryTree::removeNode(Node* node)
{
	if (node->leftChild == nullptr)
		transplant(node, node->rightChild);
	else if (node->rightChild == nullptr)
		transplant(node, node->leftChild);
	else
	{
		Node* next = getLeftmostNode(node->rightChild);
		if (next->parent != node)
		{
			transplant(next, next->rightChild);
			next->rightChild = node->rightChild;
			next->parent = next;
		}
		transplant(node, next);
		next->leftChild = node->leftChild;
		next->leftChild->parent = next;
	}

}

void BinaryTree::transplant(Node* primary, Node* secondary)
{
	if (primary->parent == nullptr)
		Root = secondary;
	else if (primary == primary->parent->leftChild)
		primary->parent->leftChild = secondary;
	else
		primary->parent->rightChild = secondary;

	if (secondary != nullptr)
		secondary->parent = primary->parent;
}