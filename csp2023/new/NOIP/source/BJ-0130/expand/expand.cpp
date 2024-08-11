#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#define mem(a,b) memset(a,b,sizeof a)
#define rep(i,n) for(int i=1;i<=n;++i)
#define re2(i,n) for(int i=2;i<=n;++i)
using namespace std;
const int N=2050;
bool dp[N][N];
int a[N],b[N],n,m,q,ta[N],tb[N];
bool d1(){
    mem(dp,0);
    int ps=1;while(ps<=m&&tb[ps]<ta[1])dp[1][ps]=1,++ps;
    re2(i,n)
    rep(r,m)
    for(int l=r,mx=0;l&&(!dp[i][r]);--l){
        mx=max(mx,tb[l]);
        if(mx>=ta[i])break;
        dp[i][r]|=(dp[i-1][l]|dp[i-1][l-1]);
    }
    return dp[n][m];
}
bool d2(){
    mem(dp,0);
    int ps=1;while(ps<=m&&tb[ps]>ta[1])dp[1][ps]=1,++ps;
    re2(i,n)
    rep(r,m)
    for(int l=r,mn=1e9;l&&(!dp[i][r]);--l){
        mn=min(mn,tb[l]);
        if(mn<=ta[i])break;
        dp[i][r]|=(dp[i-1][l]|dp[i-1][l-1]);
    }
    return dp[n][m];
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c;
    cin>>c;
    cin>>n>>m>>q;
    rep(i,n)scanf("%d",a+i),ta[i]=a[i];
    rep(i,m)scanf("%d",b+i),tb[i]=b[i];
    putchar((d1()||d2())+'0');
    while(q--){
        int aa,bb;
        cin>>aa>>bb;
        rep(i,n)ta[i]=a[i];
        rep(i,m)tb[i]=b[i];
        while(aa--){
            int x,k;scanf("%d%d",&x,&k);
            ta[x]=k;
        }
        while(bb--){
            int x,k;
            scanf("%d%d",&x,&k);tb[x]=k;
        }
        putchar((d1()||d2())+'0');
    }
    return 0;
}
