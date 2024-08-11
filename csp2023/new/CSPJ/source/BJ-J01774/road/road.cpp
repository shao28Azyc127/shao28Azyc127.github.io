#include<bits/stdc++.h>
using namespace std;
int n,d,v[10010],a[10010];
long long vv,ys;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) {
        cin>>v[i];
        vv+=v[i];
    }
    for (int i=1;i<=n;i++) cin>>a[i];
    if(1.0*vv/d!=vv/d) ys=vv/d+1;
    else ys=vv/d;

    cout<<ys*a[1];
    return 0;
}
