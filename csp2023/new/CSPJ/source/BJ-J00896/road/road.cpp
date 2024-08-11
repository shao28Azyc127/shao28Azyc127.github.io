#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+10;
ll n,d,v[maxn],a[maxn];
ll upset(ll x,ll y){
    if(x%y==0) return x/y;
    else return x/y+1;
}
ll m,s[maxn],f[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(ll i=1;i<n;i++) cin>>v[i];
    for(ll i=1;i<n;i++) f[i]=f[i-1]+v[i];
    for(ll i=1;i<=n;i++) cin>>a[i];
    a[0]=2e9;
    for(ll i=1;i<n;i++){
        if(a[i]<a[s[m]]){
            s[++m]=i;
        }
    }
    s[++m]=n;
    ll last=0,ans=0;
    for(ll i=2;i<=m;i++){
        ll cur=f[s[i]-1]-last;
        last+=(upset(cur,d)*d);
        ans+=(upset(cur,d)*a[s[i-1]]);
    }
    cout<<ans;
    return 0;
}
