#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
ll n,d;
ll a[N],v[N],res,ans,las;
ll sum[N];
ll chufa(ll x,ll y){
    if(x%y==0){
        return x/y;
    }else{
        return x/y+1;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%lld%lld",&n,&d);
    for(int i=1;i<=n-1;++i){
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&a[i]);
    }
    for(int i=2;i<=n;++i){
        sum[i]=sum[i-1]+v[i-1];

    }
    las=0;
    a[0]=1e18;
    for(int i=2;i<=n;++i){
        if(a[i-1]<a[las]){
            //cout<<sum[i]-res<<endl;
            ans+=a[i-1]*chufa(sum[i]-res,d);
            res+=d*chufa(sum[i]-res,d);
            las=i-1;

        }else{
            ans+=a[las]*chufa(sum[i]-res,d);
            res+=d*chufa(sum[i]-res,d);
        }

    }
    cout<<ans;
    return 0;
}
