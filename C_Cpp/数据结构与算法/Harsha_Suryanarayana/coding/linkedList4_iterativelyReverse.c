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

// struct Node* head;              // �� head ����Ϊȫ�ֱ���ʱ����ת�������Զ���Ϊ void Reverse(){...}


struct Node* Reverse(struct Node* head)
{
	struct Node  *current,
		         *prev,
		         *next;            // ע�⣬���� next �� Reverse() �еľֲ������������� head->next �е� next �ֶγ�ͻ��

	current = head;
	prev = NULL;

	while (current != NULL)
	{
		next = current->next;      // ��һ���ڵ�ĵ�ַ
		current->next = prev;      // ��ת��ǰ�ڵ��ַ�ֶε�ָ��
		prev = current;            // ���� prev ʹ֮��ԭ�����ָ������˳��һ���ڵ㣨����ָ���ʱ�� current��
		current = next;            // ���� current ʹ֮��ԭ�����ָ������˳��һ���ڵ㣨����ָ���ʱ�� next��

	}
	head = prev;                   // ������ while ѭ��ʱ��prev ָ��ԭ��������һ���ڵ㣬Ҳ����ת���ͷ���
	return head;
}

// Insert data at the begining of linked list.
struct Node* Insert(struct Node* head, int data);

// Print the whole linked list.
void Print(struct Node* head);



int main()
{
	struct Node* head = NULL;     // local variable. main() �����ľֲ�����������������������Ҫͨ���������������ݡ�
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