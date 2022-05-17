#include <bits/stdc++.h>
using namespace std;
double a[5];
char opt[5]= {' ','+','-','*','/'};
bool flag;
double F(double x,double k, double y)
{
	if(k==1)
		return x+y;
	if(k==2)
		return x-y;
	if(k==3)
		return x*y;
	if(y>=-0.000001&&y<=0.000001) return -9999999;
	else return x*1.0/y;
}
int main()
{
	while(1)
	{
		scanf("%lf%lf%lf%lf", &a[1],&a[2],&a[3],&a[4]);
		if(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0) break;
		sort(a+1,a+5);
		flag=false;
		do
		{
		//	printf("%lf %lf %lf %lf\n",a[1],a[2],a[3],a[4]);
			/*	a[1]=5;
				a[2]=5;
				a[3]=1;
				a[4]=5;
				int temp=F(a[1],3,F(a[2],2,F(a[3],4,a[4])));
				if(temp>=23.99999&&temp<=24.000001)
				{
					flag=true;
					break;
				}*/
			for (int i = 1; i <= 4; i++)
				if(flag) break;
				else
				{
					for (int j = 1; j <= 4; j++)
						if(flag) break;
						else
						{
							for (int k = 1; k <= 4; k++)
							{
								double temp;
								temp=F(F(F(a[1],i,a[2]),j,a[3]),k,a[4]);//((a?b)?c)?d
								if(temp>=23.99999&&temp<=24.000001)
								{
								//	printf("1:%lf\n",temp);
									flag=true;
									break;
								}
								else
								{
									temp=F(F(a[1],i,a[2]),k,F(a[3],j,a[4]));//(a?b)?(c?d)
									if(temp>=23.99999&&temp<=24.000001)
									{
									//	printf("2:%lf\n",temp);
										flag=true;
										break;
									}
									else
									{
										temp=F(a[4],k,F(a[1],j,F(a[2],i,a[3])));//(a?(b?c))?d
										if(temp>=23.99999&&temp<=24.000001)
										{
									//		printf("3:%lf\n",temp);
											flag=true;
											break;
										}
										else
										{
											temp=F(a[1],k,F(F(a[2],i,a[3]),j,a[4]));//a?((b?c)?d)
											if(temp>=23.99999&&temp<=24.000001)
											{
									//			printf("4:%lf\n",temp);
												flag=true;
												break;
											}
											else
											{
												temp=F(a[1],k,F(a[2],j,F(a[3],i,a[4])));//a?(b?(c?d))
												if(temp>=23.99999&&temp<=24.000001)
												{
									//				printf("5:%lf\n",temp);
													flag=true;
													break;
												}
											}
										}
									}
								}
							}//*/
						}
				}
			if(flag) break;
		}while (next_permutation(a + 1, a + 5));
		if(flag) printf("YES\n");
		else printf("NO\n");
		//	puts("No answer!");
	}
	return 0;
}
