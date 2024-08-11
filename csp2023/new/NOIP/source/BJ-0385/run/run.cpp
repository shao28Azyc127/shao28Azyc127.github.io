#include<bits/stdc++.h>
#define LL long long
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    x*=f;
}
const LL N=1e3+10,INF=0x3f3f3f3f3f3f3f3f;
int n,m,k;
LL d;
LL f[N][N],g[N][N],ans=-INF;
struct node{
    int x,y;LL v;
}rew[N];
void solve(){
    read(n);read(m);read(k);read(d);ans=-INF;
    memset(g,0,sizeof(g));
    for(int i=1;i<=m;++i){
        read(rew[i].x);read(rew[i].y);read(rew[i].v);
        if(m>=10000){
            g[rew[i].x][rew[i].y]+=rew[i].v;
            if(rew[i].y>rew[i].x) continue;
            g[rew[i].x][min(rew[i].x+1,k+1)]-=rew[i].v;
        }
        else for(int j=rew[i].y;rew[i].x-j>=0&&j<=k;++j) g[rew[i].x][j]+=rew[i].v;
    }
    if(m>=10000){
        for(int i=1;i<=n;++i){
            for(int j=0;j<=n;++j) g[i][j]+=g[i][j-1];
        }
    }
    memset(f,-INF,sizeof(f));
    for(int i=0;i<=n;++i) f[i][0]=0;
    LL maxn=-INF;
    for(int i=1;i<=n;++i){
        f[i][0]=max(f[i-1][0],maxn);
        maxn=-INF;
        for(int j=min(i,k);j>=1;--j){
            f[i][j]=max(f[i][j],f[i-1][j-1]-d);
            f[i][j]+=g[i][j];
            maxn=max(maxn,f[i][j]);
        }
    }
    for(int i=0;i<=k;++i){
        ans=max(ans,f[n][i]);
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int T,t;read(t);read(T);
    while(T--){
        solve();
    }
    return 0;
}


