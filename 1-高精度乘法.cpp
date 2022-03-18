#include<iostream>
#include<vector>
using namespace std;
vector<int> my_mul(vector<int>& A, vector<int>& B)
{
	vector<int> ret(A.size()+B.size());
	int temp;
	for (int i = 0; i < A.size(); ++i)
	{
		temp = 0;
		for (int j = 0; j < B.size(); ++j)
		{
			ret[i + j] += A[i] * B[j] + temp;
			temp = ret[i + j] / 10;
			ret[i + j] %= 10;
		}
		ret[i + B.size()] += temp;
	}
	int flag = 1;
	while (!ret[ret.size() - 1] && ret.size()>1)
		ret.pop_back();

	return ret;
}
int main()
{
	string temp;
	vector<int> A;
	vector<int> B;
	cin >> temp;
	for (int i = temp.size()-1; i >=0 ; --i)
		A.push_back(temp[i] - '0');
	string().swap(temp);
	cin >> temp;
	for (int i = temp.size() - 1; i >= 0; --i)
		B.push_back(temp[i] - '0');
	vector<int>rets = my_mul(A, B);

	for (int i = rets.size() - 1; i >= 0; i--)
		cout << rets[i];
	return 0;
}
