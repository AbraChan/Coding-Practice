// Linked List: Inserting a node at begining
// ���ļ��� linkedList1_2.c �Ļ������޸�һЩ���룬��ʵ�ֵ�����ͬ�Ĺ��ܡ�
// �仯����Ҫ�� Insert() ����

#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node* next;    // �� C++ �У�����Ӧд�ɣ�Node* next;

};

//��Ƚ��� linkedList1.c������ע�͵���һ�䣬�ĳ��� main() �����ж���
// struct Node* head;       // global variable, can be accessed anywhere


// Insert a node at the begining of linked list.
void Insert(struct Node** pointerToHead, int x)
{
	// struct Node** pointerToHead ��ָ�򣨴��������׽ڵ��ַ��ָ�������head ��ָ�룬������ָ���ָ��
	// pointerToHead = &head���� *pointerToHead �ŵ��� head ��ֵ

	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = x;                         // (*temp).data = x;
	// temp->next = NULL;                   // (*temp).next = NULL;�������������䣬��һ�����ʡ�Ե���

	if (*pointerToHead != NULL) temp->next = *pointerToHead;    // ��Ϊ���ڿ�ͷ����ڵ㣬���²���Ľڵ�� next �ֶ�Ҫָ��ԭ���׽ڵ�ĵ�ַ
	*pointerToHead = temp;

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

		// head = Insert(head, x);    // linkedList1_2.c ���е�д��
		Insert(&head, x);             // &head ��ָ����� head �ĵ�ַ������ Insert() ��������������β�Ӧ����ָ���ָ�롣
		Print(head);
	}
}