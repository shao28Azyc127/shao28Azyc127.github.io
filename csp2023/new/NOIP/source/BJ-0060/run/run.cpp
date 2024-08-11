#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#define ll long long
#define _1 first
#define _2 second
#define _mp make_pair
#define _pb push_back
#define inf 222222222222ll
#define MAX_N 432222

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');if(v)return -x;return x;}
char gtc(){char c = 0;do c = getchar();while(c < 33);return c;}

struct node
{
    int l, r;
    ll d, mx;
    node *lc, *rc;
    void add(ll k) { d += k, mx += k; }
    void pUp() { mx = max(lc->mx, rc->mx); }
    void pDown()
    {
        if(l != r && d)
            lc->add(d), rc->add(d), d = 0;
    }

    void update(int L, int R, ll k)
    {
        pDown();
        if(l == L && r == R)
        {
            add(k);
            return;
        }
        int mid = (l + r) >> 1;
        if(R <= mid)
            lc->update(L, R, k);
        else if(L > mid)
            rc->update(L, R, k);
        else
            lc->update(L, mid, k), rc->update(mid + 1, R, k);
        pUp();
    }

    ll query(int L, int R)
    {
        pDown();
        if(l == L && r == R)
            return mx;
        int mid = (l + r) >> 1;
        if(R <= mid)
            return lc->query(L, R);
        if(L > mid)
            return rc->query(L, R);
        return max(lc->query(L, mid), rc->query(mid + 1, R));
    }
} _pool[MAX_N * 2], *null = _pool;

int _tot;

node* make(int l, int r)
{
    _pool[++_tot] = (node){l, r, 0, 0, null, null};
    return _pool + _tot;
}

node* bT(int l, int r)
{
    node* t = make(l, r);
    if(l == r)
        return t;
    int mid = (l + r) >> 1;
    t->lc = bT(l, mid), t->rc = bT(mid + 1, r);
    return t;
}

ll mp[MAX_N];
ll rmp[MAX_N];

struct pnode
{
    ll l, r;
    ll k;
};

bool cmpl(pnode a, pnode b) { return a.l < b.l; }
bool cmpr(pnode a, pnode b) { return a.r < b.r; }

int n, m;
pnode b[MAX_N];
ll c[MAX_N];
ll cn, kr, d;
ll dp[MAX_N];

void MAIN()
{
    cn = read();
    m = read();
    kr = read();
    d = read();
    int sz = 0;
    mp[++sz] = -inf, mp[++sz] = cn + 1, mp[++sz] = cn + 2, mp[++sz] = cn + 3;
    for(int i = 1; i <= m; i++)
    {
        int x = read();
        int y = read();
        ll v = read();
        b[i] = (pnode){x - y + 1, x, v};
        mp[++sz] = b[i].l, mp[++sz] = b[i].r + 1;
    }
    //return;
    sort(mp + 1, mp + sz + 1);
    n = -1;
    for(int i = 1; i <= sz; i++)
        if(i == 1 || mp[i] != mp[i - 1])
            rmp[++n] = mp[i];
    n--;
    for(int i = 1; i <= n; i++)
    {
        ll len = rmp[i + 1] - rmp[i];
        c[i] = len * d;
    }
    int now = 0;
    sort(b + 1, b + m + 1, cmpl);
    for(int i = 1; i <= m; i++)
    {
        while(rmp[now] < b[i].l)
            now++;
        b[i].l = now;
    }
    now = 0;
    sort(b + 1, b + m + 1, cmpr);
    for(int i = 1; i <= m; i++)
    {
        while(rmp[now] <= b[i].r)
            now++;
        b[i].r = now - 1;
    }
    /*for(int i = 1; i <= m; i++)
        b[i].l = lower_bound(rmp + 1, rmp + n + 1, b[i].l) - rmp, b[i].r = lower_bound(rmp + 1, rmp + n + 1, b[i].r + 1) - rmp - 1;
    *//*for(int i = 1; i <= n; i++)
        printf("%lld ", rmp[i]);
    printf("\n");
    for(int i = 1; i <= m; i++)
        printf("%lld %lld %lld\n", b[i].l, b[i].r, b[i].k);
    for(int i = 1; i <= n; i++)
        printf("%lld ", c[i]);
    printf("\n");*/
    node* t = bT(0, n);
    //printf("E %d\n", n);
    //return;\
    dp[0] = 0;
    now = 1;
    int br = 0;
    for(int i = 1; i <= n; i++)
    {
        while(rmp[br] < rmp[i] - kr)
            br++;
        int bnd = br - 1;
        dp[i] = t->query(bnd, i - 1);
        //printf("%d %lld\n", i, dp[i]);
        t->update(i, i, dp[i]);
        /*if(i == 4)
            return;*/
        t->update(0, i - 1, -c[i]);
        while(now <= m && b[now].r == i)
            t->update(0, b[now].l - 1, b[now].k), now++;
    }
    printf("%lld\n", dp[n]);
}

void CLEAR()
{
    int s = max(n + 10, m + 10);
    _tot = n = m = cn = kr = d = 0;
    for(int i = 0; i < s; i++)
        b[i] = (pnode){0, 0, 0}, mp[i] = rmp[i] = dp[i] = c[i] = 0;
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    read();
    int T = read();
    while(T--)
        MAIN(), CLEAR();
    //printf("%d\n", (int)clock());
    return 0;
}
