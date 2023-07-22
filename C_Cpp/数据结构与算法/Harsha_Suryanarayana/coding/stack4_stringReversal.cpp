// string reversal using stack

#include<iostream>
#include<stack>         // stack from standard template library (STL)
//#include<stdio.h>
using namespace std;


/* ����������һ����������ʵ�ֵ�ջ�������ǻ�������ʵ�ֵ�ջ����û�й�ϵ�� */
/* ��C���Ժ��������ԵĿ⺯����Ҳ�������ṩ��ջ��ʵ�֡�*/
/* �������У�������ȥʵ��ջ������ʹ�� C++ ��׼�⡣*/
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

void Reverse(char C[], int n) {   // �������Ὣ char C[] ���ͳ� char *C��
	stack<char> S;                // �������ʹ����ӵ����һ���ַ�ջ��

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
	// gets�в���ȫ�����⣬C11�ͱ���������:char *gets_s(char *str, rsize_t n); ͷ�ļ� stdio.h
	gets_s(C);
	Reverse(C, strlen(C));
	printf("Output = %s\n", C);
}