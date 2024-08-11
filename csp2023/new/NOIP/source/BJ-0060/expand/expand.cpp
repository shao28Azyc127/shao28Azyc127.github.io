#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#define ll long long
#define _1 first
#define _2 second
#define _mp make_pair
#define _pb push_back
#define inf 222222222222ll
#define MAX_N 522222
#define MAX_LOG 21

using namespace std;

ll read(){ll x = 0;char c = 0, v = 0;do{c = getchar();if(c == '-')v = 1;} while(c < '0' || c > '9');do{x = (x << 3) + (x << 1) + c - '0';c = getchar();} while(c >= '0' && c <= '9');if(v)return -x;return x;}
char gtc(){char c = 0;do c = getchar();while(c < 33);return c;}

int vn, vm;
ll ssta[MAX_N], sstb[MAX_N], va[MAX_N], vb[MAX_N];

int n, m;
ll a[MAX_N], b[MAX_N];
int bac[MAX_N], nxt[MAX_N]; // < b[i]
ll bacmx[MAX_N], nxtmx[MAX_N];

bool MAIN()
{
    if(va[1] < vb[1])
    {
        n = vm, m = vn;
        for(int i = 1; i <= n; i++)
            a[i] = vb[i];
        for(int i = 1; i <= m; i++)
            b[i] = va[i];
    }
    else
    {
        n = vn, m = vm;
        for(int i = 1; i <= n; i++)
            a[i] = va[i];
        for(int i = 1; i <= m; i++)
            b[i] = vb[i];
    }
    if(a[1] <= b[1] || a[n] <= b[m])
        return 0;
    ll mxp = 0, mxv = -inf;
    for(int i = 1; i <= n; i++)
        if(a[i] > mxv)
            mxv = a[i], mxp = i;
    for(int i = 1; i <= m; i++)
        if(b[i] >= mxv)
            return 0;
    //printf("mxp = %d\n", mxp);
    mxv = -inf;
    ll now = 0, val = inf;
    for(int i = 1; i <= m; i++)
    {
        mxv = max(mxv, b[i]);
        if(b[i] < val)
            val = b[i], nxt[now] = i, nxtmx[now] = mxv, now = i, mxv = b[i];
    }
    nxtmx[now] = mxv;
    mxv = -inf;
    now = m + 1, val = inf;
    for(int i = m; i; i--)
    {
        mxv = max(mxv, b[i]);
        if(b[i] < val)
            val = b[i], bac[now] = i, bacmx[now] = mxv, now = i, mxv = b[i];
    }
    bacmx[now] = mxv;
    now = 1;
    for(int i = 1; i < mxp; i++)
    {
        if(nxt[now] && a[i] > nxtmx[now])
        {
            while(nxt[now] && a[i] > nxtmx[now])
                now = nxt[now];
            continue;
        }
        if(a[i] <= b[now])
            return 0;
    }
    now = m;
    for(int i = n; i > mxp; i--)
    {
        if(bac[now] && a[i] > bacmx[now])
        {
            while(bac[now] && a[i] > bacmx[now])
                now = bac[now];
            continue;
        }
        if(a[i] <= b[now])
            return 0;
    }
    return 1;
}

void CLEAR()
{
    n = m = 0;
    int s = max(vn + 10, vm + 10);
    for(int i = 0; i < s; i++)
        a[i] = b[i] = nxt[i] = bac[i] = nxtmx[i] = bacmx[i] = 0;
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    read();
    vn = read();
    vm = read();
    int T = read();
    for(int i = 1; i <= vn; i++)
        va[i] = ssta[i] = read();
    for(int i = 1; i <= vm; i++)
        vb[i] = sstb[i] = read();
    putchar(MAIN() ? '1' : '0'), CLEAR();
    while(T--)
    {
        for(int i = 1; i <= vn; i++)
            va[i] = ssta[i];
        for(int i = 1; i <= vm; i++)
            vb[i] = sstb[i];
        int ka = read();
        int kb = read();
        for(int i = 1; i <= ka; i++)
        {
            int p = read();
            ll v = read();
            va[p] = v;
        }
        for(int i = 1; i <= kb; i++)
        {
            int p = read();
            ll v = read();
            vb[p] = v;
        }
        putchar(MAIN() ? '1' : '0'), CLEAR();
    }
    putchar('\n');
    return 0;
}
