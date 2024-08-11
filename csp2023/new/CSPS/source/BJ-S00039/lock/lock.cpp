//CSP2023 RP++
#include<bits/stdc++.h>
using namespace std;
int n,ans,a[10][6],b[10][6],f[100005];
void print(int x)
{
	int p=a[x][1]*10000+a[x][2]*1000+a[x][3]*100+a[x][4]*10+a[x][5];
	f[p]++;
	return;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int k=0;k<=9;k++)
			{
				if(k==b[i][j])	continue;
				a[i][j]=k;
				print(i);
			}
			a[i][j]=b[i][j];
		}
		for(int j=1;j<=4;j++)
		{
			for(int k=0;k<=9;k++)
			{
				a[i][j]++;
				a[i][j+1]++;
				if(a[i][j]==10)	a[i][j]=0;
				if(a[i][j+1]==10)	a[i][j+1]=0;
				if(a[i][j]==b[i][j])	continue;
				print(i);
			}
			a[i][j]=b[i][j];
			a[i][j+1]=b[i][j+1];
		}
	}
	for(int i=0;i<=99999;i++)
	{
		if(f[i]==n)	ans++;
	}
	cout<<ans;
	return 0;
}
