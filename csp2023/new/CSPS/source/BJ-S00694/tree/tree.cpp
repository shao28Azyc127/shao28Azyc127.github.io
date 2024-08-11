#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;

struct node
{
	ll a, b, c, t, d;
	vector<int> e;
}tr[N];
ll n, u, v, ans;

void dfs(int x, int fa)
{
	tr[x].d = tr[fa].d + 1;
	for(int i = 0; i < tr[x].e.size(); i++)
		if(tr[x].e[i] != fa) dfs(tr[x].e[i], x);
}

bool calc(int x)
{
	ll cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		ll tmp = tr[i].a;
		for(tr[i].t = x; tr[i].t && tmp > 0; tr[i].t--)
			tmp -= max(tr[i].b + tr[i].t * tr[i].c, ll(1));
		tr[i].t++;
		if(tmp > 0 || tr[i].t < tr[i].d) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> tr[i].a >> tr[i].b >> tr[i].c;
	for(int i = 1; i < n; i++)
	{
		cin >> u >> v;
		tr[u].e.push_back(v), tr[v].e.push_back(u);
	}
	dfs(1, 0);
	while(++ans)
	{
		if(!calc(ans)) continue;
		cout << ans;
		break;
	}
	
	return 0;
}