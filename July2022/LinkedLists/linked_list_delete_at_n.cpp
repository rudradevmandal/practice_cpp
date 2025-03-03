/*
 * linked_list_delete_at_n.cpp
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

	bool Delete(int p, Node** pHead)
	{
		if (p<1 or p>size)
		{
			std::cout<<"Wrong position entered."<<std::endl;
			return false;
		}
		Node* prev = *pHead;
		int count = 1;
		while (count<p-1) // Get the previous node
		{
			prev = prev->next_node;
			count++;
		}
		if (p == 1) // Delete at beginning
		{
			*pHead = prev->next_node;
			delete prev;
			size--;
			return true;
		}
		Node* temp = prev->next_node;
		prev->next_node = temp->next_node;
		delete temp;
		size--;
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
	std::cout<<"***Linked List: Delete a Node at Nth Position***"<<std::endl;
	std::cout<<"***Create Linked List: Insert a Node at Nth Position***"<<std::endl;
	Node* head = nullptr;// empty list
	for (int i = 1; i<10; i++)
	{
		if (!head->Insert(i, i, &head))
			break;
	}
	head->Print();//START-->[1]-->[2]-->[3]-->[4]-->[5]-->[6]-->[7]-->[8]-->[9]-->END

	std::cout<<"***Delete Linked List: Delete a Node at Nth Position***"<<std::endl;
	head->Delete(1, &head);
	head->Print();//START-->[2]-->[3]-->[4]-->[5]-->[6]-->[7]-->[8]-->[9]-->END
	head->Delete(2, &head);
	head->Print();//START-->[2]-->[4]-->[5]-->[6]-->[7]-->[8]-->[9]-->END
	head->Delete(1, &head);
	head->Print();//START-->[4]-->[5]-->[6]-->[7]-->[8]-->[9]-->END
	head->Delete(5, &head);
	head->Print();//START-->[4]-->[5]-->[6]-->[7]-->[9]-->END
}



