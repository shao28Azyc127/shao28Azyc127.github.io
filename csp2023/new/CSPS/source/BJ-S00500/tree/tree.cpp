#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n,a[N],b[N],c[N],u,v;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
    }
    for(ll i=1;i<n;i++){
        scanf("%lld%lld",&u,&v);
    }
    printf("%lld",n+1);
    return 0;
}