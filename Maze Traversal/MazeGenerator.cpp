#include<cstdlib>
#include<ctime>
#include"Maze.h"
int height, width;
void Extend(char **x, int px, int py)     //�ݹ麯����չͨ·
{
	int up, down, left, right, n = 0;     //����up��down��left��right�ĸ�����������������ĸ�����������0��ͨ·��1��ǽ��2���߽磬n����ĸ������е���߽�ķ�����Ŀ
	if (px == 1)     //�ж��Ƿ񵽴���߽� 
	{
		left = 2;
		n++;
	}
	else left = x[py][px - 1] == '#' ? 1 : 0;     //δ����߽磬�ж��Ƿ��Ѿ���ͨ
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
	if (up ==1&& down == 1&&left ==1&& right == 1)     //�ĸ�����Կ���չ
	{
		int one, two, three, four;     //�����ĸ����α�����1~4�������ֵ��������չ����1���ϣ�2���£�3����4����
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
			x[py][px - 1] = '.';     //��ͨ�����ݹ�
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
	else if ((up == 1 && down == 1 && left == 1) || (up == 1 && left == 1 && right == 1) || (up == 1 && down == 1 && right == 1) || (down == 1 && left == 1 && right == 1))     //�������������չ
	{
		int sequence = rand() % 4 + 1;     //��1~4��Χ�ڵ�����������Ƚ�����չ�ķ���
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
	{                                                                                                                                                   //�������������չ���Ҳ�����չ��������������һ���ִ�߽�                     
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
	else if (n == 2 && (up == 1 || down == 1 || left == 1 || right == 1))     //ֻ��һ���������չ���Ҳ�����չ�������������������ִ�߽�
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
	else     //���������Ѵ�ͨ������ͨ�γɻ���飬�ָ�Ϊǽ�ҵݹ����
	{
		x[py][px] = '#';
		return;
	}
}
void MazeGenerator(char **x,int&sx,int&sy,int&ex,int&ey,int h,int w)
{
	height = h;
	width = w;
	for (int i = 0; i < height; i++)     //�������Թ���ǽ����
		for (int j = 0; j < width; j++)
			x[i][j] = '#';
	int fx, fy;     //���ȡһ���ͨ
	srand(int(time(0)));
	fx = rand() % (width-2) + 1;
	fy = rand() % (height-2) + 1;
	x[fy][fx] = '.';
	Extend(x, fx, fy);     //��չ
Start:int a = rand() % (height-2) + 1;     //���Թ�����ߺ��ұ����ȡ�����յ�
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
	for (int i = 0; i < height; i++)     //����Թ�
	{
		for (int j = 0; j < width; j++)
		{
			cout << x[i][j];
			if (j != width - 1) cout << " ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "Start (" << sx + 1 << "," << height - sy << ") ,End (" << ex + 1 << "," << height - ey << ")" << endl;     //����Թ�������յ����꣨���Թ����½�Ϊԭ�㣩
}