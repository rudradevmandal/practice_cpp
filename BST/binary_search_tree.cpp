/*
 * binary_search_tree.cpp
 *
 *  Created on: 31-Jul-2022
 *      Author: rudradev
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
	bool Insert(int x)
	{
		BstNode* temp = new BstNode();
		temp->data = x;
		temp->left_node = nullptr;
		temp->right_node = nullptr;
		if (!rootNode)rootNode=temp;

		//If root node present, compare to find the position
		BstNode* node = rootNode;
		while (node){
			if (temp->data <= node->data and node->left_node) node = node->left_node;
			else if (temp->data > node->data and node->right_node) node = node->right_node;
			else break;
		}
		if (temp->data<node->data) node->left_node = temp;
		else node->right_node = temp;
		return true;
	}
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

	bool Search(BstNode* root, int x){
		if(!root)return false;
		else if (x == root->data) return true;
		else if (x<=root->data) return Search(root->left_node,x);
		else return Search(root->right_node,x);
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
	std::cout<<"***Binary Search Tree: Search a number***"<<std::endl;
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

	int n;
	std::cout<<"Enter the number to search:"<<std::endl;
	std::cin>>n;
	if (head->Search(head, n)) std::cout<<"Found the number="<<n<<std::endl;
	else std::cout<<"Not Found the number="<<n<<std::endl;

}




