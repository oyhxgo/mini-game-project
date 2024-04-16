#pragma once

#include<stdio.h>

#include<windows.h>
#include<stdbool.h>

#define Wall L'■' 
#define Body L'◆'

//蛇默认的起始坐标
#define X 24
#define Y 5

//枚举游戏的状态
enum GAME_STATUS
{
	OK=1,//正常运行
	ESC,//按了esc键，正常退出
	KILLW,//kill by wall 
	KILLS//kill by yourself
};
//枚举贪吃蛇的操作
enum DIRECTION
{
	UP=1,
	DOWN,
	LEFT,
	RIGHT
};



//贪吃蛇蛇身结点的定义
typedef struct SnakeNode
{
	int x;
	int y;
	struct SnakeNode* next;

}SnakeNode,*pSnakeNode;//指向结构体的指针类型


//贪吃蛇
typedef struct Snake
{
	pSnakeNode pSnake;//维护整条蛇的指针
	pSnakeNode pFood;//指向食物的指针
	int Score;//当前累计的分数
	int Foodweight;//一个食物的分数
	int Sleeptime;//其实就是速度
	enum GAME_STATUS status;//游戏当前的状态
	enum DIRECTION dir;//贪吃蛇当前的位置
}Snake,*pSnake;

//
void Gamestart(pSnake ps);//指向结构体的指针
void Welcometogame();
void Creatmap();

