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
	// ���ݹ���õ� p Ϊ���һ���ڵ��ָ��ʱ��ִ�� if����ʱ��һ�� Reverse(p->next) �����е�pΪ�����ڶ����ڵ��ָ��
	if (p->next == NULL)          // exit condition,
	{
		head = p;
		return;
	}

	Reverse(p->next);

	// ����ĵݹ���ý�����������һ�㺯���󽫴Ӹò㺯���е�������俪ʼִ�С�
	// ��ʱ p Ϊ�ò�ڵ��ָ��
	struct Node* temp = p->next;     // temp Ϊ�ò�ڵ㣨��pָ��Ľڵ㣩��ԭ�����е���һ���ڵ��ָ��
	temp->next = p;                  // ��ת�ֶ� temp-next ��ָ��ָ�� temp ��ָ��ڵ���ԭ�����е���һ���ڵ�
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