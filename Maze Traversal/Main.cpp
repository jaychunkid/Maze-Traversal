#include"Maze.h"
int main()
{
	int Height, Width;     //�Զ����Թ��߶�height�����width
	cout << "Please input the height of your maze." << endl;
	cin >> Height;
	cout << "Please input the width of your maze." << endl;
	cin >> Width;
	char**maze = new char*[Height];     //������̬��ά����
	for (int i = 0; i < Height; i++)
		maze[i] = new char[Width];
	int start_x, start_y, end_x, end_y;     //���������յ�����
	MazeGenerator(maze, start_x, start_y, end_x, end_y, Height, Width);     //��������Թ�
	cout << endl;
	cin.get();
	MazeTraverse(maze, start_x, start_y, Height, Width);     //Ѱ���Թ�ͨ·
	for (int j = 0; j < Height; j++)
		delete[]maze[j];
	delete[]maze;
}