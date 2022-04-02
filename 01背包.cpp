#include<iostream>
using namespace std;
#define N 1001
int dp[N][N];
int v[N],w[N];//体积和价值
int main(){
	int n,V;
	int i,j;
	cin>>n>>V;//商品个数和背包容量
	for(i=1;i<=n;i++){
		cin>>v[i]>>w[i];//体积和价值
	}
	for(i=1;i<=n;i++){//依次遍历从第1个物品到底n个物品
		for(j=1;j<=V;j++){//依次遍历从0~背包容量v
			if(j<v[i]){//如果背包容量小于物品体积
				dp[i][j]=dp[i-1][j];//最优解就是上一个物品时的最优解
			}else{//否则就是背包容量大于等于物品体积
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+w[i]);//拿或者不拿，选最优
			}
		}
	}
	cout<<dp[n][V]<<endl;//输出前n个商品背包为m的最优解
	return 0;
}
