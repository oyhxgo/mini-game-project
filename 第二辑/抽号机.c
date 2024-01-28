#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<windows.h>
#include <string.h>
#define MAX_STUDENTS 100
//定义一个结构体，用于记住导入的学生名单
struct Student {
	char name[50];
	int seat_number;
};

int main()
{
	struct Student students[MAX_STUDENTS];
	srand(time(NULL));		//用时间作为种子，进行随机函数初始化.
	int generatedNumbers[100];
	int count = 0;
	for (int i = 0; i < 40; i++) 
	{
		int randomNumber;
		int isDuplicate;
		do {
			randomNumber = rand()%40; // 生成随机数
			isDuplicate = 0; // 默认不重复
			for (int j = 0; j < count; j++) {
				if (generatedNumbers[j] == randomNumber) {
					isDuplicate = 1; // 设置为重复
					break;
				}
			}
		} while (isDuplicate);
		generatedNumbers[count] = randomNumber; // 保存随机数
		count++;
	}
	
	//定义
	int a[1000];
	char l,o;
	int n,j,num_students;
	//这里是对导入学生名单的定义
	printf("请先导入学生名单，请告诉我你们班级的具体人数: ");
	scanf("%d", &num_students);
	// Input student information
	for (int i = 0; i < num_students; i++) 
	{
		scanf("%s", students[i].name);
		students[i].seat_number=i;
	}
	printf("好的，我记住了！！！\n");
	//这部分为随机抽号的主要实现形式
	printf("自动开启瞳孔识别\n");
	printf("识别成功，欢迎回来，尊贵的至尊超级无敌VIP用户\n");
	Sleep(500);
	printf("王子/公主大人，请您高抬贵手，输入本班需要的挑选的‘幸运儿’人数:");
	scanf("%d",&n);
	for(int p=0;p<n;p++)
		a[p]=generatedNumbers[p];
	Sleep(500);
	printf("已为您开启最强服务器，数据连接中。。（正在入侵班级系统，调用班级名单中....）\n");
	Sleep(4000);
	printf("解析成功！！！\n");
	Sleep(500);
	printf("为您挑选出以下%d位幸运儿,他们分别是：\n",n);
	for(int i=0;i<n;i++)
		{	
			j=a[i];
			printf("%d--%s\n",students[j].seat_number+1,students[j].name);
		}
		printf("您对结果是否还满意，若出现人员需调整问题，请按'Y',如果满意，请按其余任意键，程序将自动退出\n");
		scanf("%s",&l);
		o=1;
	while(o)
	{
		if(l=='Y'||l=='y')
		{
			srand(time(NULL));		//用时间作为种子，进行随机函数初始化.
			int generatedNumbers[100];
			int count = 0;
			for (int i = 0; i < 40; i++) 
			{
				int randomNumber;
				int isDuplicate;
				do {
					randomNumber = rand()%40; // 生成随机数
					isDuplicate = 0; // 默认不重复
					for (int j = 0; j < count; j++) {
						if (generatedNumbers[j] == randomNumber) {
							isDuplicate = 1; // 设置为重复
							break;
						}
					}
				} while (isDuplicate);
				generatedNumbers[count] = randomNumber; // 保存随机数
				count++;
			}
			for(int p=0;p<n;p++)
				a[p]=generatedNumbers[p];
			printf("重新为你生成结果\n");
			for(int i=0;i<n;i++)
		{	
			j=a[i];
			printf("%d--%s\n",students[j].seat_number+1,students[j].name);
		}
			printf("again？\n");
			scanf("%s",&l);
			if(l=='Y'||l=='y')
				o=1;
		}	
		else
		{
			printf("期待你的再次来临，公主大人/王子殿下！！！\n");
			o=0;
		}
	}
		return 0;

	
	
	
	
	
	
}
