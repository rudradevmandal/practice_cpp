/*
 * stack_reverse_a_linked_list.cpp
 *
 *  Created on: 31-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>
#include <stack>

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

void Reverse(Node** phead){
	std::stack<Node*> s;
	Node* temp = *phead;
	while(temp != nullptr){
		s.push(temp);
		temp = temp->next_node;
	}
	temp = s.top();
	*phead = temp;
	s.pop();
	while(!s.empty()){
		temp->next_node = s.top();
		s.pop();
		temp = temp->next_node;
	}
	temp->next_node = nullptr;
}

int main()
{
	std::cout<<"***Stack: Reverse a Linked List***"<<std::endl;
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

	Reverse(&head);
	std::cout<<"Reversed Linked List:"<<std::endl;
	head->Print();
}




