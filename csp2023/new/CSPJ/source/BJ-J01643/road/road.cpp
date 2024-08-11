#include <bits/stdc++.h>
using namespace std;
int n,d;
int a[10010],v[10010],dp[10010],sv[10010][10010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
        cin>>v[i];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=i;k<=j-1;k++)
                sv[i][j]+=v[k];
    /*for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
            cout<<i<<"-"<<j<<" km:"<<sv[i][j]<<endl;*/
    for(int i=1;i<=n;i++)dp[i]=1e9;
    dp[1]=0;
    for(int k=2;k<=n;k++){
        for(int i=1;i<k;i++){
            dp[k]=min(dp[k],dp[i]+((sv[i][k]/d)*a[i]));
            //cout<<dp[k]<<endl;
        }
    }
    cout<<dp[n];
    return 0;
}