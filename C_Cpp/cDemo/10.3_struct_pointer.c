/*����ȫ��ѧ�����ܳɼ���ƽ���ɼ���140�����µ�����*/
//#include <stdio.h>

//struct stu {
//	char *name; //����
//	int num; //ѧ��
//	int age; //����
//	char group; //����С��
//	float score; //�ɼ�
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
//	int len = sizeof(stus) / sizeof(struct stu); //�� suts ��Ԫ�ظ���
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
