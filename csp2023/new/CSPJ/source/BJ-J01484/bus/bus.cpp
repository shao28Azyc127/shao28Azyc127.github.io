#include<bits/stdc++.h>
using namespace std;
int arr[100000][100000];
int dis[10000],vis[100000];
void dj(int s)
{
	dis[s]=0;
	
}
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	long long n,m,k;
	cin>>n>>m>>k;
	int u,v,a;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>a;
		arr[u][v]=1;
	}
	dj(1);
	
	return 0;
}

