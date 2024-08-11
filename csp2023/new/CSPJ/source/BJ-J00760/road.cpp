#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+1;
struct Node
{
    ll oil,cost;
}dp[N];
ll z[N];
int n,d,v[N],a[N],ans=-1;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> d;
    for(int i=1;i<n;i++)cin >> v[i],z[i]=z[i-1]+v[i];
    for(int i=1;i<=n;i++)cin >> a[i];
    cout<<(ll)(a[1]*z[n]);
    return 0;
}