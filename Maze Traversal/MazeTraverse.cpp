#include"Maze.h"
int sx, sy;     //�������
int length = 1;     //�߹���·��
int direction = 0;     //1������2������3���ϣ�4����
void MazeTraverse(char **x, int px, int py,int height,int width)
{
	if (length == 1) cout << "Enter Enter to start." << endl;     //�������
	else cout << "Enter Enter to continue." << endl;
	char control;
	Start:if (control = cin.get() == '\n') 
	{
		if (length == 1) int sx = px, sy = py;
		for (int i = 0; i < height; i++)     //����Թ�
		{
			for (int j = 0; j < width; j++)
			{
				if (i == py&&j == px) cout << "X";     //�ڵ�ǰλ�ñ�ʾ��X��
				else cout << x[i][j];
				if (j != width - 1) cout << " ";
			}
			cout << endl;
		}
		cout << endl;
		if ((px == 0 || px == width-1 || py == 0 || py == height-1) && length != 1)     //�жϵݹ��������
		{
			if (px == sx&&py == sy) cout << "Could not find the End." << endl;     //û�г��ڣ��ص����
			else cout << "Arrive at the End." << endl;     //�����յ�
			return;
		}
		else
		{
			bool up, down, left, right;     //�ж����������ĸ������ܷ�ͨ�У�0��ǽ��1��ͨ·
			if (px == 0 || py == 0 || px == width-1 || py == height-1)     //���ڵ�λ���Թ��߽�
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
			else    //���ڵ�λ���Թ���
			{
				right = (x[py][px + 1] == '.') ? 1 : 0;
				left = (x[py][px - 1] == '.') ? 1 : 0;
				up = (x[py - 1][px] == '.') ? 1 : 0;
				down = (x[py + 1][px] == '.') ? 1 : 0;
			}
			switch (direction)     //������һ�����ƶ�����ѡ���ƶ�����
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
			length++;     //���㾭��·��
			MazeTraverse(x, px, py,height,width);     //����ݹ�
		}
	}
	else goto Start;     //��ֹ������
}