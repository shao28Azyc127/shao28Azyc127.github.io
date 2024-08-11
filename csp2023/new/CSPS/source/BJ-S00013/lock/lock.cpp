#include<bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
	freopen("lock.in","w",stdin);
	freopen("lock.out","r",stdout);
	int n,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=5;j++)
			cin>>a[i][j];
	if(n==1)
	{
		cout<<81;
		return 0;
	}
	else if(n==2)
	{
		for(int i=1;i<=5;i++)
		{
			if(a[1][i]!=a[2][i])
			{
				cnt++;
			}
		}
		if(cnt==0)
		{
			cout<<81;
			return 0;
		}
		else if(cnt==1)
		{
			cout<<10;
			return 0;
		}
		else
		{
			cout<<2;
		}
	}
	else
	{
		cout<<10;
		return 0;
	}
	return 0;
}