#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,a[9999999],apn,day=0,x=0;
	cin>>n;
	a[0]=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=1;
	}
	while(x==0)
	{
		int apple=0,ai=1;
		day++;
		while(ai<=n)
		{
			if(apple==0&&a[ai]==1)
			{
				if(ai==n)
				{
					apn=day;
				}
				a[ai]=0;
			}
			apple++;
			if(apple==3)
			{
				apple=0;
			}
			ai++;
		}
		x=1;
		for(int j=1;j<=n;j++)
		{
			if(a[j]==1)
			{
				x=0;
			}
		}
	}
	cout<< day << " " << apn;
	return 0;
}
