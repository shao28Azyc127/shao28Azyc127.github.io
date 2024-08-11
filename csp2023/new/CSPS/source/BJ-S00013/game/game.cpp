#include<bits/stdc++.h>
using namespace std;
long long ans,vis[10000001],n;
string s;
int main()
{
	freopen("game.in","w",stdin);
	freopen("game.out","r",stdout);
	cin>>n>>s;
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1])
			ans++;
	}
	for(int i=1;i<n;i++)
	{
		if(s[i]==s[i-1]&&vis[i]==0&&vis[i-1]==0)
		{
			vis[i-1]=vis[i]=1;
		}
	}
	char x=' ';
	int f=1,y;
	while(f==1)
	{
		f=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]==x)
				ans++;
			x=s[i];
			while(vis[i+1]==0&&i<n)
				i++;
		}
		x=' ';
		for(int i=0;i<n;i++)
		{
			if(s[i]==x)
				vis[i]=vis[y]=1;
			y=i;
			x=s[i];
			while(vis[i+1]==0&&i<n)
				i++;
		}
	}
	cout<<ans;
	return 0;
}