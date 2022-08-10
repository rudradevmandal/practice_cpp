/*
 * binary_search_tree_height.cpp
 *
 *  Created on: 31-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>

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

	int FindHeight(BstNode* root){
		if (!root) return -1;
		int left_height = FindHeight(root->left_node);
		int right_height = FindHeight(root->right_node);
		if (left_height>right_height) return left_height+1;
		else return right_height+1;
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

int main()
{
	std::cout<<"***Binary Search Tree: Find Height***"<<std::endl;
	BstNode* head = nullptr;// empty list
	head=head->InsertRecursive(head, 20);//							20
	head=head->InsertRecursive(head, 11);//				11					22
	head=head->InsertRecursive(head, 12);//			4		12			22
	head=head->InsertRecursive(head, 4);//				5		15
	head=head->InsertRecursive(head, 5);//					10		20
	head=head->InsertRecursive(head, 22);
	head=head->InsertRecursive(head, 10);
	head=head->InsertRecursive(head, 15);
	head=head->InsertRecursive(head, 20);
	head=head->InsertRecursive(head, 22);
	head->Print();

	std::cout<<"Height of the node is :"<<head->FindHeight(head)<<std::endl;

}




