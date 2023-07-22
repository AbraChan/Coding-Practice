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
//	char *str1 = lines[1]; //lines[1]表示lines中第0个元素，它是字符串"COSC1283/1284"的首个字符的地址
//	char *str3 = *(lines + 3); //lines + 3 表示lines中第3个元素的地址，*(lines + 3) 才是表示lines中第3个元素，它是字符串"is"的首个字符的地址
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