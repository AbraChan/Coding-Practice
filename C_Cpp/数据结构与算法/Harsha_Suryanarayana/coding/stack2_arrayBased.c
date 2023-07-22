// Stack - Array based implematation in C. 
//参考引用自github：https://gist.github.com/mycodeschool/6878252
//
//非动态Array的实现。
// 这并不是一个理想的实现。一个理想的实现是应该有一个数据类型（或者类）叫做 Stack。
// 我们应该可以创建它的实例。
// 我们用面向对象很容易实现它。
// 在 C 语言中可以使用结构体来实现它。

#include<stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];  // integer array to store the stack 
int top = -1;     // empty stack, variable to mark top of stack in array


// Push operation to insert an element on top of stack. 
void Push(int x) {
	//先处理可能是 full stack 时进行 push 出现的溢出(overflow)
	if (top == MAX_SIZE) {
		printf("Error: stack overflow\n");
		return;      //因为在这种情况下我们没有师兄动态数组，所以溢出情况下的Push不会插值成功
	}

	top++;
	A[top] = x;
	// 上述两条语句等价于：(下面的语句自增操作符++会发生在赋值操作符=之前
	// A[++top] = x;
}


// Pop operation to remove an element from top of stack.
void Pop() {
	//先处理可能是 empty stack 时进行 pop 的情况，此时不能进行 pop
	if (top == -1) {
		printf("Error: No element to pop\n");
	}
	top--;
}


// Top operation to return element at top of stack.
int Top() {
	return A[top];
}


// This function will return 1 (true) if stack is empty, 0 (false) otherwise
int IsEmpty(){
	if (top == -1) return 1;

	return 0;
}


// 以下 Print() 函数并不是典型的 Stack 的实现，这里只是为了测试程序用。
void Print() {
	int i;
	printf("Print Stack: ");
	for (i = 0; i <= top; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}



int main() {
	// Code to test the implementation. 
	// calling Print() after each push or pop to see the state of stack.

	Push(2);  Print();
	Push(5);  Print();
	Push(10); Print();
	Pop();    Print();
	Push(12); Print();

	return 0;
}