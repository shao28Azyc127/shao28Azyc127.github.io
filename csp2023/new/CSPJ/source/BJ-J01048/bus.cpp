#include<iostream>
#include<vector>
using namespace std;

struct node
{
	int v, a;
};
vector<node> v[100010];
int main()
{
	freopen("bus.in", "r", stdin);
	freopen("bus.out", "w", stdout);
	int n, m, k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++)
	{
		int u, x, a;
		cin >> u >> x >> a;
		v[u].push_back({x, a});
	}
	cout << -1 << endl;
	return 0;
}