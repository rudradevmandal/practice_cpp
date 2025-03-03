/*
 * linked_list_insert_at_n.cpp
 *
 *  Created on: 30-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>

int size=0; //Stores the current size of the Linked list

class Node{
public:
	int data;
	Node* next_node;
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
	std::cout<<"***Linked List: Insert a Node at Nth Position***"<<std::endl;
	Node* head = nullptr;// empty list
	std::cout<<"How many numbers?"<<std::endl;
	int n, x, p;
	std::cin>>n;

	for (int i = 0; i<n; i++)
	{
		std::cout<<"Enter the numbers:"<<std::endl;
		std::cin>>x;
		std::cout<<"Enter the position from 1 to n:"<<std::endl;
		std::cin>>p;
		if (!head->Insert(x, p, &head))
			break;
		if(head)head->Print();
	}
}




