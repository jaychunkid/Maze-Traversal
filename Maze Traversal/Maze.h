#include<iostream>
using namespace std;
void MazeTraverse(char **x, int px, int py,int h,int w);
void Extend(char **x, int px, int py);
void MazeGenerator(char **x,int&sx,int&sy,int&ex,int&ey,int height,int width);