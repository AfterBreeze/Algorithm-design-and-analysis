#include<iostream>
using namespace std;

int FBNQ(int n)
{
	int a = 1, b = 2, c = a + b;
	for (int i = 3; i < n; ++i)
	{
		a = b;
		b = c;
		c = a + b;
	}
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return c;
}

int main()
{
	int arr[41];
	for (int i = 1; i < 41; ++i)
		arr[i] = FBNQ(i);
	int t,ret;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		cin >> ret;
		cout << arr[ret] << endl;
	}
	return 0;
}
