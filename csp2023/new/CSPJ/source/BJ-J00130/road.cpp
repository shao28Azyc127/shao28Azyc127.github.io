#include<iostream>
using namespace std;
long long v[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++) cin>>v[i];
    for(int i=1;i<=n;i++) v[i]=v[i]+v[i-1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n;i++) a[i]=min(a[i],a[i-1]);
    long long ans=0,cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        x=(v[i]-cnt+d-1)/d;
        ans+=x*a[i];
        cnt+=x*d;
    }
    cout<<ans<<endl;
    return 0;
}
