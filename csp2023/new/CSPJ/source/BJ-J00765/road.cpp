#include <bits/stdc++.h>
using namespace std;
long long n,d,now,ans,a[100005],v[100005]={0,1};
int main(){
    freopen("road2.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;++i) cin>>v[i],v[i]=v[i-1]+v[i];
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<n;){
        long long j,tmp;
        for(j=i+1;j<=n;++j) if(a[j]<a[i]) break;
        if(j==n+1) j=n;
        if(v[j]-v[i]%d) tmp=(v[j]-v[i])/d+1;
        else tmp=(v[j]-v[i])/d;
        now+=tmp*d,now-=(v[j]-v[i]);
        if(now/d>=1) tmp-=now/d,now%=d;
        ans+=tmp*a[i];
        i=j;
    }
    cout<<ans;
    return 0;
}
