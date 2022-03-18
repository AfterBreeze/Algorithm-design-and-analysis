#include<iostream>
#include<algorithm>
using namespace std;
#define N 1000000
int arr[N];
void isAliceWin()
{
    for (int i = 1; i <= sqrt(N); i++) arr[i * i] = 1;
    for (int i = 1; i <= N; i++) {
        if (arr[i] == 1) continue;
        for (int j = 1; j * j < i; j++) {
            if (arr[i - j * j] == 0) {
                arr[i] = 1;
                break;
            }
        }
    }
}

int main()
{
	int t,temp;
    cin >> t;
    isAliceWin();
	for (int i = 0; i < t; ++i)
	{
		cin >> temp;
		if (arr[temp])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
