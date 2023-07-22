/*-------------------------------------------------
Reverse a Linked List using Recursion
---------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>


struct Node 
{
	int data;
	struct Node* next;
};

struct Node* head;


void Reverse(struct Node* p)
{
	// 当递归调用到 p 为最后一个节点的指针时，执行 if，此时上一层 Reverse(p->next) 参数中的p为倒数第二个节点的指针
	if (p->next == NULL)          // exit condition,
	{
		head = p;
		return;
	}

	Reverse(p->next);

	// 各层的递归调用结束，返回上一层函数后将从该层函数中的以下语句开始执行。
	// 此时 p 为该层节点的指针
	struct Node* temp = p->next;     // temp 为该层节点（即p指向的节点）在原链表中的下一个节点的指针
	temp->next = p;                  // 反转字段 temp-next 的指向，指回 temp 所指向节点在原链表中的上一个节点
	p->next = NULL;
}


void Print()
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}


// Insert data at the end of Linked List.
Insert(int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	(*temp).data = data;
	temp->next = NULL;

	if (head == NULL) head = temp;
	else
	{
		struct Node* temp1 = head;
		while (temp1->next != NULL) temp1 = temp1->next;
		temp1->next = temp;
	}
}



int main()
{
	head = NULL;
	
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);
	puts("Original Linked List:");
	Print();
	printf("\n");
	Reverse(head);
	puts("Reversed by recursion:");
	Print();
	printf("\n");
}