#include<bits/stdc++.h>
using namespace std;
#define N 500005
int c,n,m,q,a[N],b[N],dp[2005][2005];
vector<pair<int,int> > vx,vy;
inline int chk1(){
    if(a[1]>b[1]&&a[n]>b[m]){
        memset(dp,0,sizeof dp);
        for(int j=1;j<=m;++j){if(a[1]>b[j]) dp[1][j]=1;else break;}
        for(int i=2,f;i<=n;++i){
            f=dp[i-1][1];
            for(int j=1;j<=m;++j){
                f|=dp[i-1][j];
                if(b[j]>=a[i]) f=0;
                dp[i][j]=f;
            }
        }
        return dp[n][m];
    }else if(a[1]<b[1]&&a[n]<b[m]){
        memset(dp,0,sizeof dp);
        for(int j=1;j<=n;++j){if(b[1]>a[j]) dp[1][j]=1;else break;}
        for(int i=2,f;i<=m;++i){
            f=dp[i-1][1];
            for(int j=1;j<=n;++j){
                f|=dp[i-1][j];
                if(a[j]>=b[i]) f=0;
                dp[i][j]=f;
            }
        }
        return dp[m][n];
    }
    return 0;
}
inline int chk2(){
    return 1;
}
int main(){
    //system("diff expand3.ans expand.out -Z");exit(0);
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
    if(c<=7) cout<<chk1();
    else cout<<chk2();
    for(int sx,sy,p,v;q--;){
        cin>>sx>>sy;
        vx.clear(),vy.clear();
        for(int i=1;i<=sx;++i) cin>>p>>v,vx.push_back(make_pair(p,a[p])),a[p]=v;
        for(int i=1;i<=sy;++i) cin>>p>>v,vy.push_back(make_pair(p,b[p])),b[p]=v;
        if(c<=7) cout<<chk1();
        else cout<<chk2();
        for(auto p:vx) a[p.first]=p.second;
        for(auto p:vy) b[p.first]=p.second;
    }
}
