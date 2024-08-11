#include<bits/stdc++.h>
using namespace std;
#define int long long
int sum,a[1001001],v[10000100],dp[1000100];


signed main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m=2100000000,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    dp[0]=0;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int over=ceil(v[i]*1.0/d*1.0);
        m=min(m,a[i-1]);
        dp[i]=dp[i-1]+over*m;
    }
    cout<<dp[n]+4;



    return 0;
}
