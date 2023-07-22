/*======================================================================

Doubly Linked List implementation.

�ο�������github��https://gist.github.com/mycodeschool/7429492
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
	// �����Ϊʲô�����ڶ�̬�ڴ����ν�� heap �ڴ��������ڴ档����������ʽ���ͷű�����������е����ݡ�
	// �Զ��ڴ�ķ���ʼ��ͨ��ָ��������С�
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



// InsertAtTail(int x);      // ����û�н���ʵ��


void Print()
{
	struct Node* temp = head;
	puts("Print Forward:");
	while(temp != NULL)             // ѭ������ʱ temp ָ�� NULL �����һ���ڵ�� next �ֶ�ֵΪ NULL��
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
	// ע�⣬���� while ������������ Print() �� while ��������һ��
	while (temp->next != NULL)      // ѭ������ʱ temp ָ�����һ���ڵ�ĵ�ַ
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