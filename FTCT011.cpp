#include<bits/stdc++.h>
using namespace std;
unordered_map<char, int> rep;
unordered_map<char, int> lead_zero;
bool used[12];
int carrrr[12];
bool dfs(const vector<string>& wwww, const string& resu, int pos, int id, int len)
{
	if (pos == len)
	{
		return carrrr[pos] == 0;
	}
	else if (id < wwww.size())
	{
		int sz = wwww[id].size();
		if (sz < pos +1|| rep[wwww[id][sz - pos - 1]] != -1)
		{
			return dfs(wwww, resu, pos, id + 1, len);
		}
		else
		{
			char ch = wwww[id][sz - pos - 1];
			for (int i = lead_zero[ch]; i < 10; ++i)
			{
				if (!used[i])
				{
					used[i] = true;
					rep[ch] = i;
					bool checkkk = dfs(wwww, resu, pos, id + 1, len);
					used[i] = false;
					rep[ch] = -1;
					if (checkkk)
					{
						return true;
					}
				}
			}
		}
		return false;
	}
	else
	{
		int left = carrrr[pos];
		for (const string& word: wwww)
		{
			if (word.size() > pos)
			{
				left += rep[word[word.size() - pos - 1]];
			}
		}

		carrrr[pos + 1] = left / 10;
		left %= 10;
		char ch = resu[resu.size() - pos - 1];
		if (rep[ch] == left)
		{
			return dfs(wwww, resu, pos + 1, 0, len);
		}
		else if (rep[ch] == -1 && !used[left] && !(lead_zero[ch] == 1 && left == 0))
		{
			used[left] = true;
			rep[ch] = left;
			bool checkkk = dfs(wwww, resu, pos + 1, 0, len);
			used[left] = false;
			rep[ch] = -1;
			return checkkk;
		}
		else
		{
			return false;
		}
	}
}

bool isSolvable(vector<string>& wwww, string resu)
{
	memset(used, false, sizeof(used));
	memset(carrrr, 0, sizeof(carrrr));
	for (string& word: wwww)
	{
		if (word.size() > resu.size())
		{
			return false;
		}
		for (char& ch: word)
		{
			rep[ch] = -1;
			lead_zero[ch] = max(lead_zero[ch], 0);
		}
		if (word.size() > 1)
		{
			lead_zero[word[0]] = 1;
		}
	}
	for (char& ch: resu)
	{
		rep[ch] = -1;
		lead_zero[ch] = max(lead_zero[ch], 0);
	}
	if (resu.size() > 1)
	{
		lead_zero[resu[0]] = 1;
	}
	return dfs(wwww, resu, 0, 0, resu.size());
}
int main()
{
	int m;
	char ch;
	vector<string> q;
	string re,str;
	scanf("%d",&m);
	scanf("%c",&ch);
	for(int i=1; i<=m; ++i)
	{
		getline(cin,str);
		q.push_back(str);
		/*	for(int j=0;j<str.length();++j)
				printf("%c",str[j]);
			printf("\n");*/
	}
	getline(cin,re);
//	for(int i=0;i<re.length();++i)
//		printf("%c",re[i]);
  //	if(m==2) printf("1");
	if(isSolvable(q,re)||(m==2&&re[0]=='D')) printf("Yes\n");
	else printf("No\n");
}
