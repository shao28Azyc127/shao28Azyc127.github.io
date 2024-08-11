#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int v[100005];
int a[100005];
int mnv,ans;
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>v[i];
    for(int i=1;i<n;i++)cin>>a[i];
    mnv=a[1];
    int yxs=0;
    for(int i=1;i<=n;i++){
        if(yxs){
            v[i]-=yxs;
            yxs=0;
        }
        mnv=min(a[i],mnv);
        yxs+=((v[i]+d-1)/d)*d-v[i];
        ans+=((v[i]+d-1)/d)*mnv;
    }
    cout<<ans;
    return 0;
}
