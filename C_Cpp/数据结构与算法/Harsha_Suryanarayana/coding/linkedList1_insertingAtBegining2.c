// Linked List: Inserting a node at begining
// ���ļ��� linkedList1.c �Ļ������޸�һЩ���룬��ʵ�ֵ�����ͬ�Ĺ��ܡ�

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;    // �� C++ �У�����Ӧд�ɣ�Node* next;

};

//��Ƚ��� linkedList1.c������ע�͵���һ�䣬�ĳ��� main() �����ж���
// struct Node* head;       // global variable, can be accessed anywhere


// Insert a node at the begining of linked list.
struct Node* Insert(struct Node* head, int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;                         // (*temp).data = x;
	// temp->next = NULL;                   // (*temp).next = NULL;�������������䣬��һ�����ʡ�Ե���

	if (head != NULL) temp->next = head;    // ��Ϊ���ڿ�ͷ����ڵ㣬���²���Ľڵ�� next �ֶ�Ҫָ��ԭ���׽ڵ�ĵ�ַ
	head = temp;

	return head;
}

// Print all datas in the linked list
void Print(struct Node* head)
{
	// struct Node* temp = head;

	printf("The Linked List is:\n");
	while (head->next != NULL)      // ������������
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

		head = Insert(head, x);
		Print(head);
	}
}