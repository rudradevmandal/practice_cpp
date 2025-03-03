/*
 * stack_reverse_a_string.cpp
 *
 *  Created on: 31-Jul-2022
 *      Author: rudra
 */

#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#define MAX_SIZE 101

class Stack {
public:
	int top = -1;
	char A[MAX_SIZE];

	void Push(char x){
		if(top == MAX_SIZE-1)std::cout<<"Stack Overflow"<<std::endl;
		A[++top] = x;
	}

	void Pop(){
		if(top == -1)std::cout<<"Stack Underflow"<<std::endl;
		top--;
	}

	char Top(){
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

void Reverse(char* C, size_t l)
{
	Stack s;
	for(size_t i=0; i<l; i++)s.Push(C[i]);
	for(size_t i=0; i<l; i++){
		C[i]=s.Top();
		s.Pop();
	}
}

void ReverseUsingStdStack(char* C, size_t l)
{
	std::stack<char> s;
	for(size_t i=0; i<l; i++)s.push(C[i]);
	for(size_t i=0; i<l; i++){
		C[i]=s.top();
		s.pop();
	}
}

int main() {
	std::cout<<"***Stack: Reverse a String***"<<std::endl;
	char C[101];
	std::cout<<"Enter a string to reverse:"<<std::endl;
	std::cin>>C;
	std::cout<<"Original String="<<C<<std::endl;
	Reverse(C, std::strlen(C));
	std::cout<<"Reversed String="<<C<<std::endl;
	ReverseUsingStdStack(C, std::strlen(C));
	std::cout<<"Reversed Again with std::stack String="<<C<<std::endl;
}




