/*
 * stack_implementation.cpp
 *
 *  Created on: 30-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>
#define MAX_SIZE 101

class Stack {
public:
	int top = -1;
	int A[MAX_SIZE];

	void Push(int x){
		if(top == MAX_SIZE-1)std::cout<<"Stack Overflow"<<std::endl;
		A[++top] = x;
	}

	void Pop(){
		if(top == -1)std::cout<<"Stack Underflow"<<std::endl;
		top--;
	}

	int Top(){
		if(top == -1)std::cout<<"Stack Underflow"<<std::endl;
		return A[top];
	}

	bool isEmpty(){
		if(top == -1) return true;
		return false;
	}

	void Print(){
		for(int i=0; i<=top; i++)std::cout<<"Position="<<i<<", Value="<<A[i]<<std::endl;
	}
};

int main() {
	std::cout<<"***Stack: Array implementation***"<<std::endl;
	Stack s;
	s.Push(10);
	s.Push(20);
	s.Push(21);
	s.Pop();
	s.Push(30);
	s.Push(40);
	s.Print();
}



