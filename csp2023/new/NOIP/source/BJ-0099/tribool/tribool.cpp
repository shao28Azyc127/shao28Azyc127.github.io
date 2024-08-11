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
const int NR=1e5+20;
const int T=1e5+2, F=1e5+3, U=1e5+7;
int cid, ttt;
struct edge {
    int to, w, nxt;
};
struct graph {
    edge e[NR*2];
    int head[NR], cnt;
    void clear() {
        rps(i, 0, cnt)e[i]=(edge){0, 0, 0};
        mem(head, 0), cnt=0;
    }
    inline void add(int u, int v, int w) {
        e[++cnt]=(edge){v, w, head[u]};head[u]=cnt;
    }
}g;
inline int fei(int x) {
    if(x==T)return F;
    if(x==F)return T;
    if(x==U)return U;
    return -x;
}
int n, m, p[NR], col[NR];
bool flg;
int ctsz;
void efs(int x, int pol) {
    if(col[x]>0 && col[x]!=pol)flg=false;
    if(col[x]>0)return;
    col[x]=pol, ctsz+=(abs(x)<=n);
    rpg(i, g, x) {
        int y=g.e[i].to, w=g.e[i].w, yg;
        if(w==0)yg=pol;
        else yg=fei(pol);
        efs(y, yg);
    }
}
void work() {
    g.clear();
    read(n), read(m);
    rps(i, 1, n)p[i]=i, col[i]=0;
    while(m--) {
        char op;
        scanf(" %c", &op);
        int x, y;
        if(op=='+' || op=='-') {
            read(x), read(y);
            if(op=='+')p[x]=p[y];
            else p[x]=fei(p[y]);
        }
        else {
            read(x);
            if(op=='T')p[x]=T;
            if(op=='F')p[x]=F;
            if(op=='U')p[x]=U;
        }
    }
    int ans=0;
    rps(i, 1, n) {
        g.add(i, abs(p[i]), (p[i]<0));
        g.add(abs(p[i]), i, (p[i]<0));
    }
    flg=true, ctsz=0, efs(T, T);
    flg=true, ctsz=0, efs(F, F);
    flg=true, ctsz=0, efs(U, U), ans+=ctsz;
    rps(i, 1, n)if(col[i]==0)flg=true, ctsz=0, efs(i, T), ans+=(!flg)*ctsz;
    printf("%d\n", ans);
}
int main() {
    opf("tribool");
    read(cid), read(ttt);
    while(ttt--)work();
    return 0;
}
}
int main() {
    return cszhpdx::main();
}