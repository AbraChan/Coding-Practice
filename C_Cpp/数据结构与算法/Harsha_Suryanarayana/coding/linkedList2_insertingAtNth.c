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
	struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*));    // �µĽڵ���Ҫ�� heap �����ڴ����
	// Node* temp1 = new Node*;     //c++ ���������

	temp1->data = data;
	temp1->next = NULL;

	if (n == 1) 
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	struct Node* temp2 = head;
	// �� List: 4,5,2,3,5 ʱ Insert(6, 4)Ϊ������Ϊ n �Ǵ�1��ʼ�������� i �Ǵ�0��ʼ���������� i<n-2�������� i<n-1��
	// temp2 = head ʹ�� temp2 ָ�� n=1 
	// i=0ʱ��temp2 = temp2->next ʹ�� temp2 ָ�� n=2
	// i=1ʱ��temp2 = temp2->next ʹ�� temp2 ָ�� n=3
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
