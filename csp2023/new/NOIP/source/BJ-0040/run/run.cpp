//12:25 all samples passed, but maybe TLE
//12:32 all samples passed with O2 in time.
//But xixiefu doesn't give me the hardest sample. Sad.
//12:44 failed!!!!!!!
//12:52 about 2.5s just then.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int M = 100005, NN = M * 100;
const ll N = 1e9, INF = 1e17;
int TT, T, m;
ll n, k, d;

struct ev
{
    int x, y;
    ll z;
    bool operator < (const ev &B) const
    {
        return x < B.x;
    }
} event[M];

ll f[NN], lazyf[NN];
int lsf[NN], rsf[NN];
int cntf;
void buildf()
{
    cntf = 1;
    f[1] = (n - 1) * d;
    lazyf[1] = 0;
    lsf[1] = rsf[1] = 0;
}
int newnodef(int r)
{
    f[++cntf] = (r - 1) * d;
    lazyf[cntf] = 0;
    lsf[cntf] = rsf[cntf] = 0;
    return cntf;
}
void pushdownf(int now)
{
    ll t = lazyf[now];
    lazyf[lsf[now]] += t;
    lazyf[rsf[now]] += t;
    f[lsf[now]] += t;
    f[rsf[now]] += t;
    lazyf[now] = 0;
}
void pushupf(int now)
{
    f[now] = max(f[lsf[now]], f[rsf[now]]);
}
void addf(int now, int l, int r, int ql, int qr, ll v)
{
    if (ql > qr) return;
    if (ql <= l && qr >= r)
    {
        f[now] += v;
        lazyf[now] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (!lsf[now]) lsf[now] = newnodef(mid);
    if (!rsf[now]) rsf[now] = newnodef(r);
    if (lazyf[now]) pushdownf(now);
    if (ql <= mid) addf(lsf[now], l, mid, ql, qr, v);
    if (qr > mid) addf(rsf[now], mid + 1, r, ql, qr, v);
    pushupf(now);
}
ll queryf(int now, int l, int r, int ql, int qr)
{
    if (ql <= l && qr >= r) return f[now];
    if (ql > r || qr < l) return -INF;
    int mid = (l + r) >> 1;
    if (!lsf[now] && l <= ql && r >= qr)
        return lazyf[now] + (qr - 1) * d;
    if (!lsf[now]) lsf[now] = newnodef(mid);
    if (!rsf[now]) rsf[now] = newnodef(r);
    if (lazyf[now]) pushdownf(now);
    return max(queryf(lsf[now], l, mid, ql, qr), queryf(rsf[now], mid + 1, r, ql, qr));
}

ll tt[NN], lazyt[NN];
int lst[NN], rst[NN];
int cntt;
void buildt()
{
    cntt = 1;
    tt[1] = 0;
    lazyt[1] = 0;
    lst[1] = rst[1] = 0;
}
int newnodet(int r)
{
    tt[++cntt] = 0;
    lazyt[cntt] = -1;
    lst[cntt] = rst[cntt] = 0;
    return cntt;
}
void pushdownt(int now)
{
    ll t = lazyt[now];
    lazyt[lst[now]] = max(lazyt[lst[now]], t);
    tt[lst[now]] = max(tt[lst[now]], t);
    lazyt[rst[now]] = max(lazyt[rst[now]], t);
    tt[rst[now]] = max(tt[rst[now]], t);
    lazyt[now] = -1;
}
void pushupt(int now)
{
    tt[now] = max(tt[lst[now]], tt[rst[now]]);
}
void addt(int now, int l, int r, int ql, int qr, ll v)
{
    if (ql > qr) return;
    if (ql <= l && qr >= r)
    {
        tt[now] = max(tt[now], v);
        lazyt[now] = max(lazyt[now], v);
        return;
    }
    if (ql > r || qr < l) return;
    int mid = (l + r) >> 1;
    if (!lst[now]) lst[now] = newnodet(mid);
    if (!rst[now]) rst[now] = newnodet(r);
    if (lazyt[now] != -1) pushdownf(now);
    addt(lst[now], l, mid, ql, qr, v);
    addt(rst[now], mid + 1, r, ql, qr, v);
    pushupt(now);
}
ll queryt(int now, int l, int r, int ql, int qr)
{
    if (ql <= l && qr >= r) return tt[now];
    if (ql > r || qr < l) return -INF;
    int mid = (l + r) >> 1;
    if (!lst[now] && ql >= l && qr <= r) return lazyt[now];
    if (!lst[now]) lst[now] = newnodet(mid);
    if (!rst[now]) rst[now] = newnodet(r);
    if (lazyt[now] != -1) pushdownt(now);
    return max(queryt(lst[now], l, mid, ql, qr), queryt(rst[now], mid + 1, r, ql, qr));
}

void outf(int now, int l, int r)
{
    if (!now) return;
    printf("%d %d %d %lld %lld %d %d\n", now, l, r, f[now], lazyf[now], lsf[now], rsf[now]);
    int mid = (l + r) >> 1;
    outf(lsf[now], l, mid);
    outf(rsf[now], mid + 1, r);
}

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    scanf("%d%d", &TT, &T);
    while (T--)
    {
        scanf("%lld%d%lld%lld", &n, &m, &k, &d);
        buildf();
        buildt();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%lld", &event[i].x, &event[i].y, &event[i].z);
        }
        sort(event + 1, event + 1 + m);
        ll ans = 0;
        for (int i = 1; i <= m; )
        {
            int j = i;
            while (j < m && event[j + 1].x == event[i].x) j++;
            for (int l = i; l <= j; l++)
                addf(1, 1, n, 1, event[l].x - event[l].y + 1, event[l].z);
            //outf(1, 1, n);
            ll nowt = queryf(1, 1, n, max(event[i].x - k + 1, 1ll), event[i].x);
            //printf("%lld\n", nowt);
            nowt -= event[i].x * d;
            ans = max(ans, nowt);
            //printf("%d %d %d %lld\n", i, j, event[i].x, nowt);
            ll dt;
            if ((dt = nowt - queryt(1, 1, n, event[i].x, event[i].x)) > 0)
            {
                addf(1, 1, n, event[i].x + 2, n, dt);
                addt(1, 1, n, event[i].x, n, nowt);
            }
            i = j + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
