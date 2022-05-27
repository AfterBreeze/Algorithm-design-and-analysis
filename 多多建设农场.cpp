#include<bits/stdc++.h>
using namespace std;
int n,m,f[5001],sum,s1,tmp;
struct gg
{
	int u,v,w;
}q[200001];
int cmp(gg a,gg b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==x) return x;
	return f[x]=find(f[x]);
}
int main()
{
	scanf("%d",&n);
	m=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%d",&tmp);
			if(i!=j)
			{
				m++;
				q[m].u=i;
				q[m].v=j;
				q[m].w=tmp;
				m++;
				q[m].u=j;
				q[m].v=i;
				q[m].w=tmp;
			}
		}
	//	scanf("%d%d%d",&q[i].u,&q[i].v,&q[i].w);
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=n;++i)
		f[i]=i;
	for(int i=1;i<=m;++i)
	{
		int x1,x2;
		x1=find(q[i].u);
		x2=find(q[i].v);
		if(x1==x2) continue;
		else
		{
			sum+=q[i].w;
			++s1;
			f[x1]=x2;
		}
		if(s1==n-1)
		{
			cout<<sum<<endl;
			return 0;
		}
	}
	cout<<"orz"<<endl;
    return 0;
}
