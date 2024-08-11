#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1010;
const int INF=1000000000000;
int n,m ,c,t,k,d,dp[N][N],tmp[N][N];
struct Node{
    int x,y,v;
}a[N<<7];
void to_max(int& x,int   y){if(x<y) x=y;}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&k,&d);
        for(int i=1;i<=n;i++) for(int j=1;j<=n  ;j++) tmp[i][j]=0;
        for(int i=1;i<=m;i++) scanf("%lld%lld%lld",&a[i].x,&a[i].y,&a[i].v);
        for(int i=1;i<=m;i++){
            for(int j=a[i].y;j<=a[i].x;j++) tmp[a[i].x][j]+=a[i].v;
        }
        //for(int i=1;i<=n;i++){
            //for(int  j=1;j<=n;j++)
                //cerr<<tmp[i][j]<<" ";cerr<<endl;
        //}
        for(int i=1;i<=n;i++) for(int j=0;j<=i;j++) dp[i][j]=-INF;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i&&j<=k;j++) to_max(dp[i][0],dp[i-1][j]);
            for(int j=1;j<=i&&j<=k;j++) to_max (dp[i][j],dp[i-1][j-1]-d);
            for(int j=1;j<=i&&j<=k;j++) dp[i][j]+=tmp[i][j];
        }
        int ans=0;
        //for(int i=1;i<=n;i++){
        //    for(int j=0;j<=n;j++) cerr<<dp[i][j]<<" ";cerr<<endl;
        //}
        for(int i=0;i<=n;i++) to_max (ans,dp[n][i]);
        printf("%lld\n",ans);
    }
}
