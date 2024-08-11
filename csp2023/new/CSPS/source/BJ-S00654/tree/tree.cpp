/*
I shall be telling this with a sigh
Somewhere ages and ages hence
Two roads diverged in a wood, and I
I took the one less travelled by
And that has made all the difference
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

const int N = 1e5, E = N << 1;
const long long Max = 1e9;

typedef pair<long long, int> pir;

int n;
long long a[N + 5], b[N + 5], c[N + 5], zero[N + 5];

int head[N + 5], to[E + 5], nxt[E + 5], tot = 1;
void add_edge(int u, int v)
{
	tot++;
	to[tot] = v;
	nxt[tot] = head[u];
	head[u] = tot;
	return ;
}
void add(int u, int v)
{
	add_edge(u, v);
	add_edge(v, u);
	return ;
}

long long d[N + 5];//limit
int sz[N + 5];

void calc_d(int u, long long ans)
{
	long long l = 1, r = ans;
	d[u] = Max * 100ll;
	while (l <= r)
	{
		long long mid = (l + r) >> 1, sum = 0;

		if (c[u] >= 0)
			sum = (ans - mid + 1) * b[u]
				 + (mid + ans) * (ans - mid + 1) / 2 * c[u];
		else
		{
			if (mid > zero[u])
				sum = ans - mid + 1;
			else
				sum = (zero[u] - mid + 1) * b[u]
					 + (mid + zero[u]) * (zero[u] - mid + 1) / 2 * c[u]
					 + ans - zero[u];
		}

		if (a[u] <= sum)
		{
			d[u] = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}
	return ;
}

// bool cmp(int x, int y)
// {
// 	if (d[x] + sz[x] != d[y] + sz[y])
// 		return d[x] + sz[x] < d[y] + sz[y];
// 	if (d[x] != d[y])
// 		return d[x] < d[y];
// 	return sz[x] < sz[y];
// }
// void dfs(int u, int fa)
// {
// 	vector<int> son;
// 	sz[u] = 1;

// 	for (int i = head[u]; i; i = nxt[i])
// 	{
// 		int v = to[i];
// 		if (v == fa)
// 			continue;
// 		dfs(v, u);
// 		sz[u] += sz[v];
// 		son.push_back(v);
// 	}

// 	if (son.empty())
// 		return ;
	
// 	sort(son.begin(), son.end(), cmp);
// 	long long sum = 0;
// 	for (unsigned int t = 0; t < son.size(); t++)
// 	{
// 		int v = son[t];
// 		d[u] = min(d[u], d[v] - 1 - sum);
// 		sum += sz[v];
// 	}
// 	return ;
// }

int fa[N + 5], in[N + 5];
void dfs(int u, int father)
{
	fa[u] = father;
	in[father]++;
	for (int i = head[u]; i; i = nxt[i])
	{
		int v = to[i];
		if (v == father)
			continue;
		dfs(v, u);
	}
	return ;
}

priority_queue<pir> q;
int seq[N + 5];
bool check(long long ans)
{
	for (int i = 1; i <= n; i++)
	{
		calc_d(i, ans);
		if (d[i] > Max)
			return false;
	}

	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		if (in[i] == 0)
			q.emplace(d[i], i);
	}

	for (int T = n; T > 0; T--)
	{
		int u = q.top().second;
		q.pop();
		seq[T] = u;

		if (fa[u])
		{
			in[fa[u]]--;
			if (in[fa[u]] == 0)
				q.emplace(d[fa[u]], fa[u]);
		}
	}

	

	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << i << " " << d[i] << endl;
	// }
	// cout << endl;

	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << seq[i] << " ";
	// }
	// cout << endl;




	// dfs(1, 0);


	
	// for (int i = 1; i <= n; i++)
	// {
	// 	cout << i << " " << d[i] << endl;
	// }
	// cout << endl;
	


	// if (d[1] < 1ll)
	// 	return false;
	// return true;

	for (int i = 1; i <= n; i++)
	{
		if (1ll * i > d[seq[i]])
			return false;
	}
	return true;

}

int main()
{
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld%lld%lld", a + i, b + i, c + i);
		if (c[i] < 0)
			zero[i] = (1ll - b[i]) / c[i];
	}
	for (int i = 1, u, v; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		add(u, v);
	}


	// check(5);
	// exit(0);


	long long l = 1, r = Max, ans = 0;
	while (l <= r)
	{
		long long mid = (l + r) >> 1;
		if (check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}