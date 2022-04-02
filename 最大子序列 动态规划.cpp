#include<iostream>
#include<cstdlib>
using namespace std;
#define N 100001
int maxsequence3(int a[], int len,int &tou,int &wei)
{
	int maxsum, maxhere;
	maxsum = maxhere = a[0];  
	tou = 0, wei = len - 1;
	int temp = 0;
	for (int i = 1; i < len; i++) 
	{
		if (maxhere < 0)
			maxhere = a[i],temp = i;   
		else
			maxhere += a[i]; 
		if (maxhere > maxsum) 
		{
			maxsum = maxhere;  
			tou = temp,wei = i;
		}
	}
	return maxsum;
}


int main()
{
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		int n,a=0,b = 1;
		cin >> n;
		int arr[N];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		cout << "Case " << i << ":" << endl;
		int ret = maxsequence3(arr, n, a, b);
		printf("%d %d %d\n", ret, a+1, b+1);
		if (i != T)
			cout << endl;
	}


	return 0;
}
