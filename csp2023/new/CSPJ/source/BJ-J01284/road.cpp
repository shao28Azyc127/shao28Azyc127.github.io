#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,d;
const int N=1e5+5;
ll dis[N],c[N],f[N],g[N];

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>dis[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    f[0]=1e9;
    for(int i=1;i<=n;i++) f[i]=min(f[i-1],c[i]);
    for(int i=1;i<=n;i++) g[i]=g[i-1]+dis[i];
    ll cnt=0,ans=0;
    for(int i=1;i<n;i++){
        ll need=g[i]-cnt;
        if(need%d==0) need/=d;
        else need=need/d+1;
        ans+=need*f[i];
        cnt+=need*d;
    }
    cout<<ans;
}