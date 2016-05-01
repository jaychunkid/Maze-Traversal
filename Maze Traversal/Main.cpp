#include"Maze.h"
int main()
{
	int Height, Width;     //自定义迷宫高度height，宽度width
	cout << "Please input the height of your maze." << endl;
	cin >> Height;
	cout << "Please input the width of your maze." << endl;
	cin >> Width;
	char**maze = new char*[Height];     //建立动态二维数组
	for (int i = 0; i < Height; i++)
		maze[i] = new char[Width];
	int start_x, start_y, end_x, end_y;     //存放起点与终点坐标
	MazeGenerator(maze, start_x, start_y, end_x, end_y, Height, Width);     //随机建立迷宫
	cout << endl;
	cin.get();
	MazeTraverse(maze, start_x, start_y, Height, Width);     //寻找迷宫通路
	for (int j = 0; j < Height; j++)
		delete[]maze[j];
	delete[]maze;
}