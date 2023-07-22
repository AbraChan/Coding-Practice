/*参考链接：http://c.biancheng.net/view/2035.html */

//#include <stdio.h>
//#include <stdlib.h>
//
//#define TOTAL 1 //总人数
//
//struct {
//	char name[20];
//	int num;
//	char sex;
//	char profession;
//
//	union {
//		float score;
//		char course[20];
//	} sc;
//} individuals[TOTAL];
//
//
//int main()
//{
//	int i;
//	//individuals[0] = { "HanXiaoXiao", 501, 'f', 's', 89.5 }; //在这里不可以用这种方式对结构体数组变量赋值，只有在定义的时候初始化才能用这种方式
//	
//	//individuals[0].name = "HanXiaoXiao";  //individuals[0].name = "HanXiaoXiao"; //individuals[0].name[] = "HanXiaoXiao"; 这三种方式都是错的
//	//因为字符数组只有在定义时才能将整个字符串一次性地赋值给它，一旦定义完了，就只能一个字符一个字符地赋值了。
//	individuals[0].name[0] = 'H', individuals[0].name[1] = 'a', individuals[0].name[2] = 'n';
//	individuals[0].name[3] = 'X', individuals[0].name[4] = 'i', individuals[0].name[5] = 'a', individuals[0].name[6]= 'o';
//	individuals[0].name[7] = 'X', individuals[0].name[8] = 'i', individuals[0].name[9] = 'a', individuals[0].name[10] = 'o';
//	//individuals[0].name[11] = '\n'; //这个不用自己加
//	individuals[0].num = 501;
//	individuals[0].sex = 'f';
//	individuals[0].profession = 's';
//	individuals[0].sc.score = 89.5;
//
//	printf("sizeof of individuals[0].name = %d\n", sizeof(individuals[0].name)); //20
//	printf("individuals[0].name = %#X\n", individuals[0].name);
//	printf("*individuals[0].name = %c\n", *individuals[0].name); //H
//	printf("individuals[0].name = %s\n", individuals[0].name); //HanXiaoXiao，无论上面有没有加 individuals[0].name[11] = '\n'; 都可以输出
//	printf("&individuals[0].name[0] = %s\n", &individuals[0].name[0]); //HanXiaoXiao
//	/*
//	//printf("*individuals[0].name = %s\n", *individuals[0].name); //这个语句无法输出，无论上面有没有加 individuals[0].name[11] = '\n';
//	//char *str = individuals[0].name;
//	//printf("%s\n", *str);  //这个语句无法输出，无论上面有没有加 individuals[0].name[11] = '\n';
//	//printf("%s\n", str);   //HanXiaoXiao，无论上面有没有加 individuals[0].name[11] = '\n'; 都可以输出
//	*/
//
//	//输入人员信息
//	//for (i = 0; i < TOTAL; i++)
//	//{
//	//	puts("Please input individual's information:");
//	//	scanf("%s %d %c %c", individuals[i].name, &(individuals[i].num), &(individuals[i].sex), &(individuals[i].profession));
//
//	//	if (individuals[i].profession == 's') //如果是学生
//	//	{
//	//		scanf("%f", &individuals[i].sc.score);
//	//	}
//	//	else  //如果是老师
//	//	{
//	//		scanf("%s", individuals[i].sc.course);
//	//	}
//
//	//	fflush(stdin);
//	//}
//
//	//输出人员信息
//	printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
//	for (i = 0; i < TOTAL; i++)
//	{
//		if (individuals[i].profession == 's') 
//		{
//			printf("%s\t%d\t%c\t%c\t\t%f\n", individuals[i].name, individuals[i].num, individuals[i].sex,
//				                           individuals[i].profession, individuals[i].sc.score);
//		}
//		else 
//		{
//			printf("%s\t%d\t%c\t%c\t\t%s\n", individuals[i].name, individuals[i].num, individuals[i].sex,
//				individuals[i].profession, individuals[i].sc.course);
//		}
//	}
//
//	return 0;
//}
