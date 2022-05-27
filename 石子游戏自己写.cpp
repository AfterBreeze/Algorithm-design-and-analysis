#include<bits/stdc++.h>
using namespace std;
#define MAX 301

int N;
int dp1[MAX][MAX];
int dp2[MAX][MAX];

int num[MAX];
int sum[MAX];
int m_real[MAX];

void alg()
{
	//for (int i = 1; i <= N; ++i)
	//	dp1[i][i] = 0;
	for (int j = 2; j <= N; ++j)
	{
		for (int i = j - 1; i >= 1; --i)
		{
			int min = INT_MAX;
			int max = INT_MIN;

			for (int k = i; k < j; ++k)
			{
				int s = dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1];
				if (s < min)
					min = s;

				s = dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1];
				if (s > max)
					max = s;
				
			}
			dp1[i][j] = min;
			dp2[i][j] = max;
		}
	}
	return;
}

void re_deal(int start)
{
	int k = 1;
	for (int i = start; i <= start + N; ++i)
	{
		num[k] = m_real[i % N + 1 ];
		sum[k] = sum[k - 1] + num[k];
		k++;
	}

	//for (int i = 1; i <= N; ++i)
	//	cout << num[i] << ' ';
	//cout << endl;
}

void Init()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> m_real[i];
	//for (int i = 1; i <= N; ++i)
	//{
	//	cin >> num[i];
	//	sum[i] = sum[i - 1] + num[i];
	//}
}

int main()
{
	
	Init();
	
	int ret_min = INT_MAX;
	int ret_max = INT_MIN;
	//以某个点为起点的值
	for (int i = 1; i <= N; ++i)
	{
		re_deal(i);
		alg();
		int a = dp1[1][N];
		int b = dp2[1][N];

		if (ret_min > a)
			ret_min = a;
		if (ret_max < b)
			ret_max = b;

	}

	cout << ret_min << endl;
	cout << ret_max << endl;
	return 0;
}
