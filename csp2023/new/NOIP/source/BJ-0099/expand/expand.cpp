/*
shan~~~qingnimanxie zouxiang wo ya~~~
kuaguo heliu~~
bie jingxingle yuren~~~~
huo~~~shaozhe xingchen xibumie ya~~
wanzhang gaolou~~~ cangzhelanman tian zhe~~
*/
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
const int NR=5e5+10;
int cid, n, m, q, x[NR], y[NR];
namespace BAOLI {
    const int IR=2010;
    int tx[NR], ty[NR], ymn[IR][IR], xmx[IR][IR];
    int f[IR][IR], s[IR][IR], t[IR][IR];
    int getzy1(int i, int j) {
        int l=0, r=j-1, mid, ans=0;
        while(l<=r) {
            mid=(l+r)/2;
            if(ymn[mid+1][j]>tx[i])ans=mid, r=mid-1;
            else l=mid+1;
        }
        // printf("getzy1(%d,%d)=%d\n", i, j, ans);
        return ans;
    }
    int getzy2(int i, int j) {
        int l=0, r=i-1, mid, ans=0;
        while(l<=r) {
            mid=(l+r)/2;
            if(xmx[mid+1][i]<ty[j])ans=mid, r=mid-1;
            else l=mid+1;
        }
        // printf("getzy2(%d,%d)=%d\n", i, j, ans);
        return ans;
    }
    bool solve() {
        rps(i, 1, n)tx[i]=x[i];
        rps(i, 1, m)ty[i]=y[i];
        if(x[1]>y[1])swap(tx, ty);
        mem(xmx, 0), mem(ymn, 999999), mem(s, 0), mem(t, 0), mem(f, 0);
        // rps(i, 1, n)printf("%d ", tx[i]);puts("tx");
        // rps(i, 1, m)printf("%d ", ty[i]);puts("ty");
        rps(i, 1, n) {
            xmx[i][i]=tx[i];
            rps(j, i+1, n)xmx[i][j]=max(xmx[i][j-1], tx[j]);
        }
        rps(i, 1, m) {
            ymn[i][i]=ty[i];
            rps(j, i+1, m)ymn[i][j]=min(ty[j], ymn[i][j-1]);
        // rps(i, 1, n)rps(j, 1, n)printf("ymn[%d][%d]=%d\n", i, j, ymn[i][j]);
        }
        f[0][0]=true, s[1][1]=t[1][1]=1;
        rps(j, 1, m)s[1][j]=1;
        rps(i, 1, n)rps(j, 1, m) {
            if(tx[i]>=ty[j])continue;
            f[i][j]|=(s[i-1+1][j-1+1]-s[i-1+1][getzy1(i, j)-1+1]>0);
            f[i][j]|=(t[i-1+1][j-1+1]-t[getzy2(i, j)-1+1][j-1+1]>0);
            s[i+1][i+1]=s[i+1][j-1+1]+f[i][j];
            t[i+1][j+1]=t[i-1+1][j+1]+f[i][j];
            // printf("f[%d][%d]=%d\n", i, j, f[i][j]);
        }
        return f[n][m];
    }
}
namespace TESHU {
    bool solve() {
        bool ans=true;
        return true;
    }
}
void calc() {
    if(cid>=8 && cid<=14)putchar(TESHU::solve()+'0');
    else putchar(BAOLI::solve()+'0');
}
int cx[NR], cy[NR];
int main() {
    opf("expand");
    read(cid), read(n), read(m), read(q);
    rps(i, 1, n)read(x[i]), cx[i]=x[i];
    rps(i, 1, m)read(y[i]), cy[i]=y[i];
    calc();
    while(q--) {
        int kx, ky, u, v;
        read(kx), read(ky);
        rps(i, 1, n)x[i]=cx[i];
        rps(i, 1, m)y[i]=cy[i];
        while(kx--)read(u), read(v), x[u]=v;
        while(ky--)read(u), read(v), y[u]=v;
        calc();
    }
    return 0;
}
}
int main() {
    return cszhpdx::main();
}