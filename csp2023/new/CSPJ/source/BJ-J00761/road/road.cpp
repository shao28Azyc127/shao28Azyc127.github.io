#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 200002
using namespace std;
long long n,d,v[N],c[N],dp[N],minn=inf,last;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=2;i<=n;i++)  cin>>v[i];
    for(int i=1;i<=n;i++){
        cin>>c[i];
       // cout<<c[i]<<" ";
    }
    minn=c[1];
    for(int i=2;i<=n;i++){
        long long k=(v[i]-last)/d;
        if((v[i]-last)%d)  k++;
        dp[i]=dp[i-1]+minn*k;
        last+=d*k-v[i];
        //cout<<k<<" "<<minn<<" "<<last<<endl;
        minn=min(minn,c[i]);
    }
    cout<<dp[n];
    return 0;
}