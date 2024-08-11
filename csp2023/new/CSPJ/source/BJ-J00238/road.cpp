#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,vis[100010],ans,t,d,b[100010],a[100010],y;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    n--;
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>y;
    ll h=1;
    for(int i=1;i<=n;i++){
        if(a[h]>a[i]) h=i;
        vis[i]=h;
    }
    for(int i=1;i<=n;i++){
        ll x=a[vis[i]],f=b[i]-t;
        if(f<=0){
            t-=b[i];
            continue;
        }
        else if(f%d==0){
            t=0;
            ans+=x*(f/d);
        }else{
            t=(f/d+1)*d-f;
            ans+=x*(f/d+1);
        }
    }cout<<ans;
    return 0;
}
