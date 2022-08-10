/*
 * binary_search_tree_check.cpp
 *
 *  Created on: 01-Aug-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>
#include <queue>
#include <limits>

class BstNode;
BstNode* rootNode;

class BstNode{
public:
	int data;
	BstNode* left_node;
	BstNode* right_node;
	BstNode* NewNode(int x){
		BstNode* temp = new BstNode();
		temp->data = x;
		temp->left_node = nullptr;
		temp->right_node = nullptr;
		return temp;
	}
	BstNode* InsertRecursive(BstNode* root, int x)
	{
		if (!root)root=NewNode(x);
		else if (x <= root->data) root->left_node = InsertRecursive(root->left_node, x);
		else root->right_node = InsertRecursive(root->right_node, x);
		return root;
	}
};

void LevelOrderTraverse(BstNode* root){
	if(!root) return;
	std::queue<BstNode*> q; // Space-Complexity O(n)
	q.push(root);
	while(!q.empty()){ // Time-Complexity - O(n)
		BstNode* current = q.front();
		std::cout.flush();
		std::cout<<current->data<<", ";
		if(current->left_node)q.push(current->left_node);
		if(current->right_node)q.push(current->right_node);
		q.pop();
	}
	std::cout<<"***"<<std::endl;
}


// Brute force method
// Checks if the value in left sub tree is lesser than the value in root node
// Checks if the value in right sub tree is greater than the value in root node
// Repeats for every node
// Time-Complexity O(n^2)
bool IsSubTreeLesser(BstNode* root, int value){
	if (!root) return true;
	if (root->data <= value &&
		IsSubTreeLesser(root->left_node, value) &&
		IsSubTreeLesser(root->right_node, value)) return true;
	else return false;
}

bool IsSubTreeGreater(BstNode* root, int value){
	if (!root) return true;
	if (root->data > value &&
		IsSubTreeGreater(root->left_node, value) &&
		IsSubTreeGreater(root->right_node, value)) return true;
	else return false;
}

bool IsBinarySearchTreeBruteForce(BstNode* root){
	if (!root) return true;
	if(IsSubTreeLesser(root->left_node, root->data) &&
	   IsSubTreeGreater(root->right_node, root->data) &&
	   IsBinarySearchTreeBruteForce(root->left_node) &&
	   IsBinarySearchTreeBruteForce(root->right_node)) return true;
	else return false;
}

// Bound Method
// Define a range for every node
// If node value is within range, return true
// Else return false
// Time-Complexity O(n)
bool IsBinarySearchTreeBound(BstNode* root, int LowerBound, int UpperBound){
	if (!root) return true;
	std::cout<<"root->data="<<root->data<<", LowerBound="<<LowerBound<<", UpperBound="<<UpperBound<<std::endl;
	if(root->data >= LowerBound &&
	   root->data <= UpperBound &&
	   IsBinarySearchTreeBound(root->left_node, LowerBound, root->data) &&
	   IsBinarySearchTreeBound(root->right_node, root->data, UpperBound)) return true;
	else return false;
}

// In-Order Traversal Method
// Traverse in a sorted method
// Check the current read node with previous
// If in ascending then true
// Time-Complexity O(n)
// Space Complexity O(h)
bool IsBinarySearchTreeInOrderTraverse(BstNode* root){
	static BstNode* prev = nullptr;
	if(!root) return true;
	if(!IsBinarySearchTreeInOrderTraverse(root->left_node)) return false;
	if (prev and root)std::cout<<"root->data="<<root->data<<", prev->data="<<prev->data<<std::endl;
	if (prev and root->data < prev->data) return false;
	prev = root;
	return IsBinarySearchTreeInOrderTraverse(root->right_node);
}


int main()
{
	int imin = std::numeric_limits<int>::min(); // minimum value
	int imax = std::numeric_limits<int>::max();

	std::cout<<"***Binary Search Tree: Check if Given a Binary Tree is a Binary Search Tree***"<<std::endl;
	BstNode* head = nullptr;// empty list

	std::string isBinarySearchTree;

	head=head->InsertRecursive(head, 20);//							20
	head=head->InsertRecursive(head, 11);//				11						22
	head=head->InsertRecursive(head, 12);//			4		12				22
	head=head->InsertRecursive(head, 4);//				5		15
	head=head->InsertRecursive(head, 5);//					10		20
	head=head->InsertRecursive(head, 22);
	head=head->InsertRecursive(head, 10);
	head=head->InsertRecursive(head, 15);
	head=head->InsertRecursive(head, 20);
	head=head->InsertRecursive(head, 22);
	std::cout<<"***Expected BFS: 20, 11, 22, 4, 12, 22, 5, 15, 10, 20***"<<std::endl;
	std::cout<<"***Actual BFS: ";
	LevelOrderTraverse(head);
	std::cout<<std::endl;

	std::cout<<"***Check if Given a Binary Tree is a Binary Search Tree: Brute Force***"<<std::endl;
	isBinarySearchTree = IsBinarySearchTreeBruteForce(head) ? "IS" : "IS NOT";
	std::cout<<"The above binary tree "<<isBinarySearchTree<<" a Binary Search Tree."<<std::endl;
	std::cout<<std::endl;

	std::cout<<"***Check if Given a Binary Tree is a Binary Search Tree: Bound Method***"<<std::endl;
	isBinarySearchTree = IsBinarySearchTreeBound(head, imin, imax) ? "IS" : "IS NOT";
	std::cout<<"The above binary tree "<<isBinarySearchTree<<" a Binary Search Tree."<<std::endl;
	std::cout<<std::endl;

	std::cout<<"***Check if Given a Binary Tree is a Binary Search Tree: In-Order Traversal Method***"<<std::endl;
	isBinarySearchTree = IsBinarySearchTreeInOrderTraverse(head) ? "IS" : "IS NOT";
	std::cout<<"The above binary tree "<<isBinarySearchTree<<" a Binary Search Tree."<<std::endl;
	std::cout<<std::endl;
}




