/*
 * binary_search_tree_min_max.cpp
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

	int FindMin(BstNode* root){
		if(!root->left_node)return root->data;
		else return FindMin(root->left_node);
	}

	int FindMax(BstNode* root){
		if(!root->right_node)return root->data;
		else return FindMax(root->right_node);
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
	std::cout<<"***Binary Search Tree: Find Min and Max Values***"<<std::endl;
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

	std::cout<<"Minimum number is :"<<head->FindMin(head)<<" and Maximum number is "<<head->FindMax(head)<<std::endl;

}




