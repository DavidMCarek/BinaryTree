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
	if (Root == nullptr)
	{
		Root = new Node;
		Root->value = input;
		PrintNodeInfo(Root);
	} 
	else
	{
		// recurse through the tree comparing the input value to the value of the node
	}
		
}

void BinaryTree::PrintNodeInfo(Node* node)
{
	std::cout << "Value: " << node->value << " Count: " << node->count << std::endl;
}