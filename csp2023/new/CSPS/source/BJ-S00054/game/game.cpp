#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
char a[2000010],b[2000010];
bool xc(char x[])
{
	int up=-1;
	char y[2000010];
	for(int i=0;i<strlen(x);i++)
	{
		y[++up]=x[i];
		while(up>=1&&y[up]==y[up-1])
		{
			up-=2;
		}
		if(up+1>strlen(x)-i-1)
		{
			return 0;
		}
	}
	while(up>=1&&y[up]==y[up-1])
	{
		up-=2;
	}
	return up==-1;
}
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	cin>>n>>a;
	for(int i=0;i<n-1;i++)
	{
		memset(b,0,sizeof(0));
		b[0]=a[i];
		for(int j=1;j<=n-i-1;j++)
		{
			b[j]=a[i+j];
			if(j%2==1)
			{
				ans+=xc(b);
			}
		}
	}
	cout<<ans;
	return 0;
}