#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+5;
int n,d;
int v[MAXN],a[MAXN];
int f[MAXN];//指从站点1开到站点 i 的最小花费
int mini=0x3f3f3f3f,mi=0x3f3f3f3f,id;
int r,rb,ra;
int kms,ans;
signed main(){
    ios::sync_with_stdio(false);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        r+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<mini&&i!=n){
            mini=a[i];
            id=i;
        }
    }
    if(id==1){
        if(r%d==0) cout<<r/d;
        else cout<<r/d+1;
        return 0;
    }
    for(int i=1;i<id;i++){
        rb+=v[i];
    }
    for(int i=id;i<n;i++){
        ra+=v[i];
    }
    if(v[1]%d==0) f[2]=v[1]/d*a[1];
    else f[2]=v[1]/d*a[1]+a[1];
    kms-=v[1];
    for(int i=3;i<=id;i++){
        f[i]=min(f[i-1]+v[i-1]/d*a[i],f[1]/d*a[i]);
        kms+=f[i]*d-v[i];
    }
    ans+=f[id];
    if((ra-kms)%id==0) ans+=(ra-kms)/d*a[id];
    else ans+=(ra-kms)/d*a[id]+a[id];
    cout<<ans;
    return 0;
}
