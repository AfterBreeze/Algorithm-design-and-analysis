#include<bits/stdc++.h>
using namespace std;
#define MAX 1001

int dp[MAX][MAX];//dp[i][j] 表示s1 i-size1 s2 j-size2 之间的最长公共子序列



int MAX_String2(string s1, string s2)
{
	memset(dp, 0, sizeof(dp));
	int Size1 = s1.size(), Size2 = s2.size();

	for (int i = 1; i <= Size1; ++i)
	{
		for (int j = 1; j <= Size2; ++j)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[Size1][Size2];
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		string temp1, temp2;
		cout << MAX_String2(s1, s2) << endl;
		swap(temp1, s1), swap(temp2, s2);
	}
	return 0;
}
