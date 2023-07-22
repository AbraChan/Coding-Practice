// Linked List: Inserting a node at nth position

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Node* head;


// Insert a data in at the nth position of the linked list
void Insert(int data, int n)
{
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));    // 新的节点需要在 heap 分配内存给它
	// Node* temp1 = new Node*;     //c++ 里面的做法

	temp1->data = data;
	temp1->next = NULL;

	if (n == 1) 
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	struct Node* temp2 = head;
	// 以 List: 4,5,2,3,5 时 Insert(6, 4)为例，因为 n 是从1开始计数，而 i 是从0开始计数，故是 i<n-2，而不是 i<n-1。
	// temp2 = head 使得 temp2 指向 n=1 
	// i=0时，temp2 = temp2->next 使得 temp2 指向 n=2
	// i=1时，temp2 = temp2->next 使得 temp2 指向 n=3
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;


}


// Print all elements in the linked list
void Print()
{
	struct Node* temp = head;
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}



int main()
{
	head = NULL;  // empty list
	Insert(2, 1); // List: 2
	Insert(3, 2); // List: 2,3
	Insert(4, 1); // List: 4,2,3
	Insert(5, 2); // List: 4,5,2,3
	Insert(5, 5); // List: 4,5,2,3,5
	Insert(6, 4); // List: 4,5,2,6,3,5

	Print();
}
