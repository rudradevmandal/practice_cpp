/*
 * binary_search_tree_delete_node.cpp
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
	BstNode* FindMin(BstNode* root){
		if(!root->left_node)return root;
		else return FindMin(root->left_node);
	}
	BstNode* FindMax(BstNode* root){
		if(!root->right_node)return root;
		else return FindMax(root->right_node);
	}
	BstNode* DeleteRecursive(BstNode* root, int x)
	{
		if (!root) return root;
		else if (x < root->data) root->left_node = DeleteRecursive(root->left_node, x);
		else if (x > root->data) root->right_node = DeleteRecursive(root->right_node, x);
		else{ // Found matching node
			if (!root->left_node and !root->right_node){ // No Child
				delete root; // We deleted contents of root, but root still points to the same address which do not contain any data.
				root = nullptr;// root is dangling pointer. So, we assign it to nullptr.
			}
			else if (!root->left_node){// Only right child
				BstNode* temp = root;
				root = root->right_node;
				delete temp;
			}
			else if (!root->right_node){ // Only left child
				BstNode* temp = root;
				root = root->left_node;
				delete temp;
			}
			else{//Both left and right child present
				BstNode* temp = FindMin(root->right_node);
				root->data = temp->data;
				root->right_node = DeleteRecursive(root->right_node, temp->data);
			}
		}
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

int main()
{
	std::cout<<"***Binary Search Tree: Delete a Node***"<<std::endl;
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

	std::cout<<"Deleting 11"<<std::endl;
	head=head->DeleteRecursive(head, 11);
	LevelOrderTraverse(head);
}
