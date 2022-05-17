#include <bits/stdc++.h>
using namespace std;
int n,a[30001],w,l,r,mid,bs,b[30001],c[30001];
bool cmp(int a,int b)
{
	return a>b;
}
int Do(int x)
{
	bool f;
	memset(c,0,sizeof(c));
	bs=0;
	for(int i=1;i<=n;++i)
	{
		f=false;
		for(int j=1;j<=bs;++j)
			if(c[j]<2&&(a[i]+b[j]<=w))
			{
				b[j]+=a[i];
				c[j]++;
				f=true;
				break;
			}
		if(f) continue;
		else
		{
			bs++;
			b[bs]=a[i];
			c[bs]++;
		}
	}
	return bs;
}
int main()
{
	scanf("%d%d",&w,&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n,cmp);
/*	l=1;
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(Do(mid)) r=mid;
		else l=mid+1;
	}//*/
	printf("%d\n",Do(1));
}
