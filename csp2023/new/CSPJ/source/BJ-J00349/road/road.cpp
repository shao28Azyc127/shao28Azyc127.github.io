#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
const int N = 100005;
int n,d;
int v[N],a[N];
long long ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin >> n >> d;
    rep(i,n-1)
    {
        cin >> v[i];
        ans+=v[i];
    }
    rep(i,n)
    cin >> a[i];
    if(ans%d==0)
        ans/=d;
    else ans=ans/d+1;
    cout << ans*a[0];
    return 0;
}
