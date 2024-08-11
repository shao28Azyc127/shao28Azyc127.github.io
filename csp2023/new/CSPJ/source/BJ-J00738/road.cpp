#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,v[100005],a[100005],s[100005];
int f(int b,int e,int o){
    if(b==e)return 0;
    int minn=1e18;
    for(int i=b+1;i<=n;i++){
        minn=min(1.0*minn,1ll*f(i,e,ceil(1.0*(s[i]-s[b])/d)*d-(s[i]-s[b]-o))+(ceil(1.0*(s[i]-s[b]-o)/d))*a[b]);
    }
    return minn;
}
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        s[i+1]=s[i]+v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<f(1,n,0);
    return 0;
}
