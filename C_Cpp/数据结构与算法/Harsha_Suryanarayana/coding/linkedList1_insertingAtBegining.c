// Linked List: Inserting a node at begining

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;    // 在 C++ 中，这里应写成：Node* next;

};

struct Node* head;       // global variable, can be accessed anywhere


						 // Insert a node at the begining of linked list.
void Insert(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;                         // (*temp).data = x;
	// temp->next = NULL;                   // (*temp).next = NULL;有了下面这两句，这一句可以省略掉。

	if (head != NULL) temp->next = head;    // 因为是在开头插入节点，故新插入的节点的 next 字段要指向原来首节点的地址
	head = temp;
}

// Print all datas in the linked list
void Print()
{
	struct Node* temp = head;

	printf("The Linked List is:\n");
	while (temp->next != NULL)      // 遍历整个链表
	{
		printf("%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}




int main()
{
	head = NULL;        // empty linked list;
	printf("How many numbers?\n");
	int n, i, x;
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter the data.\n");
		scanf_s("%d", &x);

		Insert(x);
		Print();
	}
}