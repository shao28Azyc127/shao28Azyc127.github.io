#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+7;
ll n,d;
ll ans=0;
ll v[N],a[N];
//why can't i text chinese?
int main(){
freopen("road.in","r",stdin);
freopen("road.out","w",stdout);
scanf("%lld%lld",&n,&d);
for(int i=2;i<=n;++i){
    scanf("%lld",&v[i]);
}
for(int i=1;i<=n;++i){
    scanf("%lld",&a[i]);
}
ll pre=a[1],dis=0;
for(int i=2;i<=n;++i){
    dis+=v[i];
    if(a[i]<pre or i==n){
        ll t=dis/d;
        if((dis%d)!=0) t++;
        dis-=t*d;
        ans+=t*pre;
        pre=a[i];
        //cout<<t<<" ";

    }

}
cout<<ans;
}