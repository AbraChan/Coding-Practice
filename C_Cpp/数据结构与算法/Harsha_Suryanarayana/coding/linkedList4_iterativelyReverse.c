/*----------------------------------------------------------------
Iteratively (Traverse) reverse a linked list
------------------------------------------------------------------*/


#include<stdio.h>
#include<stdlib.h>


struct Node
{
	int data;
	struct Node* next;
};

// struct Node* head;              // 当 head 设置为全局变量时，反转函数可以定义为 void Reverse(){...}


struct Node* Reverse(struct Node* head)
{
	struct Node  *current,
		         *prev,
		         *next;            // 注意，这里 next 是 Reverse() 中的局部变量，不会与 head->next 中的 next 字段冲突。

	current = head;
	prev = NULL;

	while (current != NULL)
	{
		next = current->next;      // 下一个节点的地址
		current->next = prev;      // 反转当前节点地址字段的指向
		prev = current;            // 更新 prev 使之沿原链表的指向往下顺移一个节点（即：指向此时的 current）
		current = next;            // 更新 current 使之沿原链表的指向往下顺移一个节点（即：指向此时的 next）

	}
	head = prev;                   // 当跳出 while 循环时，prev 指向原链表的最后一个节点，也即反转后的头结点
	return head;
}

// Insert data at the begining of linked list.
struct Node* Insert(struct Node* head, int data);

// Print the whole linked list.
void Print(struct Node* head);



int main()
{
	struct Node* head = NULL;     // local variable. main() 函数的局部变量，其它函数操作它需要通过函数参数来传递。
	head = Insert(head, 2);       // Insert: struct Node* Insert(struct Node*, int data)
	head = Insert(head, 4);
	head = Insert(head, 6);
	head = Insert(head, 8);
	Print(head);
	printf("\n");

	head = Reverse(head);
	Print(head);
	printf("\n");
}



struct Node* Insert(struct Node* head, int data)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}


void Print(struct Node* head)
{
	puts("Print the linked list:");
	while (head != NULL)
	{
		printf("%d ", head->data);
		head = head->next;
	}

}