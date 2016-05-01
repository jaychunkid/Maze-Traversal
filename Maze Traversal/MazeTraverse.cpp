#include"Maze.h"
int sx, sy;     //起点坐标
int length = 1;     //走过的路程
int direction = 0;     //1：东，2：西，3：南，4：北
void MazeTraverse(char **x, int px, int py,int height,int width)
{
	if (length == 1) cout << "Enter Enter to start." << endl;     //控制输出
	else cout << "Enter Enter to continue." << endl;
	char control;
	Start:if (control = cin.get() == '\n') 
	{
		if (length == 1) int sx = px, sy = py;
		for (int i = 0; i < height; i++)     //输出迷宫
		{
			for (int j = 0; j < width; j++)
			{
				if (i == py&&j == px) cout << "X";     //在当前位置标示“X”
				else cout << x[i][j];
				if (j != width - 1) cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		if ((px == 0 || px == width-1 || py == 0 || py == height-1) && length != 1)     //判断递归结束条件
		{
			if (px == sx&&py == sy) cout << "Could not find the End." << endl;     //没有出口，回到起点
			else cout << "Arrive at the End." << endl;     //到达终点
			return;
		}
		else
		{
			bool up, down, left, right;     //判断上下左右四个方向能否通行，0：墙，1：通路
			if (px == 0 || py == 0 || px == width-1 || py == height-1)     //所在点位于迷宫边界
			{
				if (px == 0)
				{
					right = 1;
					direction = 4;
				}
				if (px == width-1)
				{
					left = 1;
					direction = 3;
				}
				if (py == 0)
				{
					down = 1;
					direction = 1;
				}
				if (py == height-1)
				{
					up = 1;
					direction = 2;
				}
			}
			else    //所在点位于迷宫内
			{
				right = (x[py][px + 1] == '.') ? 1 : 0;
				left = (x[py][px - 1] == '.') ? 1 : 0;
				up = (x[py - 1][px] == '.') ? 1 : 0;
				down = (x[py + 1][px] == '.') ? 1 : 0;
			}
			switch (direction)     //根据上一步的移动方向选择移动方向
			{
			case 1:if (down == 1)
			{
				py++;
				direction = 3;
			}
				   else if (right == 1)
				   {
					   px++;
					   direction = 1;
				   }
				   else if (up == 1)
				   {
					   py--;
					   direction = 4;
				   }
				   else
				   {
					   px--;
					   direction = 2;
				   }
				   break;
			case 2:if (up == 1)
			{
				py--;
				direction = 4;
			}
				   else if (left == 1)
				   {
					   px--;
					   direction = 2;
				   }
				   else if (down == 1)
				   {
					   py++;
					   direction = 3;
				   }
				   else
				   {
					   px++;
					   direction = 1;
				   }
				   break;
			case 3:if (left == 1)
			{
				px--;
				direction = 2;
			}
				   else if (down == 1)
				   {
					   py++;
					   direction = 3;
				   }
				   else if (right == 1)
				   {
					   px++;
					   direction = 1;
				   }
				   else
				   {
					   py--;
					   direction = 4;
				   }
				   break;
			case 4:if (right == 1)
			{
				px++;
				direction = 1;
			}
				   else if (up == 1)
				   {
					   py--;
					   direction = 4;
				   }
				   else if (left == 1)
				   {
					   px--;
					   direction = 2;
				   }
				   else
				   {
					   py++;
					   direction = 3;
				   }
				   break;
			}
			length++;     //计算经过路程
			MazeTraverse(x, px, py,height,width);     //进入递归
		}
	}
	else goto Start;     //防止误输入
}