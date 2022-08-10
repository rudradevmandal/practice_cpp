/*
 * queue_implementaiton_linked_list.cpp
 *
 *  Created on: 31-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>

class Queue;
Queue* head_node;
Queue* tail_node;

class Queue {
public:
	int data;
	Queue* next_node;

	void Enqueue(int x)
	{
		Queue* temp = new Queue();
		temp->data = x;
		if (tail_node)tail_node->next_node = temp;
		tail_node = temp;
		if(!head_node)head_node=tail_node;
	}

	int Dequeue(){
		if (!head_node){
			std::cout<<"Stack Underflow"<<std::endl;
			return 0;
		}
		int a = head_node->data;
		if(head_node==tail_node){
			head_node=tail_node=nullptr;
			return a;
		}
		Queue* temp = head_node;
		head_node = temp->next_node;
		delete temp;
		return a;
	}

	int Front(){
		if (!head_node)std::cout<<"Stack Underflow"<<std::endl;
		return head_node->data;
	}

	int isEmpty(){
		if (!head_node and !tail_node)return true;
		return false;
	}

	void Print(){
		Queue* next = head_node;
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
	std::cout<<"***Queue: Linked List Implementation***"<<std::endl;
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(21);
	q.Dequeue();
	q.Enqueue(30);
	q.Enqueue(40);
	q.Print();
	std::cout<<"q.Front()="<<q.Front()<<", s.isEmpty()="<<q.isEmpty()<<std::endl;
}




