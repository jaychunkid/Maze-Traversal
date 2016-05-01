# Maze-Traversal
A program to produce a maze of any width and height and solve it.  
Chinese:
--------
大一上学期C++大作业之一，要求用面向结构方式编程。使用方法：根据提示输入所要创建迷宫的高度和宽度，按回车键进入寻路过程，每按一次回车输出一步。<br>
1.体系设计<br>
一个头文件“Maze.h”存放函数声明，“mazeTraverse.cpp”及“mazeGenerator.cpp”文件分别存放题目要求的两个函数，“Main.cpp”文件用来测试这两个函数。<br>
2.应用程序设计<br>
mazeTraverse函数接受一个char类型的二级指针x，以及四个int类型变量px，py，height，width作为参数，其中x为迷宫，px，py为迷宫入口，height，width为迷宫的高度和宽度。全局变量length记录移动的路程，direction记录移动方向。函数每移动一步先判断所在位置的周围是否为通路，将判断结果分别储存在四个bool型变量up，down，left，right中，再根据direction的值，按照右转，前进，左转，后退的顺序选择前进方向，并修改direction的值，进入递归。当走出迷宫或回到入口时，函数递归结束，并分情况输出“到达终点”或“并没有出口”。函数每移动一步后都会输出移动后的迷宫情况。<br>
mazeGenerator函数接受一个char类型二级指针x，六个int类型变量sx，sy，ex，ey，h，w作为参数。其中sx，sy用于储存入口位置，ex，ey用于储存出口位置，h，w代表生成迷宫的高度和宽度，x用于储存生成的迷宫。全局变量height和width用于储存迷宫的高度和宽度。函数先将整个迷宫用“墙”填满，再用随机赋值在迷宫外层墙内取一点打通，随后调用另一个函数Extend从这一点开始向其他方向打通。Extend函数每一次递归定义四个int类型变量up，down，left，right，用于储存所在点上下左右四个方向的情况。若四个方向都未打通，则使用随机赋值决定要往哪几个方向延展通路。若三个方向未打通（可能其中一个方向是迷宫外墙），则使用随机赋值决定三个（两个）方向进入递归的先后顺序。若遇到四个方向中有两个或以上已打通的情况，则将所在点重新填为“墙”，递归结束。Extend函数递归结束后，用随机赋值在迷宫的左右两面外墙上分别取入口和出口，输出生成的迷宫情况和入口、出口的坐标（以迷宫的左下角为原点）。<br>
English:
--------
` My English is very poor... So I am sorry to tell you that I could not describe the framework of the program `<br>
This program is one of my homeworks which requires us to write it withou "class". Using method: First, input the height and width of the maze. Then, enter Enter to start solving the maze. Every entering will make the program output one-step.
