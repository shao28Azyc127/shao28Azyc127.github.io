#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef long long ll;
ll n,d,mn,lft,a[N],v[N];
ll ans;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)cin>>v[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    ans+=v[1]%d==0?(v[1]/d)*a[1]:(v[1]/d+1)*a[1];
    lft=v[1]%d==0?0:d-v[1]%d;
    mn=a[1];
    for(int i=2;i<=n-1;i++){
        mn=min(mn,a[i]);
        if(lft<v[i]){
            int t=v[i]-lft;
            ans+=t%d==0?(t/d)*mn:(t/d+1)*mn;
            lft=t%d==0?0:d-t%d;
        }else{
            lft-=v[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
