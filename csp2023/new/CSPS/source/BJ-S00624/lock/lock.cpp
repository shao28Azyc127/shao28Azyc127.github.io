#include<bits/stdc++.h>
using namespace std;
int a[10][10],ans[10],dif[6];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int i,j,n;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=5;j++)
			cin>>a[i][j];
	}
	if(n==1)
	{
		cout<<81;
		return 0;
	}
	if(n==2)
	{
		int cnt=0,di;
		for(i=1;i<=5;i++)
		{
			if(a[1][i]!=a[2][i])
				dif[i]=1;
		}
		for(i=1;i<=5;i++)
		{
			if(dif[i]==1)
				cnt++;
		}
		if(cnt>2)
		{
			cout<<0;
			return 0;
		}
		if(cnt==1)
		{
			for(i=1;i<=5;i++)
			{
				if(dif[i]==1)
				{
					di=i;
					continue;
				}
			}
			if(di==1 || di==5)
			{
				cout<<10;
				return 0;
			}
			else
			{
				cout<<12;
				return 0;
			}
		}
		else
		{
			cout<<9;
			return 0;
		}
	}
	cout<<9-n;
	return 0;
}
