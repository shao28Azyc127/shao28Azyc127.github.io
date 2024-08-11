#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
int v[N],a[N];
signed main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++) scanf("%lld",&v[i]);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int far=0;
    int ans=0;
    for(int i=1;i<n;i++)
    {
        ans+=ceil((v[i]-far)*1.0/d*1.0)*a[i];
        far+=ceil((v[i]-far)*1.0/d*1.0)*d-v[i];
        int t=i;
        //cout<<ans<<endl;
        while(a[t]<=a[i+1])
        {
            ans+=ceil((v[i+1]-far)*1.0/d*1.0)*a[t];
            far+=ceil((v[i+1]-far)*1.0/d*1.0)*d-v[i+1];
            i++;
            if(i+1>=n) break;
        }
    }
    cout<<ans;
    return 0;
}
