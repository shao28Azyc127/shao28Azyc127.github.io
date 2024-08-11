#include<bits/stdc++.h>
using namespace std;
struct r{
    int s;
    int e;
    int t;
}x[20001];
int dp[10001];
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    int n,m,k,t1,t2,t3;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>x[i].s>>x[i].e>>x[i].t;
    }
    dp[1]=k;
    int minn;
    for(int i=2;i<=n;i++){
        minn=0x3f3f3f3f;
        for(int j=1;j<=m;j++){
            if(x[j].e==i){
                minn=min(max(dp[x[j].s]+1,x[j].t),minn);
            }
        }
        dp[i]=minn;
    }
    cout<<dp[n]+(3-dp[n]%3);
    return 0;
}
