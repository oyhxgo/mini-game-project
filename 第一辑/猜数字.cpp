#include<bits/stdc++.h>
int main()
{
	srand(time(NULL));              //以时间为种子；
	int a=rand()%1000,n;    //这里是使生成的随机数在0-1000之间
	printf("欢迎来到王者猜数字！\n游戏开始！！\n请在0-1000猜一个数字：\n");
	scanf("%d",&n);
	while(1)
	{
	
		if(n>a)
		{
			printf("好像有点大，往小的猜：");
			scanf("%d",&n);
		}
		if(n<a)
		{
			printf("好像有点小，往大猜：");
			scanf("%d",&n);
		}
		if(n==a)
		{
			printf("哈哈，猜对了，你跟我想得一样！！!");
			break;
		}
	}
	return 0;
}
//
//
////数字排序--------便于理解冒泡排序
//#include<bits/stdc++.h>//包含所有的头文件 
//int main()
//{
//	srand(time(NULL));
//	int a,b[10000],p,l=0;
//	scanf("%d",&a);//输入冒泡数字量 
//	for(int i=1;i<=a;i++)
//	{
//		b[i]=rand()%100;
//	}
//	printf("由于您已是vip，自动为您生成随机数：\n");
//	for(int i=1;i<=a;i++)
//		printf("%4d",b[i]);//%4d适合人看 
//	printf("\n");
//	for(int j=1;j<=a;j++)//进行几轮冒泡 
//	{
//		for(int k=1;k<=a;k++)
//		{
//			if(b[k]>b[k+1])
//			{
//				p=b[k];
//				b[k]=b[k+1];
//				b[k+1]=p;
//			}
//		}	
//		printf("第%d轮:",j);
//		for(int k=1;k<=a;k++)
//		printf("%4d",b[k]);//%4d适合人看 
//	printf("\n");
//		
//	}
//} 
