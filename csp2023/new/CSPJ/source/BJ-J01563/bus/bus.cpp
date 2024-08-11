#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    cin>>n>>m>>k;
    cout<<((m+k-1)/k*k)<<'\n';
    return 0;
}
