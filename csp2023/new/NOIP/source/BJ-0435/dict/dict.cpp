#include <bits/stdc++.h>
using namespace std;
const int N=3e3+5;
char a[N][N],s[N][N];
int n,m;
bool cmp(char a,char b)
{
	return a>b;
}
bool B(int x,int y)
{
	if(s[x]==a[y])
		return 1;
	for(int i=0;i<m;i++)
	{
		if(s[x][i]>a[y][i])
			return 1;
		else if(s[x][i]<a[y][i])
			return 0;
	}
}
int main()
{
	freopen("dict.in","r",stdin);
	freopen("dict.out","w",stdout);
	char minc='z'+1;
	int minn;
	cin>>n>>m;
	if(n==1)
	{
		cin>>a[1];
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=0;j<m;j++)
			s[i][j]=a[i][j];
	}
	if(m==1)
	{
		for(int i=1;i<=n;i++)
			if(a[i][0]<minc)
			{
				minc=a[i][0];
				minn=i;
			}
		for(int i=1;i<=n;i++)
		{
			if(minn==i)
				cout<<1;
			else
				cout<<0;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		sort(a[i],a[i]+m,cmp);
		sort(s[i],s[i]+m);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j&&i==n)
				cout<<1;
			if(i==j)
				continue;
			if(B(i,j))
			{
				cout<<0;
				break;
			}
			if(j==n)
				cout<<1;
		}
	}
	return 0;
}