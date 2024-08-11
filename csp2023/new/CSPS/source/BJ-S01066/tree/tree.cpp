//17:45 Why still haven't debugged it? I'm a dinner.
//18:04 I think I got the problem 10 min ago. But still can't work.
//18:07 Worked out. I would think I aked.
//18:19 woyao wan yuanshen, woyao wan yuanshen (ku
//18:20 yuanshen, qidong!
//18:21 yuanshen zenmenile?
//18:22 yuanlai, niye wan yuanshen!
//18:23 I want to play Arcaea, I want to play Arcaea (cry
//18:24 Arcaea, launch!
//18:25 What did Arcaea do to you?
//18:26 Wow, so you play Arcaea too!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005, M = N * 2;
const double eps = 1e-8;
int n;
ll a[N], b[N], c[N];

int x[N], y[N];
int siz[N];
int e, head[N], nxt[M], to[M];
void adde(int x, int y)
{
    e++;
    to[e] = y;
    siz[y]++;
    nxt[e] = head[x];
    head[x] = e;
}
int dfn[N], cnt;
void dfs(int now, int f)
{
    dfn[now] = ++cnt;
    for (int i = head[now]; i; i = nxt[i])
        if (to[i] != f)
            dfs(to[i], now);
}

ll nd[N];
ll getv(int now, ll st, ll ed)
{
    if (c[now] < 0)
    {
        ll rua = (ll)ceil((double)b[now] / (c[now] * -1) - eps);
        if (rua > ed)
            return b[now] * (ed - st + 1) + (c[now] * (st + ed)) * (ed - st + 1) / 2;
        else if (rua >= st)
        {
            return b[now] * (rua - st) + (c[now] * (st + rua - 1)) * (rua - st) / 2 + (ed - rua + 1);
        }
        else return ed - st + 1;
    }
    else return b[now] * (ed - st + 1) + (c[now] * (st + ed)) * (ed - st + 1) / 2;
}
void getnd(ll lim)
{
    for (int i = 1; i <= n; i++)
    {
        ll L = 0, R = n;
        if (c[i] > 0 && (double)c[i] * (lim + n) * (lim - n) > 1e18 + 5e17)
        {
            nd[i] = n;
            continue;
        }
        while (L != R)
        {
            ll mid = (L + R + 1) / 2;
            if (getv(i, mid, lim) >= a[i])
                L = mid;
            else
                R = mid - 1;
        }
        nd[i] = L;
    }
}

int ru[N];
vector <int> tong[N];

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld%lld", &a[i], &b[i], &c[i]);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        adde(x[i], y[i]);
        adde(y[i], x[i]);
    }
    dfs(1, 0);
    e = 0;
    memset(head, 0, sizeof(head));
    memset(siz, 0, sizeof(siz));
    for (int i = 1; i < n; i++)
        if (dfn[x[i]] < dfn[y[i]])
            adde(y[i], x[i]);
        else
            adde(x[i], y[i]);
    ll L = n, R = 1e9;
    while (L != R)
    {
        ll mid = (L + R) / 2;
        getnd(mid);
        for (int i = 0; i <= n; i++)
            tong[i].clear();
        for (int i = 1; i <= n; i++)
        {
            ru[i] = siz[i] + 1;
            tong[nd[i]].push_back(i);
        }
        bool ok = true;
        queue <int> dui;
        for (int i = n; i >= 1; i--)
        {
            for (int j = 0; j < tong[i].size(); j++)
                if (--ru[tong[i][j]] == 0)
                    dui.push(tong[i][j]);
            if (dui.empty())
            {
                //printf("%lld notok %d\n", mid, i);
                ok = false;
                break;
            }
            int t = dui.front();
            dui.pop();
            for (int i = head[t]; i; i = nxt[i])
                if (--ru[to[i]] == 0)
                    dui.push(to[i]);
        }
        if (ok) R = mid;
        else L = mid + 1;
    }
    printf("%lld\n", L);
    return 0;
}
