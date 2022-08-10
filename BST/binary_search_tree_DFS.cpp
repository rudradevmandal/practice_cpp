/*
 * binary_search_tree_DFS.cpp
 *
 *  Created on: 01-Aug-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>
#include <queue>

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

void PreOrderTraverse(BstNode* root){
	if(!root) return;
	std::cout<<root->data<<", ";
	PreOrderTraverse(root->left_node);
	PreOrderTraverse(root->right_node);
}
void InOrderTraverse(BstNode* root){
	if(!root) return;
	InOrderTraverse(root->left_node);
	std::cout<<root->data<<", ";
	InOrderTraverse(root->right_node);
}
void PostOrderTraverse(BstNode* root){
	if(!root) return;
	PostOrderTraverse(root->left_node);
	PostOrderTraverse(root->right_node);
	std::cout<<root->data<<", ";
}

int main()
{
	// Space-Complexity O(height) worst: O(n) best: O(logn)
	// Time-Complexity O(n)
	std::cout<<"***Binary Search Tree: Depth First Search***"<<std::endl;
	BstNode* head = nullptr;// empty list
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
	std::cout<<std::endl;

	std::cout<<"***Binary Search Tree: Pre-order Traversal (root->left->right)***"<<std::endl;
	std::cout<<"***Expected DFS: 20, 11, 4, 5, 10, 12, 15, 20, 22, 22***"<<std::endl;
	std::cout<<"***Actual DFS: ";
	PreOrderTraverse(head);
	std::cout<<"***"<<std::endl;
	std::cout<<std::endl;

	std::cout<<"***Binary Search Tree: In-order Traversal (left->root->right)***"<<std::endl;
	std::cout<<"***Expected DFS: 4, 5, 10, 11, 12, 15, 20, 20, 22, 22***"<<std::endl;
	std::cout<<"***Actual DFS: ";
	InOrderTraverse(head);
	std::cout<<"***"<<std::endl;
	std::cout<<std::endl;

	std::cout<<"***Binary Search Tree: Post-order Traversal (left->right->root)***"<<std::endl;
	std::cout<<"***Expected DFS: 10, 5, 4, 20, 15, 12, 11, 22, 22, 20***"<<std::endl;
	std::cout<<"***Actual DFS: ";
	PostOrderTraverse(head);
	std::cout<<"***"<<std::endl;
}




