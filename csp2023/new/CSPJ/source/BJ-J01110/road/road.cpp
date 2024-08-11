#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 100005
typedef long long ll;
int main(){
    ll n,d,v[maxn]={0},a[maxn],n2=1,v2[maxn],a2[maxn],dp[maxn];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    dp[1]=0;
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(ll i=2;i<=n;i++){
        cin>>v[i];
        v[i]+=v[i-1];
    }
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        if(i==1){
            a2[1]=a[1];
        }
        if(a[i]<a2[n2]||i==n){
            n2++;
            v2[n2]=ceil((float)(v[i])/(float)(d));
            a2[n2]=a[i];
        }
    }
    for(ll i=2;i<=n2;i++){
        for(ll j=1;j<i;j++){
            dp[i]=min(dp[i],dp[j]+(v2[i]-v2[j])*a2[j]);
        }
    }
    cout<<dp[n2];
    return 0;
}
