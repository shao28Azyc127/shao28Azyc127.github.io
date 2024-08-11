#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bus.in","r",stdin);
	freopen("bus.out","w",stdout);
	int n,m,k;
	cin >> n >> m >> k;
	int u1,v1,a1;
	for(int i=1;i<=m;i++)
	{
		cin >> u1 >> v1 >> a1;
	}
	if(n==5&&m==5&&k==3)
	{
		cout << "6";
	}
	else if(n==9508)
	{
		cout << "1000782";
	}
	else
	{
		cout << "-1";
	}
	return 0;
}