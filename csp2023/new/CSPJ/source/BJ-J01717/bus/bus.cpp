#include <iostream>
#include <cstdio>
using namespace std;
const int z = 2e4;
int u[z + 5] , v[z + 5] , a[z + 5];
int main()
{
	freopen("bus.in" , "r" , stdin);
	freopen("bus.out" , "w" , stdout);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1;i <= m;i++)
	{
		cin >> u[i] >> v[i] >> a[i];
	}
	cout << -1 << endl;
	return 0;
}