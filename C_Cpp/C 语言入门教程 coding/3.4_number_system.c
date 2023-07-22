//#include <stdio.h>
//
// BHD conversion
// number system

//int main()
//{
//	short a = 0b1010110; //二进制数
//	int b = 02713; //八进制数
//	long c = 0X1DAB83; //十六进制数
//
//	printf("八进制：a=%ho, b=%o, c=%lo\n", a, b, c); //以八进制形式输出
//	printf("十进制：a=%hd, b=%d, c=%ld\n", a, b, c); //以十进制形式输出
//	printf("十六小：a=%hx, b=%x, c=%lx\n", a, b, c); //以十六进制形式输出（字母小写）
//	printf("十六大：a=%hX, b=%X, c=%lX\n", a, b, c); //以十六进制形式输出（字母大写）
//
//	/* 在格式控制符中加上#即可输出不同进制的前缀 */
//	puts("\n输出不同进制并带前缀(十进制除外)：");
//	printf("八进制：a=%#ho, b=%#o, c=%#lo\n", a, b, c); //八进制输出
//	printf("十进制：a=%hd, b=%d, c=%ld\n", a, b, c); //十进制输出
//	printf("十六小：a=%#hx, b=%#x, c=%#lx\n", a, b, c); //十六进制（字母小写）
//	printf("十六大：a=%#hX, b=%#X, c=%#lX\n", a, b, c); //十六进制（字母大写）
//	puts("\n");
//
//	return 0;
//}