//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

//int main() {
//	char *str = "http://c.biancheng.net";
//	int len = strlen(str), i;
//
//	//ֱ������ַ���
//	printf("%s\n", str);
//	//ʹ��*(str+i)�ַ���
//	for (i = 0; i < len; i++) {
//		printf("%c", *(str + i));
//	}
//	printf("\n");
//
//	//ʹ��str[i]����ַ���
//	for (i = 0; i < len; i++) {
//		printf("%c", str[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

//int main() {
//	char *str = "Hello World!";
//	printf("%s\n", str);
//
//	str = "I Love C!"; //��ȷ
//	printf("%s\n", str);
//
//	//str[3] = 'P';
//	printf("%c\n", str[3]);
//
//	return 0;
//}


//int main() {
//	char str[20] = { 0 };
//	int i;
//
//	for (i = 0; i < 10; i++) {
//		*(str + i) = 97 + i; //97 Ϊ�ַ�a��ASCII��ֵ
//	}
//
//	printf("%s\n", str);
//	printf("%s\n\n", str + 2);
//
//	printf("%c\n", str + 2);
//	printf("%#X\n", str + 2);
//	printf("%c\n\n", *(str + 2));
//
//	printf("%c\n", str[2]);
//	printf("%c\n", (str + 2)[2]);
//
//	return 0;
//}