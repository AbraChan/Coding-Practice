//#include <stdio.h>

//int main() {
//	char *lines[5] = {
//		"COSC1283/1284",
//		"Programming",
//		"Techniques",
//		"is",
//		"great fun"
//	};
//
//	char *str1 = lines[1]; //lines[1]��ʾlines�е�0��Ԫ�أ������ַ���"COSC1283/1284"���׸��ַ��ĵ�ַ
//	char *str3 = *(lines + 3); //lines + 3 ��ʾlines�е�3��Ԫ�صĵ�ַ��*(lines + 3) ���Ǳ�ʾlines�е�3��Ԫ�أ������ַ���"is"���׸��ַ��ĵ�ַ
//	
//	char c1 = *(*(lines + 4) + 6);
//	char c2 = (*lines + 5)[5];
//	char c3 = *lines[0] + 2;
//
//	printf("str1 = %s\n", str1);
//	printf("str2 = %s\n", str3);
//	printf("  c1 = %c\n", c1);
//	printf("  c2 = %c\n", c2);
//	printf("  c3 = %c\n", c3);
//
//	return 0;
//}