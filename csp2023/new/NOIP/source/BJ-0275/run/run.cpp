#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int inf=0x3f3f3f3f;
ll c,t;
ll n,m,k,d;
ll a[N][N],f[N][N];
ll ans;
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&m,&n,&k,&d);
        ll x,y,z;
        memset(a,0,sizeof(a));
        memset(f,0,sizeof(f));
        ans=0;
        for(int i=1;i<=m;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            a[x][y]+=z;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                a[i][j]+=a[i][j-1];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                f[i][0]=max(f[i][0],f[i-1][j]);
            }
            for(int j=1;j<=k;j++){
                f[i][j]=f[i-1][j-1]-d+a[i][j];
            }
        }
        ll ans=0;
        for(int i=1;i=k;i++){
            ans=max(ans,f[n][i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}