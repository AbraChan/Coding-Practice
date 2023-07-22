// Linked List: Delete a node at nth position.

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
struct Node* head;

void Insert(int data);        // Insert an integer at the end of the linked list
void Print();                 // Print all elements in the linked list
void Delete(int n);           // Delete a node at position n. 在这里的实现中没有去处理无效位置的这种情况。


int main()
{
	head = NULL;    // Empty list
	Insert(2);
	Insert(4);
	Insert(6);
	Insert(5);      // List: 2,4,6,5
	Print();        // Print the whole linked list

	int n;
	printf("Please Enter the postion you want to delete.\n");
	scanf_s("%d", &n);
	Delete(n);
	Print();
}



// Delete node at position n
void Delete(int n)
{
	struct Node* temp1 = head;

	if (n == 1) {
		head = temp1->next;     // head now points to the 2nd Node.
		free(temp1);
		return;                 // 有了这个 return 语句，当执行完 if(n==1)之后，就不会执行下面的代码。
	}

	for (int i = 0; i < n - 2; i++)
		temp1 = temp1->next;

	// 此时，temp1 points to (n-1)th Node
	struct Node* temp2 = temp1->next;        // temp2 points to nth Node.
	temp1->next = temp2->next;               // temp1 points to (n+1)th Node.
	free(temp2);                             // C++ 的写法：delete temp2;
}


// Insert an integer at the end of the linked list
void Insert(int data)
{
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	// 注意，sizeof(struct Node) 和 sizeof(struct Node*) 是有区别的！后者只是一个指针变量的内存大小，不是结构体类型的内存大小。
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return;
	}

	struct Node* temp = head;
	while (temp->next != NULL)
	{
		// 这里 while 的循环条件与下面 Print() 函数中的不同，不能写成 temp != NULL，
		// 不然结束循环时，temp == NULL, 此时 temp-> next = newNode 中的 temp->next 没有意义。
		temp = temp->next;
	}
	temp->next = newNode;              // 此时 temp 指向原链表的最后一个节点
}


// Delete a node at position n. 在这里的实现中没有去处理无效位置的这种情况。
void Print()
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}