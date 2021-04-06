#define _CRT_SECURE_NO_WARNINGS 1
//test.c用来测试游戏，还得有一个游戏实现的模块game.c,  game.c用来放游戏的实现。
//再建立一个头文件game.h用来放函数的声明
#include"game.h"

void menu()
{
	printf("*****************************************\n");
	printf("********      1.play      ***************\n");
	printf("********      0.exit      ***************\n");
	printf("*****************************************\n");
}


void game()
{
	//雷的信息存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);
	//布置雷
	SetMine(mine,ROW,COL);
	//打印雷阵
	DisplayBoard(mine, ROW, COL);

	//扫雷,mine数组里找信息，找到之后放到show数组里
	FindMine(mine,show,ROW,COL);

}

void test()//这个游戏玩完一把不过瘾我要再玩一把
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}