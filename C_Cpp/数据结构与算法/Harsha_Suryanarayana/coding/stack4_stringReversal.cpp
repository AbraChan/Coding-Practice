// string reversal using stack

#include<iostream>
#include<stack>         // stack from standard template library (STL)
//#include<stdio.h>
using namespace std;


/* 这个类可以是一个基于数组实现的栈，或者是基于链表实现的栈，这没有关系。 */
/* 在C语言和其它语言的库函数中也给我们提供了栈的实现。*/
/* 本程序中，将不会去实现栈，而是使用 C++ 标准库。*/
/*
class Stack {
private:
char A[101];
int top;

public:
void Push(int x);
void Pop();
int Top();
bool IsEmpty();
};


void Reverse(char C[], int n){
Stack S;
}
*/

void Reverse(char C[], int n) {   // 编译器会将 char C[] 解释成 char *C。
	stack<char> S;                // 这条语句使我们拥有了一个字符栈。

								  // loop for push
	for (int i = 0; i < n; i++) {
		S.push(C[i]);
	}
	// loop for pop
	for (int i = 0; i < n; i++) {
		C[i] = S.top();          // overwrite the character at index i.
		S.pop();                 // perform pop.
	}
}

int main() {
	char C[51];
	printf("Enter a string: ");
	//gets(C); 
	// gets有不安全性问题，C11型编译器改用:char *gets_s(char *str, rsize_t n); 头文件 stdio.h
	gets_s(C);
	Reverse(C, strlen(C));
	printf("Output = %s\n", C);
}