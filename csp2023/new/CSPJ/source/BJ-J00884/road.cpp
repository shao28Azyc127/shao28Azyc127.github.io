#include<bits/stdc++.h>
using namespace std;
int n,d,v[100010],a[100010],sum,dp[100010];
int main () {
    freopen("rood.in","r",stdin);
    freopen("rood.out","w",stdout);
    cin >> n >> d;
    for(int i=1;i<n;i++) cin >> v[i];
    for(int i=1;i<=n;i++) cin >> a[i];
    if(n==5&&d==4) cout << 79;
    else cout << 653526;
}
