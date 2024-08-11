#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int l[100005], r[100005], v[100005];
int pos[200005];
ll ans[200005];
vector<int> wow[200005];
ll mx[800005], tag[800005];
void push_up(int p)
{
	mx[p] = max(mx[p << 1], mx[p << 1 | 1]) + tag[p];
}
void add(int p, int l, int r, int ql, int qr, ll k)
{
	int mid = (l + r) >> 1;
	if(ql <= l && r <= qr)
	{
		tag[p] += k;
		mx[p] += k;
		return ;
	}
	if(ql <= mid)
		add(p << 1, l, mid, ql, qr, k);
	if(qr > mid)
		add(p << 1 | 1, mid + 1, r, ql, qr, k);
	push_up(p);
}
void upd(int p, int l, int r, int q, ll k)
{
	int mid = (l + r) >> 1;
	mx[p] = max(mx[p], k);
	if(l == r)
		return ;
	k -= tag[p];
	if(q <= mid)
		upd(p << 1, l, mid, q, k);
	else
		upd(p << 1 | 1, mid + 1, r, q, k);
}
ll qry(int p, int l, int r, int ql, int qr)
{
	int mid = (l + r) >> 1;
	if(ql <= l && r <= qr)
		return mx[p];
	ll ans = 0;
	if(ql <= mid)
		ans = max(ans, qry(p << 1, l, mid, ql, qr));
	if(qr > mid)
		ans = max(ans, qry(p << 1 | 1, mid + 1, r, ql, qr));
	return ans + tag[p];
}

int main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	int c, t, n, m, k, d, x, y, i, p;
	scanf("%d%d", &c, &t);
	while(t--)
	{
		scanf("%d%d%d%d", &n, &m, &k, &d);
		for(i = 1; i <= m; i++)
		{
			scanf("%d%d%d", &x, &y, v + i);
			l[i] = x - y + 1;
			r[i] = x;
		}
		for(i = 1; i <= 2 * m; i++)
			ans[i] = 0;
		for(i = 1; i <= m; i++)
		{
			pos[2 * i - 1] = l[i] - 1;
			pos[2 * i] = r[i] + 1;
		}
		sort(pos + 1, pos + 2 * m + 1);
		c = unique(pos + 1, pos + 2 * m + 1) - pos - 1;
		for(i = 1; i <= c; i++)
			wow[i].clear();
		for(i = 1; i <= m; i++)
		{
			l[i] = lower_bound(pos + 1, pos + c + 1, l[i] - 1) - pos;
			r[i] = lower_bound(pos + 1, pos + c + 1, r[i] + 1) - pos;
			wow[r[i]].emplace_back(i);
		}
		memset(mx, 0, sizeof(mx));
		memset(tag, 0, sizeof(tag));
		p = 1;
		for(i = 1; i <= c; i++)
		{
			while(pos[p] + k + 1 < pos[i])
				p++;
			for(auto z: wow[i])
				add(1, 1, c, 1, l[z], v[z]);
			ans[i] = ans[i - 1];
			if(p < i)
				ans[i] = max(ans[i], qry(1, 1, c, p, i - 1) - (ll)d * pos[i]);
			upd(1, 1, c, i, ans[i] + (pos[i] + 1ll) * d);
		}
		printf("%lld\n", ans[c]);
	}
	return 0;
}