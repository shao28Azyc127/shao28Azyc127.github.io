#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAX_NUM=1e5+5;
ll n,d,v[MAX_NUM],a[MAX_NUM];
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) {
        cin>>v[i];
    }
    ll minx=1e18;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        minx=min(minx,a[i]);
    }
    if(minx==a[1]) {
        ll sum=0;
        for(int i=1;i<n;i++) {
            sum+=v[i];
        }
        cout<<a[1]*ll(ceil(sum/d));
    }
    return 0;
}
