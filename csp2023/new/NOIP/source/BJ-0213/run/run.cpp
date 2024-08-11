#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int N=1100,inf=-1000000000;

int n,m,k,d,dp[N][N],x[N],y[N],w[N];
int flag[100000][2];
int ans=0;

int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    fill(dp[0],dp[0]+100000*2,inf);
    cin>>n>>m>>k>>d;
    for(int i=1;i<=m;i++){
        cin>>x[i]>>y[i]>>w[i];
        flag[x[i]][0]=y[i],flag[x[i]][1]=w[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++){
            dp[i][j]=dp[i-1][j-1]-d;
            if(j>flag[i][0])
                dp[i][j]+=flag[i][1];
            ans=max(dp[i][j],ans);
        }
    }
    cout<<ans;
    return 0;
}
