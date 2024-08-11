//10:40 75pts at least
//10:49 have wasted 9min and I think T3over
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 500005;
int C, n, m, q;
int x[N], y[N];
int xx[N], yy[N];

int t1[N], t2[N];
int lowx[N], upx[N], cntx, lowy[N], upy[N], cnty;
int ask()
{
    if (1ll * (x[1] - y[1]) * (x[n] - y[m]) <= 0) return 0;
    bool swp = (x[1] < y[1]);
    if (swp)
    {
        swap(n, m);
        memcpy(t1, y, sizeof(t1));
        memcpy(t2, x, sizeof(t2));
    }
    else
    {
        memcpy(t1, x, sizeof(t1));
        memcpy(t2, y, sizeof(t2));
    }
    bool res = true;
    int mxx = 0, mxy = 0, mnx = 1e9, mny = 1e9;
    for (int i = 1; i <= n; i++)
    {
        mxx = max(mxx, t1[i]);
        mnx = min(mnx, t1[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        mxy = max(mxy, t2[i]);
        mny = min(mny, t2[i]);
    }
    if (mxx <= mxy || mnx <= mny) res = false;
    else
    {
        lowx[cntx = 1] = upx[1] = t1[1];
        for (int i = 2; t1[i - 1] != mxx; i++)
        {
            if (t1[i] < lowx[cntx])
            {
                lowx[++cntx] = t1[i];
                upx[cntx] = upx[cntx - 1];
            }
            else upx[cntx] = max(upx[cntx], t1[i]);
        }
        upy[cnty = 1] = lowy[1] = t2[1];
        for (int i = 2; t2[i - 1] != mny; i++)
        {
            if (t2[i] > upy[cnty])
            {
                upy[++cnty] = t2[i];
                lowy[cnty] = lowy[cnty - 1];
            }
            else lowy[cnty] = min(lowy[cnty], t2[i]);
        }
        for (int tx = 1, ty = 1; upx[tx] != mxx && lowy[ty] != mny; )
        {
            if (lowx[tx + 1] > lowy[ty]) tx++;
            else if (upy[ty + 1] < upx[tx]) ty++;
            else
            {
                res = false;
                break;
            }
        }
        lowx[cntx = 1] = upx[1] = t1[n];
        for (int i = n - 1; t1[i + 1] != mxx; i--)
        {
            if (t1[i] < lowx[cntx])
            {
                lowx[++cntx] = t1[i];
                upx[cntx] = upx[cntx - 1];
            }
            else upx[cntx] = max(upx[cntx], t1[i]);
        }
        upy[cnty = 1] = lowy[1] = t2[m];
        for (int i = m - 1; t2[i + 1] != mny; i--)
        {
            if (t2[i] > upy[cnty])
            {
                upy[++cnty] = t2[i];
                lowy[cnty] = lowy[cnty - 1];
            }
            else lowy[cnty] = min(lowy[cnty], t2[i]);
        }
        for (int tx = 1, ty = 1; upx[tx] != mxx && lowy[ty] != mny; )
        {
            if (lowx[tx + 1] > lowy[ty]) tx++;
            else if (upy[ty + 1] < upx[tx]) ty++;
            else
            {
                res = false;
                break;
            }
        }
    }

    if (swp) swap(n, m);
    return res? 1: 0;
}

int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    scanf("%d%d%d%d", &C, &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%d", &xx[i]);
    for (int i = 1; i <= m; i++)
        scanf("%d", &yy[i]);
    memcpy(x, xx, sizeof(x));
    memcpy(y, yy, sizeof(y));
    printf("%d", ask());
    while (q--)
    {
        memcpy(x, xx, sizeof(x));
        memcpy(y, yy, sizeof(y));
        int kx, ky, a, b;
        scanf("%d%d", &kx, &ky);
        for (int i = 1; i <= kx; i++)
        {
            scanf("%d%d", &a, &b);
            x[a] = b;
        }
        for (int i = 1; i <= ky; i++)
        {
            scanf("%d%d", &a, &b);
            y[a] = b;
        }
        printf("%d", ask());
    }
    printf("\n");
    return 0;
}
