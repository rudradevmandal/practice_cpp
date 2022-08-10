/*
 * stack_check_balanced_parenthesis.cpp
 *
 *  Created on: 31-Jul-2022
 *      Author: rudra
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>

std::pair<char, char> e1('{', '}');
std::pair<char, char> e2('(', ')');
std::pair<char, char> e3('[', ']');

bool ifBalanced(char* C, size_t l){
	std::stack<char> s;
	for (size_t i=0; i<l; i++){
		if (C[i]==e1.first || C[i]==e2.first || C[i]==e3.first)s.push(C[i]);
		else if (C[i]==e1.second || C[i]==e2.second || C[i]==e3.second)
		{
			if (s.empty() or (std::make_pair(s.top(), C[i])!=e1 and std::make_pair(s.top(), C[i])!=e2 and std::make_pair(s.top(), C[i])!=e3))return false;
			else s.pop();
		}
	}
	return s.empty()?true:false;
}

int main() {
	std::cout<<"***Stack: Check for Balanced Parenthesis***"<<std::endl;
	char C[101];
	std::cout<<"Enter an expression:"<<std::endl;
	std::cin>>C;

	std::string isBalanced = ifBalanced(C, std::strlen(C))?"Balanced":"NOT Balanced";
	std::cout<<"Original Expression="<<C<<" is "<<isBalanced<<std::endl;
}
