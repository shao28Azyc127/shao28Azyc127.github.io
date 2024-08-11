#include<bits/stdc++.h>
using namespace std;
int d[2000][2000];
int o,minans = 1e9;
int bfs(int n,int ans)
{
	if(ans % o == 0)
	{
		minans = min(minans,ans);
		return 0;
	}
	for(int i = 1;i <= n;i++)
	{
		if(d[n][i] == 1)
		{
			d[n][i] = 0;
			bfs(i,ans + 1);
			d[n][i] = 1;
		}
	}
	return 0;
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,a,b,c;
	cin>>n>>m>>o;
	for(int i = 1;i <= m;i++)
	{
		cin>>a>>b>>c;
		d[a][b] = 1;
	}
	bfs(1,0);
	cout<<minans;
	return 0;
}
