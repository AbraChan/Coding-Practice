#include <stdio.h>

int main()
{
	char str[] = "http://c.biancheng.net";

	//printf("%s\n", str);    // ʹ�� printf() ͨ���ַ����������
	//printf("%s\n", "http://c.biancheng.net");  //ֱ�����

	//puts(str);              // ʹ�� puts() ͨ���ַ����������
	//puts("http://c.biancheng.net");  //ֱ�����

	char str1[30] = { 0 };
	char str2[30] = { 0 };
	char str3[30] = { 0 };

	// gets() �÷�
	printf("Input a string: ");
	gets(str1);

	//scanf() �÷�
	printf("Input a string: ");
	scanf("%s", str2);
	scanf("%s", str3);

	puts(str1);
	puts(str2);
	puts(str3);

	return 0;
}