/*======================================================================

Doubly Linked List implementation.

参考引用自github：https://gist.github.com/mycodeschool/7429492
========================================================================*/


#include<stdio.h>
#include<stdlib.h>


struct Node 
{
	int data;
	struct Node *next,
		        *prev;
};

struct Node* head;                // global variable - pointer to head node


struct Node* CreateNewNode(int x)
{
	/*
	// local variable, will be cleared from memory when function call will finish
	// 这就是为什么我们在动态内存或所谓的 heap 内存来分配内存。除非我们显式地释放变量来清除堆中的内容。
	// 对堆内存的访问始终通过指针变量进行。
	struct Node myNode;
	myNode.data = x;
	myNode.prev = NULL;
	myNode.next = NULL;
	*/

	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;           // (*newNode).data = x;
	newNode->prev = NULL;        // (*newNode).prev = NULL;
	newNode->next = NULL;        // (*newNode).next = NULL;

	return newNode;
}


void InsertAtHead(int x)
{
	struct Node* newNode = CreateNewNode(x);

	if (head == NULL)
	{
		head = newNode;
		return;
	}

	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}



// InsertAtTail(int x);      // 这里没有进行实现


void Print()
{
	struct Node* temp = head;
	puts("Print Forward:");
	while(temp != NULL)             // 循环结束时 temp 指向 NULL （最后一个节点的 next 字段值为 NULL）
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}


void ReversePrint()
{
	struct Node* temp = head;
	if (temp == NULL) return;       // Empty list, exit.
	
	// Going to last Node.
	// 注意，这里 while 的条件和上面 Print() 中 while 的条件不一样
	while (temp->next != NULL)      // 循环结束时 temp 指向最后一个节点的地址
	{
		temp = temp->next;
	}

	// Traversing backward using prev pointer.
	puts("Print Reversely:");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}



int main()
{
	head = NULL;

	InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();

}