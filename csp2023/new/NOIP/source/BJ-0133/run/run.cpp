#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
struct node{
    int y,v;
};
int c,t;
int n,m,k,d;
int f[N][N];
int vis[N];
vector<node> vec[N];
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        if(c<=7){
            memset(vis,0,sizeof(vis));
            for(int i=1;i<=n;i++) vec[i].clear();
            for(int i=1;i<=m;i++){
                int x,y,v;
                scanf("%lld%lld%lld",&x,&y,&v);
                vis[x]=1;
                vec[x].push_back((node){y,v});
            }
            for(int i=0;i<=n;i++) for(int j=0;j<=min(n,k);j++) f[i][j]=-1e18;
            f[0][0]=0;
            for(int i=1;i<=n;i++){
                int Max=f[i-1][0];
                for(int j=1;j<=min(n,k);j++){
                    Max=max(Max,f[i-1][j]);
                    if(vis[i]){
                        int totw=0;
                        for(int k=0;k<vec[i].size();k++) if(vec[i][k].y<=j) totw+=vec[i][k].v;
                        f[i][j]=max(f[i][j],f[i-1][j-1]-d+totw);
                    }
                    else f[i][j]=max(f[i][j],f[i-1][j-1]-d);
                }
                f[i][0]=max(f[i][0],Max);
            }
            int ans=-1e18;
            for(int i=0;i<=n;i++) for(int j=0;j<=min(n,k);j++) ans=max(ans,f[i][j]);
            printf("%lld\n",ans);
        }
        else{
            int ans=0;
            for(int i=1;i<=m;i++){
                int x,y,v;
                scanf("%lld%lld%lld",&x,&y,&v);
                if(y<=k&&y*d<=v) ans+=v-y*d;
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
