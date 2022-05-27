#include<bits/stdc++.h>
using namespace std;
int n,t,a[200010],b[200010],bs,s,temp,c,ans,ssum[200010],ss;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&t);
	while(t)
	{
		t--;
		scanf("%d",&n);
		for(int i=1;i<=n-1;++i)
			scanf("%d",&a[i]);
		sort(a+1,a+n);
		bs=1;
		b[1]=1;
		s=1;
		for(int i=2;i<=n-1;++i)
			if(a[i]==a[i-1]) s++;
			else
			{
				bs++;
				b[bs]=s;
				s=1;
			}
		bs++;
		b[bs]=s;
		sort(b+1,b+1+bs,cmp);
	/*	cout<<"###";
		for(int i=1;i<=bs;++i)
			cout<<b[i]<<" ";
		cout<<endl;//*/
		
		memset(ssum,0,sizeof(ssum));
		temp=n;
		c=0;
		ans=0;
		ss=0;//ssum
		while(temp>0)
		{
			ans++;
			if(c==0)//第一次默认 
			{
				c=1;
				if(b[1]-1>0)
				{
					ss++;
					ssum[ss]=b[1]-1;
				}
				temp--;
			}
			else
			{
				for(int i=1;i<=ss;++i)
					if(ssum[i]>0)
					{
						ssum[i]--;
						temp--;
					}
				if(c<bs)
				{
					c++;
					if(b[c]-1>0)
					{
						ss++;
						ssum[ss]+=b[c]-1;
					}
					temp--;
				}
				else
				{
					for(int i=1;i<=ss;++i)
						if(ssum[i]>0)
						{
							ssum[i]--;
							temp--;
							break;
						}
				}
			}
		}
		cout<<ans<<endl;
	}
}
