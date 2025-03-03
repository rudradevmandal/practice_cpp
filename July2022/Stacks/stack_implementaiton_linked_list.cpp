/*
 * stack_implementaiton_linked_list.cpp
 *
 *  Created on: 30-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>

class Stack;
Stack* head_node;


class Stack {
public:
	int data;
	Stack* next_node;

	void Push(int x)
	{
		Stack* temp = new Stack();
		temp->data = x;
		temp->next_node = head_node;
		head_node = temp;
	}

	void Pop(){
		if (!head_node)std::cout<<"Stack Underflow"<<std::endl;
		Stack* temp = head_node;
		head_node = temp->next_node;
		delete temp;
	}

	int Top(){
		if (!head_node)std::cout<<"Stack Underflow"<<std::endl;
		return head_node->data;
	}

	int isEmpty(){
		if (head_node)return false;
		return true;
	}

	void Print(){
		Stack* next = head_node;
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
	std::cout<<"***Stack: Linked List Implementation***"<<std::endl;
	Stack s;
	s.Push(10);
	s.Push(20);
	s.Push(21);
	s.Pop();
	s.Push(30);
	s.Push(40);
	s.Print();
	std::cout<<"s.Top()="<<s.Top()<<", s.isEmpty()="<<s.isEmpty()<<std::endl;
}




