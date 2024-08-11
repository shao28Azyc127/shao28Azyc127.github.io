#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const int maxn2=1e3+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct node{
    int st,ed,len;
    ll v;
}a[maxn];
int T,testcase,n,m,k,c[maxn];
vector <int> id[maxn];
ll d,dp[maxn2][maxn2];
inline void clr(int x){
    vector <int> nw;
    id[x].swap(nw);
}
inline void solve(){
    scanf("%d%d%d%lld",&n,&m,&k,&d);
    for (int i=1;i<=n;i++) if (id[i].size()) clr(i);
    for (int i=1;i<=m;i++){
         scanf("%d%d%lld",&a[i].ed,&a[i].len,&a[i].v),a[i].st=a[i].ed-a[i].len+1;
         id[a[i].ed].push_back(i);
    }
    memset(dp,-inf,sizeof(dp)),dp[0][0]=0;
    for (int i=1;i<=n;i++){
        for (int j=0;j<=k;j++) dp[i][0]=max(dp[i][0],dp[i-1][j]);
        for (int j=1;j<=k;j++) dp[i][j]=dp[i-1][j-1]-d;
        if (!id[i].size()) continue;
        for (int j=0;j<id[i].size();j++){
            int p=id[i][j];
            c[a[p].len]+=a[p].v;
        }
        for (int sum=0,j=0;j<=k;j++){
            sum+=c[j];
            dp[i][j]+=sum;
        }
        for (int j=0;j<id[i].size();j++){
            int p=id[i][j];
            c[a[p].len]-=a[p].v;
        }
    }
    /*
    for (int i=1;i<=mtot;i++){
        for (int j=0;j<=k;j++) printf("%lld ",dp[i][j]);
        printf("\n");
    }
    */
    ll ans=-inf;
    for (int i=0;i<=k;i++) ans=max(ans,dp[n][i]);
    printf("%lld\n",ans);
}
inline void solve2(){
    scanf("%d%d%d%lld",&n,&m,&k,&d);
    for (int i=1;i<=m;i++) scanf("%d%d%lld",&a[i].ed,&a[i].len,&a[i].v),a[i].st=a[i].ed-a[i].len+1;

}
int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&testcase,&T);
    while (T--){
        solve();
    }
    return 0;
}
