#include<bits/stdc++.h>
using namespace std;
struct str{
    int b,e,t;
}a[20010];
int dp[10010];
long long ans=INT_MAX;
int n,m,k;
void f(int nu){
    if(dp[n]!=0){
        if(dp[n]%k==0&&dp[n]<ans){
            ans=dp[n];
        }
        return;
    }
    for(int i=0;i<m;i++){
        if(a[i].b==nu&&a[i].t<dp[nu]){
            dp[a[i].e]=dp[a[i].b]+1;
            f(a[i].e);
            dp[a[i].e]=0;
        }
    }
    return;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a[i].b>>a[i].e>>a[i].t;
    }
    dp[1]=k;
    f(1);
    if(ans!=INT_MAX) cout<<ans;
    else cout<<-1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
