#define _CRT_SECURE_NO_WARNINGS 1
#include<locale.h>
#include"Snake.h"

void text()
{
	//����̰����
	Snake snake = { 0 };
	//��Ϸ��ʼ��Ϣ
	Gamestart(&snake);//����ṹ��ָ�루��ַ��


}
int main()
{
	//�޸����䱾�����Ļ���
	setlocale(LC_ALL, "");
	text();
	return 0;
}