// Stack - Link List based implematation in C.
// ����ڻ��� Array based ʵ�ֵ� stack���û��� Link List ʵ�ֵ� stack�����õ�����������⡣
// ���������þ��˻������ڴ档������ʵ�ǣ�����ֻ����Ҫ��ʱ��ʹ���ڴ棬�ڲ���Ҫ��ʱ����ͷ��ڴ棬
// ��ĳ�̶ֳ����������� Push �� Pop ��ʵ�ַ�ʽ����������š�

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *link;
};


struct Node *top = NULL;  // empty stack
// top ��������һ��ȫ�ֱ�����������ǲ���Ҫ�������������������к�����˵���ǿ��Է��ʵġ�
// ����������ʵ������������һ��˽�г�Ա�������ڹ��캯���п��԰�������Ϊ NULL��


// ÿ�� Push ������ linked list ���׶˲���һ�� Node
void Push(int x) {
	struct Node *temp = (struct Node*) malloc(sizeof(struct Node*));
	temp->data = x;
	temp->link = top;
	top = temp;
}


//
void Pop(){
	struct Node *temp;
	if (top == NULL) return;
	temp = top;
	top = top->link;
	free(temp);
}


int Top() {
	return top->data;
}


int IsEmpty() {
	if (top == NULL) return 1;
	return 0;
}


void Print() {
	struct Node *temp;
	temp = top;
	printf("Stack: ");
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}


int main() {
	printf("%d\n", IsEmpty());
	Push(2);  Print();
	printf("%d\n", IsEmpty());
	
	/*Push(2);  Print();
	Push(5);  Print();
	Push(10); Print();
	Pop();    Print();
	Push(12); Print();*/

	return 0;
}
