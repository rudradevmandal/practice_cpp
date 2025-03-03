/*
 * linked_list_insert_at_start.cpp
 *
 *  Created on: 30-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>

class Node{
public:
	int data;
	Node* next_node;
	void Insert(int x, Node** pHead)
	{
		Node* temp = new Node();
		temp->data = x;
		temp->next_node = *pHead;
		*pHead = temp;
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
	std::cout<<"***Linked List: Insert a Node at the beginning***"<<std::endl;
	Node* head = nullptr;// empty list
	std::cout<<"How many numbers?"<<std::endl;
	int n, x;
	std::cin>>n;

	for (int i = 0; i<n; i++)
	{
		std::cout<<"Enter the numbers:"<<std::endl;
		std::cin>>x;
		head->Insert(x, &head);
	}
	head->Print();
}



