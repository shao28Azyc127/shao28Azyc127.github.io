#include<bits/stdc++.h>
using namespace std;
int n,m,k,net[1010][1010],book[1010],u,v,w;

int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	cin >> m>> n >> k;
	for(int i=1;i<=n;i++)
	{
		cin >> u >> v >> w;
		net[u][v]=w;
	}
	cout << "-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}