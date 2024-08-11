#include<bits/stdc++.h>
using namespace std;
int n,d,c=INT_MAX,ans,cnt;
int v[100010],a[100010],dp[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        c=min(c,a[i]);
        int x;
        if((v[i]-cnt)%d==0) x=(v[i]-cnt)/d;
        else{
            x=(v[i]-cnt)/d+1;
            cnt+=((v[i]-cnt)/d+1)*d-v[i];
        }
        dp[i]=dp[i-1]+x*c;
    }
    cout<<dp[n];
}