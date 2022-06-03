#include<bits/stdc++.h>
using namespace std;
#define MAX 501
int n, m;

int Dijistra(int n, int sou,int des,int a[MAX][MAX],int b[MAX])
{
	for (int i = 1; i <= n; ++i)
	{
		b[i] = a[sou][i];
	}
	int Flag[MAX];
	memset(Flag, 0, sizeof(Flag));

	Flag[sou] = 1;

	for (int k = 1; k < n; ++k)
	{
		int n_min = INT_MAX, index;

		for (int i = 1; i <= n; ++i)
		{
			if (!Flag[i])
			{
				if (n_min > b[i])
				{
					n_min = b[i];
					index = i;
				}
			}
		}

		Flag[index] = 1;

		//更新权值
		for (int i = 1; i <= n; ++i)
		{
			if (!Flag[i])
			{
				if (b[i] > b[index] + a[index][i])
					b[i] = b[index] + a[index][i];
			}
		}
	}
  
	return b[des];
}

int main()
{
	cin >> n >> m ;
	int dp[MAX][MAX];
	int ret[MAX];
	int x, y, z;
	memset(dp, 10001, sizeof(dp));
	memset(ret, 10001, sizeof(ret));
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y >> z;
		dp[x][y] = min(z, dp[x][y]);
	}

	Dijistra(n, 1, n, dp, ret);

	if (ret[n] <= 10000)
		cout << ret[n] << endl;
	else
		cout << "-1" << endl;
	return 0;
}
