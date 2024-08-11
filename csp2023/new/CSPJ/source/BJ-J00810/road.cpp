#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,d,u[maxn],a[maxn],ans=0,num=0;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for (int i=1;i<n;i++) {
            cin>>u[i];
            num+=u[i];
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    if (num%d!=0) ans=(num/d+1)*a[1];
    else ans=(num/d)*a[1];
    cout<<ans<<"\n";
    return 0;
}
