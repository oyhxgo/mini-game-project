#include<bits/stdc++.h>
int main()
{
	srand(time(NULL));              //��ʱ��Ϊ���ӣ�
	int a=rand()%1000,n;    //������ʹ���ɵ��������0-1000֮��
	printf("��ӭ�������߲����֣�\n��Ϸ��ʼ����\n����0-1000��һ�����֣�\n");
	scanf("%d",&n);
	while(1)
	{
	
		if(n>a)
		{
			printf("�����е����С�Ĳ£�");
			scanf("%d",&n);
		}
		if(n<a)
		{
			printf("�����е�С������£�");
			scanf("%d",&n);
		}
		if(n==a)
		{
			printf("�������¶��ˣ���������һ������!");
			break;
		}
	}
	return 0;
}
//
//
////��������--------�������ð������
//#include<bits/stdc++.h>//�������е�ͷ�ļ� 
//int main()
//{
//	srand(time(NULL));
//	int a,b[10000],p,l=0;
//	scanf("%d",&a);//����ð�������� 
//	for(int i=1;i<=a;i++)
//	{
//		b[i]=rand()%100;
//	}
//	printf("����������vip���Զ�Ϊ�������������\n");
//	for(int i=1;i<=a;i++)
//		printf("%4d",b[i]);//%4d�ʺ��˿� 
//	printf("\n");
//	for(int j=1;j<=a;j++)//���м���ð�� 
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
//		printf("��%d��:",j);
//		for(int k=1;k<=a;k++)
//		printf("%4d",b[k]);//%4d�ʺ��˿� 
//	printf("\n");
//		
//	}
//} 
