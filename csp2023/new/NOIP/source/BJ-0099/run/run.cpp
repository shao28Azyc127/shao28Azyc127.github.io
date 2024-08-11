#include<bits/stdc++.h>
using namespace std;
#define mem(a, x) memset(a, x, sizeof(a))
#define rps(i, b, e) for(int i=(b);i<=(e);i++)
#define prs(i, e, b) for(int i=(e);i>=(b);i--)
#define rpg(i, g, x) for(int i=g.head[x];i;i=g.e[i].nxt)
#define opf(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)
namespace cszhpdx {
template<class T>
void read(T &x) {
    x=0;
    bool f=false;
    char c=getchar();
    while(!isdigit(c))f|=(c=='-'), c=getchar();
    while(isdigit(c))x=x*10+(c-'0'), c=getchar();
    if(f)x=-x;
}
typedef long long LL;
const int MR=2e5+10, VR=8e5+10;
int cid, ttt;
LL n, m, k, d, x[MR], y[MR], v[MR], t[MR], tct, f[MR][2];
LL lc[VR], rc[VR], cnt, mx[VR], tg[VR];
LL build(LL l, LL r) {
    LL x=++cnt;
    if(l==r)return x;
    int mid=(l+r)/2;
    lc[x]=build(l, mid);
    rc[x]=build(mid+1, r);
    return x;
}
inline void pushup(int x) {
    mx[x]=max(mx[lc[x]], mx[rc[x]]);
}
inline void updran(LL x, LL v) {
    mx[x]+=v, tg[x]+=v;
}
inline void pushdown(LL x) {
    if(tg[x]==0 || lc[x]==0)return;
    updran(lc[x], tg[x]), updran(rc[x], tg[x]);
    tg[x]=0;
}
void upd(LL x, LL l, LL r, LL s, LL t, LL v) {
    if(s>t)return;
    if(l>=s && r<=t)return updran(x, v);
    pushdown(x);
    LL mid=(l+r)/2;
    if(mid>=s)upd(lc[x], l, mid, s, t, v);
    if(mid<t)upd(rc[x], mid+1, r, s, t, v);
    pushup(x);
}
LL query(LL x, LL l, LL r, LL s, LL t) {
    if(l>=s && r<=t)return mx[x];
    pushdown(x);
    LL mid=(l+r)/2, res=0;
    if(mid>=s)res=max(res, query(lc[x], l, mid, s, t));
    if(mid<t)res=max(res, query(rc[x], mid+1, r, s, t));
    return res;
}
vector<pair<LL, LL> >eri[MR];
void work() {
    read(n), read(m), read(k), read(d);
    t[++tct]=0, t[++tct]=n;
    rps(i, 1, m) {
        read(x[i]), read(y[i]), read(v[i]);
        t[++tct]=x[i], t[++tct]=x[i]-y[i];
    }
    sort(t+1, t+tct+1);
    tct=unique(t+1, t+tct+1)-t-1;
    // cerr<<tct<<endl;
    rps(i, 1, m) {
        int p=lower_bound(t+1, t+tct+1, x[i])-t;
        // cerr<<p<<'|'<<endl;
        eri[p].push_back(make_pair(y[i], v[i]));
    }
    // cerr<<tct<<endl;
    build(1, tct);
    rps(i, 2, tct) {
        upd(1, 1, tct, i-1, i-1, f[i-1][0]);
        upd(1, 1, tct, 1, i-1, -d*(t[i]-t[i-1]));
        for(auto p:eri[i]) {
            LL x=t[i], y=p.first, v=p.second;
            LL c=upper_bound(t+1, t+tct+1, x-y)-t-1;
            upd(1, 1, tct, 1, c, v);
        }
        LL c=lower_bound(t+1, t+tct+1, t[i]-k)-t;
        f[i][1]=query(1, 1, tct, c, i-1);
        f[i][0]=max(f[i-1][0], f[i-1][1]);
    }
    // cerr<<tct<<endl;
    printf("%lld\n", max(f[tct][0], f[tct][1]));
    rps(i, 0, tct)eri[i].clear();
    rps(i, 0, tct)f[i][0]=f[i][1]=0, t[i]=0;
    rps(i, 0, cnt)lc[i]=rc[i]=tg[i]=mx[i]=0;
    cnt=0, tct=0;
    // mem(f, 0), mem(t, 0);
    // mem(lc, 0), mem(rc, 0), mem(tg, 0), mem(mx, 0);
    mem(x, 0), mem(y, 0), mem(v, 0);
}
int main() {
    opf("run");
    read(cid), read(ttt);
    while(ttt--)work();
    return 0;
}
}
int main() {
    return cszhpdx::main();
}