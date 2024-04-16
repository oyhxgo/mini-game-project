#include"Snake.h"


//定位函数
void Setpos(short x,short y)
{
	COORD pos = { x, y };
	HANDLE hOutput = NULL;
	//获取标准输出的句柄(⽤来标识不同设备的数值)
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	//设置标准输出上光标的位置为pos
	SetConsoleCursorPosition(hOutput, pos);
}
//欢迎界面
void Welcometogame()
{
	Setpos(36,10);
	printf("Welcome to Snake Game!\n");
	Setpos(36, 13);
	printf("欢迎来到贪吃蛇小游戏！\n");
	Setpos(38, 20);
	system("pause");
	system("cls");
	Setpos(24, 12);
	printf("用↑ . ↓ . ← . → 分别控制蛇的移动， F3为加速，F4为减速\n");
	Setpos(24, 13);
	printf("加速将能得到更高的分数。\n");
	Setpos(38, 20);//让按任意键继续的出现的位置好看点
	system("pause");
	system("cls");

}
void Creatmap()
{	
	system("color 03");
	//上
	Setpos(0, 0);
	for (int i = 0; i <= 56; i += 2)
	{
		wprintf(L"%c",Wall);
	}
	//下
	Setpos(0,25);
	for (int i = 0; i <= 56; i += 2)
	{
		wprintf(L"%c", Wall);
	}
	//左
	for (int i = 1; i <= 25; i++)//i++有坑
	{
		Setpos(0,i);
		wprintf(L"%lc", Wall);
	}
	//右
	for (int i = 1; i <= 25; i++)
	{
		Setpos(56, i);
		wprintf(L"%lc", Wall);
	}
}
void Initsnake(pSnake ps)
{
	pSnakeNode cur=NULL;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		cur = (pSnakeNode)malloc(sizeof(SnakeNode));//开辟空间
		if (cur == NULL)
		{
			perror("InitSnake():malloc():开辟空间失败");
			return;
		}
		cur->x = X + 2 * i;//横坐标每次移动两格
		cur->y = Y;//纵坐标不动
		cur->next = NULL;

		//头插法
		if (ps->pSnake == NULL)//第一个节点
		{
			ps->pSnake = cur;
		}
		else
		{
			cur->next = ps->pSnake;
			ps->pSnake = cur;
		}
	}
	//打印蛇身
	cur = ps->pSnake;
	while (cur)
	{

		Setpos(cur->x, cur->y);
		wprintf(L"%lc", Body);
		cur = cur->next;
	}
	//贪吃蛇的其他信息初始化
	ps->dir = RIGHT;
	ps->pFood = NULL;
	ps->Score = 0;
	ps->Sleeptime = 200;
	ps->status = OK;
	getchar();
}
//游戏开始的界面//游戏开始信息：
void Gamestart(pSnake ps)
{
	//1.设置控制台信息，窗口大小，窗口名
	system("mode con cols=100 lines=30");
	system("title 贪吃蛇");

	//2.隐藏光标
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursorInfo;
	GetConsoleCursorInfo(handle, &CursorInfo);
	CursorInfo.bVisible = false;
	SetConsoleCursorInfo(handle, &CursorInfo);
	//3.打印欢迎界面
	Welcometogame();
	//4.绘制地图
	Creatmap();
	//5.初始化蛇
	Initsnake(ps);//初始化需要修改所创建的蛇

}