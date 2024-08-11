#include <bits/stdc++.h>
using namespace std;
struct str{
    int b,e,t;
}a[20001];
int dp[10010];
int n,m,k;
int flag=0;
long long int ans=INT_MAX;
void f(int nu){
    if(nu==n){
        if(dp[n]%k==0&&dp[n]<ans){
            ans=dp[n];
            flag=1;
        }
        return;
    }
    for(int i=0;i<m;i++){
        if(a[i].b==nu&&dp[nu]>a[i].t){
            dp[a[i].e]=dp[nu]+1;
            f(a[i].e);
            dp[nu]=0;
        }
    }
    return;
}
int main()
{
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m ;i++){
        cin>>a[i].b>>a[i].e>>a[i].t;
    }dp[1]=k;
    f(1);
    if(ans!=INT_MAX) cout<<ans;
    else cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

