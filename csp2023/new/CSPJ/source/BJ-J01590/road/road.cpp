#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d;
int dis=0,sum=0,v[100005],a[100005],minn=2e9,ans=0;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;++i) cin>>v[i];
    for(int i=1;i<=n;++i) cin>>a[i];
    minn=a[1];
    for(int i=2;i<=n;++i){
        sum+=v[i-1];
        if(sum>dis){
            int cha=sum-dis,jia=0;
            if(cha%d!=0)cha-=(cha)%d,jia=1;
            jia+=cha/d;
            dis+=jia*d;
            ans+=jia*minn;
        }
        minn=min(minn,a[i]);
    }
    cout<<ans;
    return 0;
}
