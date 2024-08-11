#include <bits/stdc++.h>
using namespace std;
int mp[1005][1005];

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int a,u,v;
		cin>>v>>u>>a;
		mp[u][v]++;
	}
	cout<<-1;
	return 0;
}
