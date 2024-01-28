
#include"game.h"

void rearray(char a[ROWS][COLS],int rows,int cols,char set)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols;j++)
		{
			a[i][j] = set;
		}
	}
}

void displaybroad(char a[ROWS][COLS], int row, int col)
{
	printf("************扫雷*************\n");
	for (int i = 0; i <=row; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
	printf("************扫雷*************\n");


}


void setmine(char a[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EASY;
	while (count)
	{
		int x = rand() % row + 1;//1-9(原本0-8)
		int y = rand() % col + 1;
		if (a[x][y] == '0')//判定是否已经是雷，防止重复set mine
		{
			a[x][y] = '1';
			count--;//满足设雷条件则雷减1
		}
	}
}

static int getminecount(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y + 1]
		+ mine[x][y + 1] + mine[x + 1][y] + mine[x - 1][y + 1] - 8 * '0');


}

void findmine(char a[ROWS][COLS], char b[ROWS][COLS], int row, int col)
{

	int win = 0;
	while (win < row * col - EASY)
	{
			int x = 0;
			int y = 0;
			printf("请输入您要排查的坐标：>\n");
			scanf("%d %d", &x, &y);
			if (b[x][y] != '*')
			{
				printf("键入重复，请重新键入！！！\n");
				continue;
			}
			else if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
		

				if (a[x][y] == '1')
				{
					printf("很遗憾，你被炸死了！！！\n");
					displaybroad(a, ROW, COL);
					break;
				}
				else
				{
					int count= getminecount(a, x, y);//获取雷的个数
					b[x][y] = count + '0';//导入雷的个数
					displaybroad(b, ROW, COL);//打印
					win++;
				}
			}
			else
			{
				printf("键入错误，坐标非法，请重新输入坐标：>\n");
			}
		
	}
	if (win == row * col - EASY)
	{
		printf("恭喜你，排雷成功！！！\n");
		displaybroad(b, ROW, COL);//打印
		printf("下面为您重新返回菜单\n");
	}
}
