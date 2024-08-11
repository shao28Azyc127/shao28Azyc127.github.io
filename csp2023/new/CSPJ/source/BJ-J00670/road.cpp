#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,d,a[N],w[N];
long long ans=0;

void test(){
    cin>>n>>d;
    for(int i=1;i<n;i++)cin>>a[i];
    int minn=1e18,lst=0;
    for(int i=1;i<n;i++){
        cin>>w[i];
        a[i]-=lst;minn=min(minn,w[i]);
        if(a[i]<=0)lst=-a[i];
        else{
            lst=d-a[i]%d;
            ans+=minn*((a[i]+d-1)/d);
        }
    }
    cin>>w[n];cout<<ans<<endl;
}

signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    test();
    return 0;
}
