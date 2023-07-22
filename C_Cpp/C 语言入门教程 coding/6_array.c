#include <stdio.h>

int main()
{
	char str[] = "http://c.biancheng.net";

	//printf("%s\n", str);    // 使用 printf() 通过字符串名字输出
	//printf("%s\n", "http://c.biancheng.net");  //直接输出

	//puts(str);              // 使用 puts() 通过字符串名字输出
	//puts("http://c.biancheng.net");  //直接输出

	char str1[30] = { 0 };
	char str2[30] = { 0 };
	char str3[30] = { 0 };

	// gets() 用法
	printf("Input a string: ");
	gets(str1);

	//scanf() 用法
	printf("Input a string: ");
	scanf("%s", str2);
	scanf("%s", str3);

	puts(str1);
	puts(str2);
	puts(str3);

	return 0;
}