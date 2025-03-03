/*
 * queue_implementation_array.cpp
 *
 *  Created on: 31-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>
#define MAX_SIZE 4

class Queue
{
public:
	int front = -1;
	int back = -1;
	int A[MAX_SIZE];

	void Enqueue(int x)
	{
		if ((back + 1) % MAX_SIZE == front)
		{
			std::cout << "Queue Overflow" << std::endl;
			return;
		}
		++back;
		back %= MAX_SIZE;
		A[back] = x;
		if (front == -1)
			front++;
	}

	int Dequeue()
	{
		if (front == -1)
		{
			std::cout << "Queue Underflow" << std::endl;
			return 0;
		}
		int a = A[front];
		if (front == back)
		{
			front = back = -1;
			return a;
		}
		front++;
		front %= MAX_SIZE;
		return a;
	}

	int Front()
	{
		if (front == -1)
		{
			std::cout << "Queue Underflow" << std::endl;
			return 0;
		}
		return A[front];
	}

	bool isEmpty()
	{
		if (back == -1 and front == -1)
			return true;
		return false;
	}

	void Print()
	{
		std::cout << "front=" << front << ", back=" << back << std::endl;
		int i = front;
		while (i != back)
		{
			std::cout << "Position=" << i << ", Value=" << A[i] << std::endl;
			i++;
			i %= MAX_SIZE;
		}
		std::cout << "Position=" << i << ", Value=" << A[i] << std::endl; // Print the back element
	}
};

int main()
{
	std::cout << "***Queue: Circular Array implementation***" << std::endl;
	Queue q;
	q.Enqueue(10);
	q.Enqueue(20);
	q.Enqueue(21);
	q.Dequeue();
	q.Enqueue(30);
	q.Enqueue(40);
	q.Print();
	std::cout << "q.Front()=" << q.Front() << ", s.isEmpty()=" << q.isEmpty() << std::endl;
}
