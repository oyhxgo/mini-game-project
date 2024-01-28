#include"game.h"

void menu()
{
	printf("***************************\n");
	printf("*******1.  play   *********\n");
	printf("*******2.  exit   *********\n");
	printf("***************************\n");
}

void game()
{
	//创建两个字符数组
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//初始化数组
	rearray(mine,ROWS,COLS,'0');
	rearray(show, ROWS, COLS,'*');
	//打印棋盘
	displaybroad(show, ROW, COL);
	//布置雷
	setmine(mine,ROW,COL);
	//displaybroad(mine, ROW, COL);测试用
	//排查雷
	findmine(mine, show, ROW, COL);
}


int main()
{
	int a=0;
	srand((unsigned int)time(NULL));//以时间为种子的随机函数，强制类型转换为unsigned int；
	do {
		menu();
		printf("欢迎安装游戏，请输出数字代表操作：\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("欢迎来到扫雷游戏\n");
			game();
			break;
		case 2:
			printf("按任意键退出游戏!!!\n");
			a = 0;
			break;
		default:
			printf("键入错误，请重新选择！！！\n");
			break;
		}
	} while (a);
	return 0;
}