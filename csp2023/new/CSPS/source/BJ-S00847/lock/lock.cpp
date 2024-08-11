#include<bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>mp,mp1;
int get(int a,int b,int c,int d,int e)
{
	return a*10000+b*1000+c*100+d*10+e;
}
int a[10][7],b[(int)(1e5+10)][7];
signed main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++) cin>>a[i][j];
		for(int j=1;j<=5;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int tmp=a[i][j];
				a[i][j]=k;
				mp[get(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]++;
				a[i][j]=tmp;
			}
		}
		for(int j=1;j<=4;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int t1=a[i][j],t2=a[i][j+1];
				a[i][j]+=k;a[i][j+1]+=k;
				a[i][j]%=10;a[i][j+1]%=10;
				mp[get(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]++;
				a[i][j]=t1;a[i][j+1]=t2;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		mp[get(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]=0;
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=1;j<=5;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int tmp=a[i][j];
				a[i][j]=k;
				if(mp[get(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]==n) cnt++,mp[get(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]=0;
				a[i][j]=tmp;
			}
		}
		for(int j=1;j<=4;j++)
		{
			for(int k=0;k<=9;k++)
			{
				int t1=a[i][j],t2=a[i][j+1];
				a[i][j]+=k;a[i][j+1]+=k;
				a[i][j]%=10;a[i][j+1]%=10;
				if(mp[get(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]==n) cnt++,mp[get(a[i][1],a[i][2],a[i][3],a[i][4],a[i][5])]=0;
				a[i][j]=t1;a[i][j+1]=t2;
			}
		}
	}
	cout<<cnt;
}