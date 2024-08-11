#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MXN=1e5+10;
int n,d;
LL v[MXN],a[MXN];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>d;
    LL s=0;
    for(int i=1;i<n;i++){
        cin>>v[i];
        s+=v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<s/d*a[1]+(s%d!=0)*a[1]<<'\n';
    return 0;
}
