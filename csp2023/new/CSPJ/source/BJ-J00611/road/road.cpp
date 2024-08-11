#include <iostream>
#include <algorithm>
using namespace std;
long long n,d,v[100005],pre[100005],a[100005],rest[100005];
long long ans;
int pos;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) pre[i]=pre[i-1]+v[i];
    pos=1; rest[1]=0;
    for(int i=2;i<=n;i++){
        if(a[i]>=a[pos]) continue;
        long long diss=pre[i]-pre[pos]-rest[pos];
        long long num=(diss+d-1)/d;
        ans+=num*a[pos]; rest[i]=num*d-diss; pos=i;
    }
    if(pos!=n){
        long long diss=pre[n]-pre[pos]-rest[pos];
        long long num=(diss+d-1)/d;
        ans+=num*a[pos];
    }
    cout<<ans<<endl;
}
