#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef long double ld;

struct node
{
	int x, sz;
	ll val;
	node(int x0 = 0, int s0 = 0, ll v0 = 0)
	{
		x = x0;
		sz = s0;
		val = v0;
	}
	node operator + (node n1)
	{
		return node(x, sz + n1.sz, max(val, sz + n1.val));
	}
	friend bool operator < (node n1, node n2)
	{
		return n1.val - n1.sz < n2.val - n2.sz;
	}
};
ll a[200005];
int b[200005], c[200005];
vector<int> e[200005];
int fa[200005], f[200005], n, pos[200005];
node tmp[200005];
bool cmp(int x, int y)
{
	return tmp[y] < tmp[x];
}
void dfs(int x, int f)
{
	fa[x] = f;
	for(auto y: e[x])
		if(y != f)
			dfs(y, x);
}
int getf(int x)
{
	return (x == f[x]) ? x : (f[x] = getf(f[x]));
}
ll work(ll a, int b, int c, ll t)
{
	if(max(b + t * c, 1ll) >= a)
		return 0;
	ll rt = 0;
	if(c < 0)
	{
		int p = (b - c - 1) / (-c);
		if(p <= t)
		{
			if((t - p + 1) >= a)
				return a - 1;
			a -= (t - p + 1);
			rt += t - p + 1;
			t = p - 1;
		}
	}
	if(!c)
		return (a - 1) / b;
	if(2ll * b + (t + 1) * c <= (2 * a - 1) / t)
		return -1ll;
	// ll l, r, mid;
	// l = 1;
	// r = t;
	// while(l <= r)
	// {
	// 	mid = (l + r) >> 1;
	// 	if(2ll * b + (2 * t - mid + 1) * c <= (2 * a - 1) / mid)
	// 		l = mid + 1;
	// 	else
	// 		r = mid - 1;
	// }
	// return r + rt;
	ll B = (2 * t + 1) * c + 2 * b;
	ld dt = sqrtl((ld)B * B - (ld)8 * a * c) / (2 * c), p = (ld)B / (2 * c), pos = 1e18;
	ll ans = 0;
	if(p + dt >= 0)
		pos = min(pos, p + dt);
	if(p - dt >= 0)
		pos = min(pos, p - dt);
	ans = (ll)pos;
	while(2ll * b + (2 * t - ans) * c <= (2 * a - 1) / (ans + 1))
		ans++;
	while(ans && 2ll * b + (2 * t - ans + 1) * c > (2 * a - 1) / ans)
		ans--;
	return ans + rt;
}
bool check(ll t)
{
	int i, p, q;
	node h;
	for(i = 1; i <= n; i++)
	{
		f[i] = i;
		tmp[i] = node(i, 1, work(a[i], b[i], c[i], t));
		if(tmp[i].val == -1)
			return 0;
	}
	for(i = 1; i <= n; i++)
		pos[i] = i;
	sort(pos + 1, pos + n + 1, cmp);
	for(i = 1; i <= n; i++)
	{
		p = pos[i];
		if(p != f[p])
			continue;
		while(p != 1)
		{
			q = getf(fa[p]);
			tmp[q] = tmp[q] + tmp[p];
			f[p] = q;
			p = q;
		}
	}
	return tmp[1].val < t;
}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int i, u, v;
	ll l, r, mid;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		scanf("%lld%d%d", a + i, b + i, c + i);
	for(i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		e[u].emplace_back(v);
		e[v].emplace_back(u);
	}
	dfs(1, 0);
	l = 1;
	r = 1e9;
	while(l <= r)
	{
		mid = (l + r) >> 1;
		if(check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	printf("%lld\n", l);
	// system("grep VmPeak /proc/$PPID/status > /dev/tty");
	return 0;
}