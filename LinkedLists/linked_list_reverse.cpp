/*
 * linked_list_reverse.cpp
 *
 *  Created on: 30-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>

int size=0; //Stores the current size of the Linked list
class Node;//Forward Declaration
Node* globalHead;

class Node{
public:
	int data;
	Node* next_node;
	Node* head_node;
	bool Insert(int x, int p, Node** pHead)
	{
		if (p<=0 or p>size+1)
		{
			std::cout<<"Wrong position entered."<<std::endl;
			return false;
		}
		Node* temp = new Node();
		temp->data = x;
		temp->next_node = nullptr;
		Node* prev = *pHead;
		int count = 1;
		while (count<p-1) // Get the previous node
		{
			prev = prev->next_node;
			count++;
		}
		if (p == 1) // Insert at beginning
		{
			temp->next_node = prev;
			*pHead = temp;
			size++;
			return true;
		}
		temp->next_node = prev->next_node;
		prev->next_node = temp;
		size++;
		return true;
	}

	//Iterative Approach
	void Reverse(Node** pHead)
	{
		Node* curr = *pHead;
		Node* prev = nullptr;
		while (curr)
		{
			// Storing next->next_node in temp as 'next' will be pointing to first one after this
			Node* next = curr->next_node;
			curr->next_node = prev; // Reversing
			prev = curr;
			curr = next;
		}
		*pHead = prev;
	}
	//Recursive Approach
	Node* ReverseRecurse(Node* pHead)
	{
		Node* curr = pHead;
		if(!curr->next_node)
		{
			head_node = curr;
			return head_node;
		}
		ReverseRecurse(curr->next_node);
		Node* temp = curr->next_node;
		temp->next_node = curr;
		curr->next_node = nullptr;
		return head_node;
	}

	void Print()
	{
		Node* next = this;
		std::cout<<"START-->";
		while (next != nullptr)
		{
			std::cout<<"["<<next->data<<"]-->";
			next = next->next_node;
		}
		std::cout<<"END"<<std::endl;
	}
};

int main()
{
	std::cout<<"***Linked List: Reverse***"<<std::endl;
	std::cout<<"***Create Linked List: Insert a Node at Nth Position***"<<std::endl;
	Node* head = nullptr;// empty list
	for (int i = 1; i<10; i++)
	{
		if (!head->Insert(i, i, &head))
			break;
	}
	head->Print();//START-->[1]-->[2]-->[3]-->[4]-->[5]-->[6]-->[7]-->[8]-->[9]-->END

	std::cout<<"***Reverse Linked List***"<<std::endl;

//	head->Reverse(&head); //Iterative Approach
//	head->Print();//START-->[9]-->[8]-->[7]-->[6]-->[5]-->[4]-->[3]-->[2]-->[1]-->END

	head = head->ReverseRecurse(head); //Recursive Approach
	head->Print();//START-->[9]-->[8]-->[7]-->[6]-->[5]-->[4]-->[3]-->[2]-->[1]-->END
}




