#include <bits/stdc++.h>
#define int long long
using namespace std;
int dp[1000001]={0};
int n,k,dis[1000001]={0},cost[1000001]={0},ardis[1000001]={0},lastdis[1000001]={0},yes=0;
signed main(){
    FILE* f=freopen("road.in","r",stdin);
    FILE* f2=freopen("road.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<n;i++){
        cin>>dis[i];
        ardis[i+1]=ardis[i]+dis[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            double d=(double)(ardis[i]-ardis[j]-lastdis[j])/(double)k;
            int d2=ceil(d);
            int m=d2*k-(ardis[i]-ardis[j]-lastdis[j]);
            int costNow=dp[j]+(d2*cost[j]);
            if(costNow<dp[i]||!dp[i]){
                dp[i]=costNow;
                lastdis[i]=m;
                yes=1;
            }
            if(costNow==dp[i]&&lastdis[j]>lastdis[i]&&!yes){
                lastdis[i]=m;
            }
            lastdis[1]=0;
            m=0;
        }
    }
    cout<<dp[n];
    fclose(f);
    fclose(f2);
    return 0;
}
