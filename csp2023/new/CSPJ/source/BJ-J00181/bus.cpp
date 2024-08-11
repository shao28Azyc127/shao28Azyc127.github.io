#include <iostream>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct node
{
	ll u , t;
};
const int N = 1e4 + 10;
bool vis[N][110];
int n , m , k;
vector<pair<ll,ll>>e[N];
vector<ll>st;
ll bfs(ll s)
{
	queue<node>q;
	node t;
	t.u = 1;
	t.t = s;
	q.push(t);
	vis[1][s%k] = true;
	while (!q.empty())
	{
		t = q.front();
		q.pop();
		if (t.t % k == 0 && t.u == n)return t.t;
		for (int x = 0; x < e[t.u].size(); x++)
		{
			int i = e[t.u][x].first;
			if (t.t + 1 < e[t.u][x].second)continue;
			if (vis[i][(t.t+1)%k])continue;
			vis[i][(t.t+1)%k] = true;
			node now;
			now.u = i;
			now.t = t.t + 1;
			q.push(now);
		}
	}
	return -1;
}
int main()
{
	freopen("bus.in" , "r" , stdin);
	freopen("bus.out" , "w" , stdout);
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i++)
	{
		ll u , v , a;
		cin >> u >> v >> a;
		if (u == 1 && v != 1)st.push_back(a);
		e[u].push_back(make_pair(v , a));
	}
	ll mn = 9e18;
	for (int i = 0; i < st.size(); i++)mn = min(mn , bfs(st[i]));
	cout << mn;
	return 0;
}
