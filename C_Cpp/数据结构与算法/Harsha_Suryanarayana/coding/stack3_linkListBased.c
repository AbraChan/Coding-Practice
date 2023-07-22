// Stack - Link List based implematation in C.
// 相对于基于 Array based 实现的 stack，用基于 Link List 实现的 stack，不用担心溢出的问题。
// 除非我们用尽了机器的内存。但是事实是，我们只在需要的时候使用内存，在不需要的时候就释放内存，
// 从某种程度来讲，这种 Push 和 Pop 的实现方式比数组更优雅。

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *link;
};


struct Node *top = NULL;  // empty stack
// top 在这里是一个全局变量，因此我们不需要向函数传入它，它对所有函数来说都是可以访问的。
// 在面向对象的实现中它可以是一个私有成员变量，在构造函数中可以把它设置为 NULL。


// 每次 Push 都是在 linked list 的首端插入一个 Node
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
