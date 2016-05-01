#include<cstdlib>
#include<ctime>
#include"Maze.h"
int height, width;
void Extend(char **x, int px, int py)     //递归函数延展通路
{
	int up, down, left, right, n = 0;     //建立up，down，left，right四个变量存放上下左右四个方向的情况：0：通路，1：墙，2：边界，n存放四个方向中到达边界的方向数目
	if (px == 1)     //判断是否到达左边界 
	{
		left = 2;
		n++;
	}
	else left = x[py][px - 1] == '#' ? 1 : 0;     //未到达边界，判断是否已经打通
	if (px == (width-2))
	{
		right = 2;
		n++;
	}
	else right = x[py][px + 1] == '#' ? 1 : 0;
	if (py == 1)
	{
		up = 2;
		n++;
	}
	else up = x[py - 1][px] == '#' ? 1 : 0;
	if (py == height-2)
	{
		down = 2;
		n++;
	}
	else down = x[py + 1][px] == '#' ? 1 : 0;
	if (up ==1&& down == 1&&left ==1&& right == 1)     //四个方向皆可延展
	{
		int one, two, three, four;     //建立四个整形变量在1~4内随机赋值，决定延展方向：1：上，2：下，3：左，4：右
		one = rand() % 4 + 1;
		two = rand() % 4 + 1;
		three = rand() % 4 + 1;
		four = rand() % 4 + 1;
		if (one == 1 || two == 1 || three == 1 || four == 1)
		{
			x[py - 1][px] = '.';
			Extend(x, px, py - 1);
		}
		if (one == 3 || two == 3 || three == 3 || four == 3)     
		{
			x[py][px - 1] = '.';     //打通后进入递归
			Extend(x, px - 1, py);
		}
		if (one == 2 || two == 2 || three == 2 || four == 2)
		{
			x[py + 1][px] = '.';
			Extend(x, px, py + 1);
		}
		if (one == 4 || two == 4 || three == 4 || four == 4)
		{
			x[py][px + 1] = '.';
			Extend(x, px + 1, py);
		}
	}
	else if ((up == 1 && down == 1 && left == 1) || (up == 1 && left == 1 && right == 1) || (up == 1 && down == 1 && right == 1) || (down == 1 && left == 1 && right == 1))     //有三个方向可延展
	{
		int sequence = rand() % 4 + 1;     //用1~4范围内的随机数决定先进行延展的方向
		switch (sequence)
		{
		case 1:if (up == 1)
				{
					x[py - 1][px] = '.';
					Extend(x, px, py - 1);
				}
			   if (down == 1)
			   {
				   x[py + 1][px] = '.';
				   Extend(x, px, py + 1);
			   }
			   if (right == 1)
			   {
				   x[py][px + 1] = '.';
				   Extend(x, px + 1, py);
			   }
			   if (left == 1)
			   {
				   x[py][px - 1] = '.';
				   Extend(x, px - 1, py);
			   }
			   break;
		case 2:if (down == 1)
				{
					x[py + 1][px] = '.';
					Extend(x, px, py + 1);
				}
			   if (up == 1)
			   {
				   x[py - 1][px] = '.';
				   Extend(x, px, py - 1);
			   }
			   if (left == 1)
			   {
				   x[py][px - 1] = '.';
				   Extend(x, px - 1, py);
			   }
			   if (right == 1)
			   {
				   x[py][px + 1] = '.';
				   Extend(x, px + 1, py);
			   }
			   break;
		case 3:	if (left == 1)
				{
					x[py][px - 1] = '.';
					Extend(x, px - 1, py);
				}
				if (up == 1)
				{
					x[py - 1][px] = '.';
					Extend(x, px, py - 1);
				}
				if (right == 1)
				{
					x[py][px + 1] = '.';
					Extend(x, px + 1, py);
				}
				if (down == 1)
				{
					x[py + 1][px] = '.';
					Extend(x, px, py + 1);
				}
				break;
		case 4:if (right == 1)
				{
					x[py][px + 1] = '.';
					Extend(x, px + 1, py);
				}
			   if (up == 1)
			   {
				   x[py - 1][px] = '.';
				   Extend(x, px, py - 1);
			   }
				if (left == 1)
			   {
				   x[py][px - 1] = '.';
				   Extend(x, px - 1, py);
			   }
			   if (down == 1)
			   {
				   x[py + 1][px] = '.';
				   Extend(x, px, py + 1);
			   }
			   break;
		}
	}
	else if ((n == 1 || n == 2) && ((up == 1 && down == 1) || (up == 1 && left == 1) || (up == 1 && right == 1) || (down == 1 && left == 1) || (down == 1 && right == 1) || (left == 1 && right == 1)))
	{                                                                                                                                                   //有两个方向可延展，且不可延展的两个方向中有一个抵达边界                     
		int sequence = rand() % 2 + 1;
		switch (sequence)
		{
		case 1:if (down == 1)
				{
					x[py + 1][px] = '.';
					Extend(x, px, py + 1);
				}
			   if (left == 1)
			   {
				   x[py][px - 1] = '.';
				   Extend(x, px - 1, py);
			   }
			   if (up == 1)
			   {
				   x[py - 1][px] = '.';
				   Extend(x, px, py - 1);
			   }
			   if (right == 1)
			   {
				   x[py][px + 1] = '.';
				   Extend(x, px + 1, py);
			   }
			   break;
		case 2: if (right == 1)
				{
					x[py][px + 1] = '.';
					Extend(x, px + 1, py);
				}
				if (up == 1)
				{
					x[py - 1][px] = '.';
					Extend(x, px, py - 1);
				}
				if (left == 1)
				{
					x[py][px - 1] = '.';
					Extend(x, px - 1, py);
				}
				if (down == 1)
				{
					x[py + 1][px] = '.';
					Extend(x, px, py + 1);
				}
				break;
		}
	}
	else if (n == 2 && (up == 1 || down == 1 || left == 1 || right == 1))     //只有一个方向可延展，且不可延展的三个方向中有两个抵达边界
	{
		if (down == 1)
		{
			x[py + 1][px] = '.';
			Extend(x, px, py + 1);
		}
		if (up == 1)
		{
			x[py - 1][px] = '.';
			Extend(x, px, py - 1);
		}
		if (right == 1)
		{
			x[py][px + 1] = '.';
			Extend(x, px + 1, py);
		}
		if (left == 1)
		{
			x[py][px - 1] = '.';
			Extend(x, px - 1, py);
		}
	}
	else     //会与其他已打通部分连通形成环或块，恢复为墙且递归结束
	{
		x[py][px] = '#';
		return;
	}
}
void MazeGenerator(char **x,int&sx,int&sy,int&ex,int&ey,int h,int w)
{
	height = h;
	width = w;
	for (int i = 0; i < height; i++)     //将整个迷宫用墙填满
		for (int j = 0; j < width; j++)
			x[i][j] = '#';
	int fx, fy;     //随机取一点打通
	srand(int(time(0)));
	fx = rand() % (width-2) + 1;
	fy = rand() % (height-2) + 1;
	x[fy][fx] = '.';
	Extend(x, fx, fy);     //延展
Start:int a = rand() % (height-2) + 1;     //在迷宫的左边和右边随机取起点和终点
	if (x[a][1] == '.')
	{
		x[a][0] = '.';
		sy = a;
		sx = 0;
	}
	else goto Start;
End:int b = rand() % (height-2) + 1;
	if (x[b][width-2] == '.')
	{
		x[b][width-1] = '.';
		ey = b;
		ex = width - 1;
	}
	else goto End;
	for (int i = 0; i < height; i++)     //输出迷宫
	{
		for (int j = 0; j < width; j++)
		{
			cout << x[i][j];
			if (j != width - 1) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Start (" << sx + 1 << "," << height - sy << ") ,End (" << ex + 1 << "," << height - ey << ")" << endl;     //输出迷宫起点与终点坐标（以迷宫左下角为原点）
}