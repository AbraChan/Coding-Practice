// Stack - Array based implematation in C. 
//�ο�������github��https://gist.github.com/mycodeschool/6878252
//
//�Ƕ�̬Array��ʵ�֡�
// �Ⲣ����һ�������ʵ�֡�һ�������ʵ����Ӧ����һ���������ͣ������ࣩ���� Stack��
// ����Ӧ�ÿ��Դ�������ʵ����
// ������������������ʵ������
// �� C �����п���ʹ�ýṹ����ʵ������

#include<stdio.h>

#define MAX_SIZE 101

int A[MAX_SIZE];  // integer array to store the stack 
int top = -1;     // empty stack, variable to mark top of stack in array


// Push operation to insert an element on top of stack. 
void Push(int x) {
	//�ȴ�������� full stack ʱ���� push ���ֵ����(overflow)
	if (top == MAX_SIZE) {
		printf("Error: stack overflow\n");
		return;      //��Ϊ���������������û��ʦ�ֶ�̬���飬�����������µ�Push�����ֵ�ɹ�
	}

	top++;
	A[top] = x;
	// �����������ȼ��ڣ�(������������������++�ᷢ���ڸ�ֵ������=֮ǰ
	// A[++top] = x;
}


// Pop operation to remove an element from top of stack.
void Pop() {
	//�ȴ�������� empty stack ʱ���� pop ���������ʱ���ܽ��� pop
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


// ���� Print() ���������ǵ��͵� Stack ��ʵ�֣�����ֻ��Ϊ�˲��Գ����á�
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