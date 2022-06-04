#include<bits/stdc++.h>
using namespace std;

#define MAXN 100001
int Fa[MAXN];

void Init(int n)
{
    for(int i = 1;i <= n ; ++i)
        Fa[i] = i;
}

int Find(int i)
{
    if(Fa[i] == i)
        return i;
    else
        return Find(Fa[i]);
}

void Union(int i,int j)
{
    Fa[Find(i)] = Find(j);
}

int main()
{
    int n,m;
    cin >> n >> m;
    Init(n);
    char a;
    int x,y;
    for(int i =1 ; i <= m ; ++i)
    {
        cin >> a >> x >> y;
        if(a == 'M')
        {
            Union(x,y);
        }
        else
        {
            if(Find(x) == Find(y))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
