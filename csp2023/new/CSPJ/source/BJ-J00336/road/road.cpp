#include<iostream>
using namespace std;
typedef long long ll;
const ll MAXN=1e5+5;
ll n,d;
ll v[MAXN],a[MAXN];
ll query(ll l,ll r){
    return v[r]-v[l-1];
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(ll i=1;i<n;++i){
        scanf("%lld",&v[i]);
        v[i]+=v[i-1];
    }
    for(ll i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    ll r=1,ans=0,val=0;
    a[n]=0;
    for(ll i=1;i<n;i=r){
        while(r<n&&a[r+1]>a[i]){
            r++;
        }
        r++;
        ll Need=query(i,r-1);
        ll k=(Need-val)/d;
        if((Need-val)%d!=0){
            k++;
        }
        val+=k*d-Need;
        ans+=a[i]*k;
        //cout<<r<<endl;
    }
    cout<<ans<<endl;
    return 0;
}

