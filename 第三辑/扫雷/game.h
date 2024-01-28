#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#define EASY 10
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void rearray(char a[ROWS][COLS], int rows, int cols, char set);
void displaybroad(char a[ROWS][COLS], int row, int col);
void setmine(char a[ROWS][COLS], int row, int col);
void findmine(char a[ROWS][COLS], char b[ROWS][COLS] ,int row, int col);