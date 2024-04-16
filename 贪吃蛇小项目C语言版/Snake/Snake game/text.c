#define _CRT_SECURE_NO_WARNINGS 1
#include<locale.h>
#include"Snake.h"

void text()
{
	//创建贪吃蛇
	Snake snake = { 0 };
	//游戏开始信息
	Gamestart(&snake);//填入结构体指针（地址）


}
int main()
{
	//修改适配本地中文环境
	setlocale(LC_ALL, "");
	text();
	return 0;
}