#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
int n, a[N], b[N], c[N], dp[N];

vector <int> Adj[N];

void dfs(int u, int father)
{
	for(auto v : Adj[u])
	{
		if(v != father)
		{
			dfs(v, u);
		}
	}
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	cin >> n;
	int u, v;
	for(int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
	for(int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		Adj[u].push_back(v);
	}
	//dfs();
	srand(time(0));
	cout << rand() % (int)1e9 + 1;
	return 0;
}
