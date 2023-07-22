//#include <stdio.h>

//int main() {
//	int arr[] = {99, 15, 100, 888, 252};
//	int len = sizeof(arr) / sizeof(int); //求数组的长度，即数组元素的个数
//	int i;
//	for (i = 0; i < len; i++) {
//		printf("%d ", *(arr+i) );  //*(arr+i) 等价于 arr[i] 
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
//		printf("%d ", *p++); //输出结果为：99 15 100 888 252
//		//printf("%d ", *++p); //输出结果为：15 100 888 252 -858993460
//	}
//	printf("\n");
//	return 0;
//}