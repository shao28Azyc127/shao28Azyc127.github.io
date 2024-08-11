#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,k,tp,ct=0;
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>tp;
        ct+=tp;
    }cin>>tp;
    cout<<(tp/k+(int)(tp%k!=0))*tp;
    return 0;
}
