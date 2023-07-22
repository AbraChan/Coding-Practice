// Linked List: Inserting a node at begining
// 本文件在 linkedList1_2.c 的基础上修改一些代码，但实现的是相同的功能。
// 变化点主要在 Insert() 函数

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;    // 在 C++ 中，这里应写成：Node* next;

};

//相比较于 linkedList1.c，这里注释掉这一句，改成在 main() 函数中定义
// struct Node* head;       // global variable, can be accessed anywhere


// Insert a node at the begining of linked list.
void Insert(struct Node** pointerToHead, int x)
{
	// struct Node** pointerToHead 是指向（存放链表的首节点地址的指针变量）head 的指针，即它是指针的指针
	// pointerToHead = &head，故 *pointerToHead 才等于 head 的值

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;                         // (*temp).data = x;
	// temp->next = NULL;                   // (*temp).next = NULL;有了下面这两句，这一句可以省略掉。

	if (*pointerToHead != NULL) temp->next = *pointerToHead;    // 因为是在开头插入节点，故新插入的节点的 next 字段要指向原来首节点的地址
	*pointerToHead = temp;

}

// Print all datas in the linked list
void Print(struct Node* head)
{
	// struct Node* temp = head;

	printf("The Linked List is:\n");
	while (head->next != NULL)      // 遍历整个链表
	{
		printf("%d", head->data);
		head = head->next;
	}
	printf("\n");
}




int main()
{
	struct Node* head = NULL;        // empty linked list;
	printf("How many numbers?\n");
	int n, i, x;
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter the data.\n");
		scanf_s("%d", &x);

		// head = Insert(head, x);    // linkedList1_2.c 当中的写法
		Insert(&head, x);             // &head 是指针变量 head 的地址，所以 Insert() 函数定义中这个形参应该是指针的指针。
		Print(head);
	}
}