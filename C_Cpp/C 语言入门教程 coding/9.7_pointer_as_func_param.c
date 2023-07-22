//#include <stdio.h>

//void swap(int *p1, int *p2) {
//	int temp; //临时变量
//	temp = *p1;
//	*p1 = *p2;
//	*p2 = temp;
//}

//下面这种方式是无法实现变量a、b的值互换的。
//void swap(int a, int b) {
//	int temp; //临时变量
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
//	int i, maxValue = intArr[0]; //暂时假设第0个元素是最大值
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
//	puts("请分别输入6个整数：");
//	for (i = 0; i < len; i++) {
//		scanf("%d", nums+i); //这里要用地址，nums+i 和 &num[i] 等价。
//	}
//	printf("The max value in this array is %d!\n", max(nums, len));
//	
//	return 0;
//
//}