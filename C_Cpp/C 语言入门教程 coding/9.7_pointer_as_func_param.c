//#include <stdio.h>

//void swap(int *p1, int *p2) {
//	int temp; //��ʱ����
//	temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}

//�������ַ�ʽ���޷�ʵ�ֱ���a��b��ֵ�����ġ�
//void swap(int a, int b) {
//	int temp; //��ʱ����
//	temp = a;
//	a = b;
//	b = temp;
//}

//int main() {
//	int a = 66, b = 99;
//	swap(&a, &b);
//	printf("a=%d, b=%d\n", a, b);
//
//	return 0;
//}

//int max(int *intArr, int len) {
//	int i, maxValue = intArr[0]; //��ʱ�����0��Ԫ�������ֵ
//	for (i = 0; i < len; i++) {
//		if (maxValue < intArr[i]){
//			maxValue = intArr[i];
//		}
//	}
//	return maxValue;
//}
//
//int main() {
//	int nums[6], i;
//	int len = sizeof(nums) / sizeof(int);
//
//	puts("��ֱ�����6��������");
//	for (i = 0; i < len; i++) {
//		scanf("%d", nums+i); //����Ҫ�õ�ַ��nums+i �� &num[i] �ȼۡ�
//	}
//	printf("The max value in this array is %d!\n", max(nums, len));
//	
//	return 0;
//
//}