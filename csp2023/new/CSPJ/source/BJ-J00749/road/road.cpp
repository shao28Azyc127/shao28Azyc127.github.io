#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],v[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ll n,d;
    scanf("%lld%lld",&n,&d);
    for (int i=1; i<n; i++){
        scanf("%lld",&v[i]);
    }
    for (int i=1; i<=n; i++){
        scanf("%lld",&a[i]);
    }
    ll r=1;
    ll nowy=0,cntj=0,dj=0;
    ll ans=0;
    for (int i=1; i<n;){
        while(r<n&&a[r]>=a[i]){
            cntj+=v[r];
            r++;
        }
        //cout<<i<<"->"<<r<<endl;
        cntj-=dj;
        nowy=0;
        if(cntj<=0){
            dj=abs(cntj);
            cntj=0;
            i=r;
            continue;
        }
        nowy=cntj/d+(cntj%d?1:0);
        dj=nowy*d-cntj;
        ans+=nowy*a[i];
        //cout<<cntj<<" "<<nowy<<endl;
        //cout<<ans<<endl;
        cntj=0;
        i=r;
    }
    cout<<ans<<endl;
    return 0;
}
