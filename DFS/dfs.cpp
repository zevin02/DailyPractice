#include<iostream>
#pragma once;
using namespace std;
#include<algorithm>
#include<cstdio>
#include<map>
#include<cstring>



//�ܽ�
//�����Թ�����
//1.�����䷽�����飬�������飬��������
/*
int p,q;//p��q�����ǵ��յ�����

//��ʼ��һ�µ�ͼ
int map[100][100];//��ͼ���飬������1��ʾ�յأ�2��ʾ�ϰ���,
int v[100][100];//�������飬0��ʾδ���ʣ�1��ʾ����
int m, n;//m��n��
int minstep=99999;//���·��

//���ǻ����Զ����������Ż�����Ϊ�����е�����
//���ǿ��Զ���һ����������
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void dfs(int x, int y, int step)
{
	//�鿴һ���Ƿ񵽴����յ㣬����ǵĻ���Ҫ����һ����Сֵ
	if (x == p && y == q)
	{
		if (step < minstep)
		{
			minstep = step;
			return;//��һ���ǲ����и�С��·��
		}
	}
		else
			//����ط������յ㣬���Ǿ�Ҫ���ĸ�����ȥ��̽���������ϣ�˳ʱ����̽
		{

		for (int k = 0; k < 4; k++)
		{
			//˳ʱ�������̽
			int tx, ty;//��һ����������
			tx = x + dx[k];
			ty = y + dy[k];
			if (map[tx][ty] == 1 && v[tx][ty] == 0)//�յغ�δ����
			{
				v[tx][ty] = 1;
				dfs(tx, ty, step + 1);
				v[tx][ty] = 0;//��������δ����
			}
		}
		/*
			//�ң����ұ��ǿյأ���û�б����ʹ��Ϳ��Ե��ұ���̽
			if (map[x][y+1] == 1 && v[x][y+1] == 0)//�ұ��ǿյ���δ����
			{
				//�����������Ϊ1
				v[x][y + 1] = 1;
				dfs(x, y + 1, step + 1);//�����������Ѿ������ұ������
				//��Щ��ִ����֮�󣬻��˻�ȥ

				//����Ҫ�ٰ��������ΪΪ����
				v[x][y + 1] = 0;
			}
			//��ͬ��
			 if (map[x+1][y] == 1 && v[x+1][y] == 0)//�ұ��ǿյ���δ����
			{
				//�����������Ϊ1
				v[x+1][y] = 1;
				dfs(x+1, y, step + 1);//�����������Ѿ������ұ������
				//��Щ��ִ����֮�󣬻��˻�ȥ

				//����Ҫ�ٰ��������ΪΪ����
				v[x+1][y ] = 0;
			}
			//��
			 if (map[x][y -1] == 1 && v[x][y - 1] == 0)//�ұ��ǿյ���δ����
			 {
				 //�����������Ϊ1
				 v[x][y - 1] = 1;
				 dfs(x, y - 1, step + 1);//�����������Ѿ������ұ������
				 //��Щ��ִ����֮�󣬻��˻�ȥ

				 //����Ҫ�ٰ��������ΪΪ����
				 v[x][y - 1] = 0;
			 }

			//��
			 if (map[x-1][y] == 1 && v[x-1][y] == 0)//�ұ��ǿյ���δ����
			 {
				 //�����������Ϊ1
				 v[x-1][y ] = 1;
				 dfs(x-1, y, step + 1);//�����������Ѿ������ұ������
				 //��Щ��ִ����֮�󣬻��˻�ȥ

				 //����Ҫ�ٰ��������ΪΪ����
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
			 //	for (int i = 1; i <= m; i++)//�ӵ�һ�ʼ�Ͳ���Խ��
			 //	{
			 //		for (int j = 1; j <= n; j++)
			 //		{
			 //			cin >> map[i][j];//1��ʾ��ʵ�㣬2 ��ʾ�ϰ���
			 //		}
			 //	}
			 //	//����׿�ʼ�����������������Ϊ1
			 //	v[startx][starty] = 1;
			 //	dfs(startx, starty, 0);
			 //	printf("minstep=%d", minstep);
			 //
			 //}
char str[55][55];//
int life[55][55];//����һ�����λ���飬�Ƿ񱻷��ʹ�,true��ʾ���ʹ�,false ��ʾû�б����ʹ�
int nowx, nowy;//��ǰ���ڵ�����
//�ȶ���һ����������
int dic[4][2] = { {0,1} ,{1,0},{0,-1},{-1,0} };//���ǹ涨���ҿ�ʼ˳ʱ��
int x[2500], y[2500];//��¼��������
//����Ҫ��¼һ�´�����
int area[55][55];
void dfs(int x, int y)//��ǰ����
{
	life[x][y] = 1;//����ط����һ�£��Ѿ�������
	area[nowx][nowy]++;//����һ��ÿ����Ч�����
	for (int i = 0; i < 4; i++)
	{
		int tempx = x + dic[i][0];
		int tempy = y + dic[i][1];
		if (str[tempx][tempy] == '#' && life[tempx][tempy] == 0)//�Ǹ�������û�б����ʹ�
		{
			//�ȱ��һ�·��ʹ�
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
	int ans1, ans2;//3����ͬ�Ĵ𰸣��ܹ��ģ������ͬ�ģ���״��ͬ��
	bool flag;//��ͬ����
	for (int i = 1; i <= n; i++)
	{
		cin >> str[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//���û�б����ʹ�,�����Ǹ�����
			if (life[i][j] == 0 && str[i][j] == '#')
			{
				ans0++;
				nowx = i;
				nowy = j;
				x[ans0] = i;
				y[ans0] = j;
				dfs(i, j);//������ͨ��
			}
		}
	}
	//ͳ���ж��ٸ������ͬ������

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
	//		ans1++;//��ͬ����ľͼӣ�
	//	}
	//}
	cout << ans0 << endl;
	return 0;
}