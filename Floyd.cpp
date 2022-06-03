#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int N=205,INF=1e9;
int dis[N][N],n,m,k;
void floyd()
{
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    int a,b,c;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)dis[i][j]=0;//自环为0
            else dis[i][j]=INF;
        }
    }
    while(m--) {
        cin >> a>> b >> c;
        dis[a][b] = min(dis[a][b],c);
    }
    floyd();
    int x,y;
    while(k--)
    {
        cin>>x>>y;
        if(dis[x][y]>INF/2)puts("impossible");
        else cout<<dis[x][y]<<endl;
    }
    return 0;
}
