#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1005,inf=1e16;
int c,t;
int n,m,k,d;

int p[N][N];
int f[N][N];
int ans;
signed main(){
  //  freopen("dat","r",stdin);
  freopen("run.in","r",stdin);
  freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ans=0;
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=k;j++)
                p[i][j]=0,f[i][j]=-inf;
        for(int i=1,x,y,v;i<=m;i++){
            scanf("%lld%lld%lld",&x,&y,&v);
            p[x][y]+=v;
        }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=k;j++)
                p[i][j]+=p[i][j-1];

        f[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++)
                f[i][0]=max(f[i][0],f[i-1][j]);
            f[i][0]+=p[i][0];
            for(int j=1;j<=k;j++)
                f[i][j]=max(f[i][j],f[i-1][j-1]+p[i][j]-d);
        }
        for(int i=1;i<=n;i++)
        for(int j=0;j<=k;j++){
            ans=max(ans,f[i][j]);
        }
        printf("%lld\n",ans);
    }


    return 0;
}
