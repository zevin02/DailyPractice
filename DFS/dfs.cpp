#include<iostream>
#pragma once;
using namespace std;
#include<algorithm>
#include<cstdio>
#include<map>
#include<cstring>



//总结
//对于迷宫问题
//1.定义其方向数组，访问数组，进行搜索
/*
int p,q;//p和q是他们的终点坐标

//初始化一下地图
int map[100][100];//地图数组，我们用1表示空地，2表示障碍物,
int v[100][100];//访问数组，0表示未访问，1表示访问
int m, n;//m行n列
int minstep=99999;//最短路径

//我们还可以对这代码进行优化，因为代码有点冗余
//我们可以定义一个方向数组
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y, int step)
{
	//查看一下是否到达了终点，如果是的话就要更新一下最小值
	if (x == p && y == q)
	{
		if (step < minstep)
		{
			minstep = step;
			return;//找一下是不是有更小的路径
		}
	}
		else
			//这个地方不是终点，我们就要往四个方向去试探，右下左上，顺时针试探
		{

		for (int k = 0; k < 4; k++)
		{
			//顺时针进行试探
			int tx, ty;//下一个方向坐标
			tx = x + dx[k];
			ty = y + dy[k];
			if (map[tx][ty] == 1 && v[tx][ty] == 0)//空地和未访问
			{
				v[tx][ty] = 1;
				dfs(tx, ty, step + 1);
				v[tx][ty] = 0;//回退设置未访问
			}
		}
		/*
			//右，当右边是空地，而没有被访问过就可以到右边试探
			if (map[x][y+1] == 1 && v[x][y+1] == 0)//右边是空地且未访问
			{
				//把这个点设置为1
				v[x][y + 1] = 1;
				dfs(x, y + 1, step + 1);//继续搜索，已经到了右边这个点
				//这些都执行完之后，回退回去

				//我们要再把这点设置为为访问
				v[x][y + 1] = 0;
			}
			//下同理
			 if (map[x+1][y] == 1 && v[x+1][y] == 0)//右边是空地且未访问
			{
				//把这个点设置为1
				v[x+1][y] = 1;
				dfs(x+1, y, step + 1);//继续搜索，已经到了右边这个点
				//这些都执行完之后，回退回去

				//我们要再把这点设置为为访问
				v[x+1][y ] = 0;
			}
			//左
			 if (map[x][y -1] == 1 && v[x][y - 1] == 0)//右边是空地且未访问
			 {
				 //把这个点设置为1
				 v[x][y - 1] = 1;
				 dfs(x, y - 1, step + 1);//继续搜索，已经到了右边这个点
				 //这些都执行完之后，回退回去

				 //我们要再把这点设置为为访问
				 v[x][y - 1] = 0;
			 }

			//上
			 if (map[x-1][y] == 1 && v[x-1][y] == 0)//右边是空地且未访问
			 {
				 //把这个点设置为1
				 v[x-1][y ] = 1;
				 dfs(x-1, y, step + 1);//继续搜索，已经到了右边这个点
				 //这些都执行完之后，回退回去

				 //我们要再把这点设置为为访问
				 v[x-1][y ] = 0;
			 }
			 */
			 /*
						  return;
					 }


			 }

			 */

			 /*
			 1 1
			 5 4
			 4 3
			 1 1 2 1
			 1 1 1 1
			 1 1 2 1
			 1 2 1 1
			 1 1 1 2



			 */

			 //int main()
			 //{
			 //	int startx, starty;
			 //	cin >> startx >> starty;
			 //	cin >> m >> n;
			 //	cin >> p >> q;
			 //	for (int i = 1; i <= m; i++)//从第一项开始就不会越界
			 //	{
			 //		for (int j = 1; j <= n; j++)
			 //		{
			 //			cin >> map[i][j];//1表示其实点，2 表示障碍物
			 //		}
			 //	}
			 //	//从起底开始搜索，所以这点设置为1
			 //	v[startx][starty] = 1;
			 //	dfs(startx, starty, 0);
			 //	printf("minstep=%d", minstep);
			 //
			 //}
char str[55][55];//
int life[55][55];//定义一个标记位数组，是否被访问过,true表示访问过,false 表示没有被访问过
int nowx, nowy;//当前处于的坐标
//先定义一个方向数组
int dic[4][2] = { {0,1} ,{1,0},{0,-1},{-1,0} };//我们规定从右开始顺时针
int x[2500], y[2500];//记录起点的坐标
//我们要记录一下存的面积
int area[55][55];
void dfs(int x, int y)//当前坐标
{
	life[x][y] = 1;//这个地方标记一下，已经访问了
	area[nowx][nowy]++;//保存一下每次有效面积的
	for (int i = 0; i < 4; i++)
	{
		int tempx = x + dic[i][0];
		int tempy = y + dic[i][1];
		if (str[tempx][tempy] == '#' && life[tempx][tempy] == 0)//是个岛，且没有被访问过
		{
			//先标记一下访问过
			life[tempx][tempy] = 1;
			dfs(tempx, tempy);
			life[tempx][tempy] = 0;
		}
	}
}

bool areasome(int i, int j)
{
	return area[x[i]][y[i]] == area[x[j]][y[j]];
}
int main()
{
	int m, n;
	cin >> n >> m;
	int ans0 = 0;
	int ans1, ans2;//3个不同的答案，总共的，面积不同的，形状不同的
	bool flag;//不同岛屿
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//如果没有被访问过,而且是个岛屿
			if (life[i][j] == 0 && str[i][j] == '#')
			{
				ans0++;
				nowx = i;
				nowy = j;
				x[ans0] = i;
				y[ans0] = j;
				dfs(i, j);//搜索连通块
			}
		}
	}
	//统计有多少个面积不同的数量

	//for (int i = 1; i <= ans0; i++)
	//{
	//	flag = false;
	//	for (int j = 1; j <= i; j++)
	//	{
	//		if (areasome(i, j))
	//		{
	//			flag = true;
	//			break;
	//		}

	//	}
	//	if (!flag)
	//	{
	//		ans1++;//不同面积的就加，
	//	}
	//}
	cout << ans0 << endl;
	return 0;
}