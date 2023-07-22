/*计算全班学生的总成绩、平均成绩和140分以下的人数*/
//#include <stdio.h>

//struct stu {
//	char *name; //姓名
//	int num; //学号
//	int age; //年龄
//	char group; //所在小组
//	float score; //成绩
//} stus[] = {
//	{"Zhou ping", 5, 18, 'C', 145.0},
//	{"Zhang ping", 4, 19, 'A', 130.5},
//	{"Liu fang", 1, 18, 'A', 148.5},
//	{"Cheng ling", 2, 17, 'F', 139.0},
//	{"Wang ming", 3, 17, 'B', 144.5}
//};
//
//void average(struct stu *pstus, int len);
//
//int main() 
//{
//	int len = sizeof(stus) / sizeof(struct stu); //求 suts 的元素个数
//	average(stus, len);
//	
//	return 0;
//}
//
//void average(struct stu *pstus, int len)
//{
//	int i, num_under_140 = 0;
//	float average, sum = 0;
//
//	for (i = 0; i < len; i++)
//	{
//		sum += (pstus + i)->score;
//		if ((pstus+i)->score < 140)num_under_140++;
//	}
//	average = sum / len;
//	printf("sum=%.2f\naverage=%.2f\nnum_under_140=%d\n", sum, average, num_under_140);
//}
