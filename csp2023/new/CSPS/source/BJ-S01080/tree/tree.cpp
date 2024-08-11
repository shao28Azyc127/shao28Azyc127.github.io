#include<bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 114514;

long long read()
{
	long long s = 0, f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)) s = s * 10 + ch - 48, ch = getchar();
	return s * f;
}

struct star
{
	int prev, to;
}e[N<<1];

int n;
long long a[N], b[N], c[N];
int last[N], tot, dfn[N], nfd[N], cnt;
int t[N], rt[N], dep[N], siz[N], anc[N][18];


void add(int u, int v)
{
	e[++tot] = {last[u], v};
	last[u] = tot;
}

void dfs(int cur, int fa)
{
	dep[cur] = dep[fa] + 1;
	siz[cur] = 1;
	dfn[cur] = ++cnt;
	nfd[cnt] = cur;
	anc[cur][0] = fa;
	for(int i = 1; i < 18; i++)
		anc[cur][i] = anc[anc[cur][i - 1]][i -1];
	for(int i = last[cur]; i; i = e[i].prev)
		if(e[i].to != fa)
		{
			dfs(e[i].to, cur);
			siz[cur] += siz[e[i].to];
		}
}

int kfa(int cur, int k)
{
	for(int i = 17; i >= 0; i--)
		if((1 << i) <= k)
		{
			cur = anc[cur][i];
			k -= (1 << i);
		}
	return cur;
}

struct node
{
	int l, r, lz, mx, mxn;
}tr[N << 2];

#define lson cur << 1
#define rson cur << 1 | 1

void pushup(int cur)
{
	tr[cur].mx = min(tr[lson].mx, tr[rson].mx);
	tr[cur].mxn = tr[lson].mx < tr[rson].mx ? tr[lson].mxn : tr[rson].mxn;
}

void pushdown(int cur)
{
	tr[lson].lz += tr[cur].lz ;
	tr[rson].lz += tr[cur].lz ;
	tr[lson].mx += tr[cur].lz ;
	tr[rson].mx += tr[cur].lz;
	tr[cur].lz = 0;
};

void init(int cur, int l, int r)
{
	tr[cur].l = l;
	tr[cur].r = r;
	tr[cur].mxn = l;
	if(l != r)
	{
		int mid = (l + r) >> 1;
		init(lson, l, mid);
		init(rson, mid + 1, r);
	}
}

void chg1(int cur, int tar, int k)
{
	if(tr[cur].l == tr[cur].r)
	{
		tr[cur].mx = k;
		return;
	}
	pushdown(cur);
	int mid = (tr[cur].l + tr[cur].r) >> 1;
	if(tar <= mid) chg1(lson, tar, k);
	else chg1(rson, tar, k);
	pushup(cur);
}

void chg2(int cur, int l, int r)
{
	if(tr[cur].l >= l && tr[cur].r <= r)
	{
		tr[cur].lz++;
		tr[cur].mx++;
		return;
	}
	pushdown(cur);
	int mid = (tr[cur].l + tr[cur].r) >> 1;
	if(l <= mid) chg2(lson, l, r);
	if(r > mid) chg2(rson, l, r);
	pushup(cur);
}

int qry1(int cur)
{
	return tr[cur].mxn;
}

int qry2(int cur, int tar)
{
	if(tr[cur].l == tr[cur].r)
	{
		return tr[cur].mx;
	}
	pushdown(cur);
	int mid = (tr[cur].l + tr[cur].r) >> 1;
	if(tar <= mid) return qry2(lson, tar);
	else return qry2(rson, tar);
}

bool chk2()
{
	init(1, 1, n);
	for(int i = 1; i <= n; i++)
	{
		rt[i] = 0;
		if(t[i] < dep[i]) return false;
		else chg1(1, dfn[i], t[i] - dep[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		int top =nfd[ qry1(1)];
		int dir = kfa(top, t[top] - qry2(1, dfn[top]) - 1);
	        if(i > t[dir]) 
		{
			return false;
		}
		chg1(1, dfn[dir], INF);
		chg2(1, dfn[dir], dfn[dir] + siz[dir] - 1);	
	}
	return true;
}

bool chk1(int tim)
{
	for(int i = 1; i <= n; i++)
	{
		int l =0, r = tim;
		while(l != r)
		{
			int mid = (l +r + 1) >> 1;
			long double sum = (long double)(2*b[i] +c[i]* (mid + tim)) * (tim - mid + 1) / 2; 
			if(c[i] < 0)
			{
				int lim = ceil(1.0 * (b[i] - 1) / (-c[i]));
				if(tim < lim);
				else if(mid >= lim) sum = tim - mid + 1;
				else sum = tim - lim + 1 + (long double)(2 * b[i] + c[i] * (mid + lim - 1)) * (lim - mid) / 2;
			}
			if(sum >= a[i]) l = mid;
			else r = mid - 1;
		}
		t[i] = l;
		if(!t[i]) return false;
	}
	return chk2();
}

int main()
{
#ifndef DEBUG
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
	n = read();
	for(int i = 1; i <= n; i++)
	{
		a[i] = read(); b[i] = read(); c[i] = read();
	}
	for(int i = 1; i < n; i++)
	{
		int u, v;
		u = read(); v = read();
		add(u, v); add(v, u);
	}
	dfs(1, 0);
	int l = 1, r = 1e9;
	while(l != r)
	{
		int mid = (l + r) >> 1;
		if(chk1(mid))r = mid;
		else l = mid +1;
	}
	printf("%d\n", l);
	return 0;
}

