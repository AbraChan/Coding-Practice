//#include <stdio.h>

//int main() {
//	int arr[] = {99, 15, 100, 888, 252};
//	int len = sizeof(arr) / sizeof(int); //������ĳ��ȣ�������Ԫ�صĸ���
//	int i;
//	for (i = 0; i < len; i++) {
//		printf("%d ", *(arr+i) );  //*(arr+i) �ȼ��� arr[i] 
//	}
//	printf("\n");
//	return 0;
//}

//int main() {
//	int arr[] = {99, 15, 100, 888, 252};
//	int *p = arr, len = sizeof(arr) / sizeof(int);
//	int i;
//
//	for (i = 0; i < len; i++) {
//		printf("%d ", *p++); //������Ϊ��99 15 100 888 252
//		//printf("%d ", *++p); //������Ϊ��15 100 888 252 -858993460
//	}
//	printf("\n");
//	return 0;
//}