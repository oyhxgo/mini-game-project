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
	//���������ַ�����
	char mine[ROWS][COLS];
	char show[ROWS][COLS];
	//��ʼ������
	rearray(mine,ROWS,COLS,'0');
	rearray(show, ROWS, COLS,'*');
	//��ӡ����
	displaybroad(show, ROW, COL);
	//������
	setmine(mine,ROW,COL);
	//displaybroad(mine, ROW, COL);������
	//�Ų���
	findmine(mine, show, ROW, COL);
}


int main()
{
	int a=0;
	srand((unsigned int)time(NULL));//��ʱ��Ϊ���ӵ����������ǿ������ת��Ϊunsigned int��
	do {
		menu();
		printf("��ӭ��װ��Ϸ����������ִ��������\n");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			printf("��ӭ����ɨ����Ϸ\n");
			game();
			break;
		case 2:
			printf("��������˳���Ϸ!!!\n");
			a = 0;
			break;
		default:
			printf("�������������ѡ�񣡣���\n");
			break;
		}
	} while (a);
	return 0;
}