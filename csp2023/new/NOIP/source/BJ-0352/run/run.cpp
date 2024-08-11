#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
const int NR = 1e5;
const long long inf = 1e18;
int C,T,n,m,k,d;
long long tr[NR * 4 + 5],tag[NR * 4 + 5];
vector <pair <int,int> > op[NR + 5];
inline int read()
{
    int x = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9')
        ch = getchar();
    while (ch >= '0' && ch <= '9')
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    }
    return x;
}
inline void write(long long x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
    return;
}
inline void pushup(int p)
{
    tr[p] = max(tr[p << 1],tr[p << 1 | 1]);
    return;
}
inline void pushdown(int p)
{
    if (tag[p])
    {
        tr[p << 1] += tag[p];
        tr[p << 1 | 1] += tag[p];
        tag[p << 1] += tag[p];
        tag[p << 1 | 1] += tag[p];
        tag[p] = 0;
    }
    return;
}
inline void build(int p,int l,int r)
{
    tag[p] = 0;
    if (l == r)
    {
        if (l == 0)
            tr[p] = 0;
        else
            tr[p] = -inf;
    }
    else
    {
        int mid = l + r >> 1;
        build(p << 1,l,mid);
        build(p << 1 | 1,mid + 1,r);
        pushup(p);
    }
    return;
}
inline void upd(int p,int l,int r,int u,int v,int w)
{
    if (l >= u && r <= v)
    {
        tr[p] += 1ll * w;
        tag[p] += 1ll * w;
    }
    else
    {
        int mid = l + r >> 1;
        pushdown(p);
        if (u <= mid)
            upd(p << 1,l,mid,u,v,w);
        if (v >= mid + 1)
            upd(p << 1 | 1,mid + 1,r,u,v,w);
        pushup(p);
    }
    return;
}
inline void mdf(int p,int l,int r,int u,long long v)
{
    if (l == r)
        tr[p] = v;
    else
    {
        int mid = l + r >> 1;
        pushdown(p);
        if (u <= mid)
            mdf(p << 1,l,mid,u,v);
        else
            mdf(p << 1 | 1,mid + 1,r,u,v);
        pushup(p);
    }
    return;
}
inline int pos(int x,int d)
{
    int tmp = (x - d) % (k + 1);
    if (tmp < 0)
        tmp += k + 1;
    return tmp;
}
int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    C = read();
    T = read();
    while (T--)
    {
        n = read();
        m = read();
        k = read();
        d = read();
        for (int i = 1;i <= n;i++)
            op[i].clear();
        for (int i = 1;i <= m;i++)
        {
            int x = read(),y = read(),z = read();
            op[x].push_back(make_pair(y,z));
        }
        build(1,0,k);
        for (int i = 1;i <= n;i++)
        {
            int p1 = pos(1,i),p2 = pos(k,i),p3 = pos(0,i);
            long long tmp = tr[1];
            if (p1 <= p2)
                upd(1,0,k,p1,p2,-d);
            else
            {
                upd(1,0,k,p1,k,-d);
                upd(1,0,k,0,p2,-d);
            }
            for (auto x : op[i])
                if (x.first <= k)
                {
                    p1 = pos(x.first,i);
                    if (p1 <= p2)
                        upd(1,0,k,p1,p2,x.second);
                    else
                    {
                        upd(1,0,k,p1,k,x.second);
                        upd(1,0,k,0,p2,x.second);
                    }
                }
            mdf(1,0,k,p3,tmp);
        }
        write(tr[1]);
        putchar('\n');
    }
    return 0;
}