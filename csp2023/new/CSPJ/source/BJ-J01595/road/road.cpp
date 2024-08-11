#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
ll n,d,v[100005],a[100005],now,les=0,ans=0;
ll jisuan(ll o){
    if(o%d==0){
        return o/d;
    }else{
        return o/d+1;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        scanf("%lld",&v[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    now=a[1];
    for(int i=1;i<=n-1;i++){
        now=min(now,a[i]);
        if(les>=v[i]){
            les=les-v[i];
            continue;
        }else{
            v[i]=v[i]-les;
            ans=ans+now*jisuan(v[i]);
            les=jisuan(v[i])*d-v[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}