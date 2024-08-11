#include<bits/stdc++.h>
#define int long long
using namespace std;
int v[100005];//dis
int a[100005];//price
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    int minn=0x3f3f3f3f3f3f3f3f;
    int ans=0;
    int now=0;
    int yx=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(yx!=0){//have bought some
            if(yx>v[i]){//can't use all of it
                minn=min(minn,a[i]);
                yx-=v[i];
                continue;
            }else{
                v[i]-=yx;
                yx=0;
                now=v[i];
                minn=min(minn,a[i]);
                continue;
            }
        }
        if(a[i]<minn){
            ans+=now/d*minn;
            if(now%d!=0){
                ans+=minn;
                yx=(now%d);
                if(yx<=v[i]){
                    v[i]-=yx;
                    yx=0;
                }else{
                    minn=a[i];
                    now=0;
                    yx-=v[i];
                    continue;
                }
            }
            now=v[i];
            minn=a[i];
        }else{
            now+=v[i];
        }
        //cout<<i<<" "<<ans<<endl;
    }
    ans+=now/d*minn;
    if(now%d!=0){
        ans+=minn;
    }
    cout<<ans;
    return 0;
}
