//36~45pts
#include<bits/stdc++.h>
#define ll long long
#define mkp(x,y) make_pair(x,y);
#define int long long
using namespace std;
const int N=1e5+5;
const int M=1e6+5;
const int INF=2e17+5;
template<typename T>
void read(T &x) {
    x=0;
    int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-48;
    x*=f;
}
int c,t,n,m,k,d;
vector<int> vis[1005],day[1005];
ll f[1005][1005];
void solve1() {
    for(int i=0;i<=n;i++)for(int j=0;j<=k;j++)f[i][j]=-INF;
    for(int i=1;i<=n;i++)vis[i].clear(),day[i].clear();
    while(m--) {
        int l,r,v;
        read(l),read(r),read(v);
        vis[l].push_back(v);
        day[l].push_back(r);
    }
    ll mx=-INF;
    f[0][0]=0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=k;j++)f[i][0]=max(f[i][0],f[i-1][j]);
        for(int j=1;j<=min(i,k);j++) {
            f[i][j]=f[i-1][j-1];
            for(int l=0;l<(int)vis[i].size();l++) {
                if(j>=day[i][l])f[i][j]+=vis[i][l];
            }
            f[i][j]-=d;
        }
    }
    ll ans=-INF;
    for(int i=0;i<=k;i++)ans=max(ans,f[n][i]);
    printf("%lld\n",max(ans,0ll));
}
void solve2() {
    ll ans=0;
    while(m--) {
        int x,y,v;
        read(x),read(y),read(v);
        if(y*d<v)ans+=v-y*d;
    }
    printf("%lld\n",ans);
}
signed main() {
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    read(c);read(t);
    while(t--) {
        read(n),read(m),read(k),read(d);
        if(c<=9)solve1();
        else if(c>=17&&c<=18)solve2();
        else solve1();
    }
    return 0;
}
