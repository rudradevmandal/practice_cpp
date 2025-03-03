/*
 * binary_search_tree_inorder_successor.cpp
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
void InOrderTraverse(BstNode* root){
	if(!root) return;
	InOrderTraverse(root->left_node);
	std::cout<<root->data<<", ";
	InOrderTraverse(root->right_node);
}

BstNode* Search(BstNode* root, int x){
	if(!root)return root;
	else if (x == root->data) return root;
	else if (x<=root->data) return Search(root->left_node,x);
	else return Search(root->right_node,x);
}

BstNode* FindMin(BstNode* root){
	if(!root->left_node)return root;
	else return FindMin(root->left_node);
}

BstNode* GetSuccessor(BstNode* root, int value){
	BstNode* current = Search(root, value); //O(h)
	if(!current) return current; //No Value Found
	if(current->right_node) return FindMin(current->right_node);//If current has right sub tree O(h)
	else{//No right Tree
		BstNode* successor = nullptr;
		BstNode* ancestor = root;
		while(ancestor != current){
			if (current->data <= root->data){
				if (root->left_node){
					successor = ancestor; // Save the current node before going to the left node, as left nodes are read for a node with no right tree
					ancestor = root->left_node; // Go to the next node
				}
			}
			else{
				ancestor = root->right_node;
			}
		}
		return successor;
	}
}

int main()
{
	// Space-Complexity O(height) worst: O(n) best: O(logn)
	// Time-Complexity O(h)
	std::cout<<"***Binary Search Tree: In-Order Successor***"<<std::endl;
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

	std::cout<<"***Binary Search Tree: In-order Traversal (left->root->right)***"<<std::endl;
	std::cout<<"***Expected DFS: 4, 5, 10, 11, 12, 15, 20, 20, 22, 22***"<<std::endl;
	std::cout<<"***Actual DFS: ";
	InOrderTraverse(head);
	std::cout<<"***"<<std::endl;
	std::cout<<std::endl;

	int value = 12;
	BstNode* successor = GetSuccessor(head, value);
	std::string successorValue = successor ? std::to_string(successor->data) : "nullptr";
	std::cout<<"Successor of value="<<value<<" is "<<successorValue<<std::endl;
	std::cout<<std::endl;

}




