/*
 * binary_search_tree_BFS.cpp
 *
 *  Created on: 31-Jul-2022
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

	void Print()
	{
		BstNode* left = this;
		std::cout<<"LEFT-->";
		while (left != nullptr)
		{
			std::cout<<"["<<left->data<<"]-->";
			if (!left->left_node) break;
			left = left->left_node;
		}
		std::cout<<"END"<<std::endl;
		BstNode* right = this;
		std::cout<<"RIGHT-->";
		while (right != nullptr)
		{
			std::cout<<"["<<right->data<<"]-->";
			if (!right->right_node) break;
			right = right->right_node;
		}
		std::cout<<"END"<<std::endl;
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

int main()
{
	std::cout<<"***Binary Search Tree: Level Order Traversal***"<<std::endl;
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
	head->Print();
	std::cout<<"***Expected BFS: 20, 11, 22, 4, 12, 22, 5, 15, 10, 20***"<<std::endl;
	std::cout<<"***Actual BFS: ";
	LevelOrderTraverse(head);
}




