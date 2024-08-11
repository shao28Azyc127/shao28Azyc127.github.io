#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,d;
ll v[100001];
ll a[100001];
ll dist[100001];
ll ans=1000000000;
void dfs(ll sum,ll now){
    if(now==n){
        ans=min(ans,sum);
        return;
    }
    for(int i=now+1;i<=n;i++){
        //now to i
        sum+=ceil((dist[i]-dist[now-1])/double(d))*a[i];
        dfs(sum,i);
       // sum-=ceil((dist[i]-dist[now-1])/d)*a[i];
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%lld",&v[i]);
        dist[i]=v[i]+dist[i-1];
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }//a[i]*d
    dfs(0,1);
    cout<<ans;
   fclose(stdin);
   fclose(stdout);
    return 0;
}

