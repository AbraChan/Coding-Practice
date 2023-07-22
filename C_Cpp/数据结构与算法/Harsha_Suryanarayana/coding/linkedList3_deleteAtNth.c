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
void Delete(int n);           // Delete a node at position n. �������ʵ����û��ȥ������Чλ�õ����������


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
		return;                 // ������� return ��䣬��ִ���� if(n==1)֮�󣬾Ͳ���ִ������Ĵ��롣
	}

	for (int i = 0; i < n - 2; i++)
		temp1 = temp1->next;

	// ��ʱ��temp1 points to (n-1)th Node
	struct Node* temp2 = temp1->next;        // temp2 points to nth Node.
	temp1->next = temp2->next;               // temp1 points to (n+1)th Node.
	free(temp2);                             // C++ ��д����delete temp2;
}


// Insert an integer at the end of the linked list
void Insert(int data)
{
	struct Node* newNode= (struct Node*)malloc(sizeof(struct Node));
	// ע�⣬sizeof(struct Node) �� sizeof(struct Node*) ��������ģ�����ֻ��һ��ָ��������ڴ��С�����ǽṹ�����͵��ڴ��С��
	newNode->data = data;
	newNode->next = NULL;

	if (head == NULL) {
		head = newNode;
		return;
	}

	struct Node* temp = head;
	while (temp->next != NULL)
	{
		// ���� while ��ѭ������������ Print() �����еĲ�ͬ������д�� temp != NULL��
		// ��Ȼ����ѭ��ʱ��temp == NULL, ��ʱ temp-> next = newNode �е� temp->next û�����塣
		temp = temp->next;
	}
	temp->next = newNode;              // ��ʱ temp ָ��ԭ��������һ���ڵ�
}


// Delete a node at position n. �������ʵ����û��ȥ������Чλ�õ����������
void Print()
{
	struct Node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
}