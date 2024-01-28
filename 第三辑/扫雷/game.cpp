
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
	printf("************ɨ��*************\n");
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
	printf("************ɨ��*************\n");


}


void setmine(char a[ROWS][COLS], int row, int col)
{
	//����10����
	int count = EASY;
	while (count)
	{
		int x = rand() % row + 1;//1-9(ԭ��0-8)
		int y = rand() % col + 1;
		if (a[x][y] == '0')//�ж��Ƿ��Ѿ����ף���ֹ�ظ�set mine
		{
			a[x][y] = '1';
			count--;//���������������׼�1
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
			printf("��������Ҫ�Ų�����꣺>\n");
			scanf("%d %d", &x, &y);
			if (b[x][y] != '*')
			{
				printf("�����ظ��������¼��룡����\n");
				continue;
			}
			else if (x >= 1 && x <= row && y >= 1 && y <= col)
			{
		

				if (a[x][y] == '1')
				{
					printf("���ź����㱻ը���ˣ�����\n");
					displaybroad(a, ROW, COL);
					break;
				}
				else
				{
					int count= getminecount(a, x, y);//��ȡ�׵ĸ���
					b[x][y] = count + '0';//�����׵ĸ���
					displaybroad(b, ROW, COL);//��ӡ
					win++;
				}
			}
			else
			{
				printf("�����������Ƿ����������������꣺>\n");
			}
		
	}
	if (win == row * col - EASY)
	{
		printf("��ϲ�㣬���׳ɹ�������\n");
		displaybroad(b, ROW, COL);//��ӡ
		printf("����Ϊ�����·��ز˵�\n");
	}
}
