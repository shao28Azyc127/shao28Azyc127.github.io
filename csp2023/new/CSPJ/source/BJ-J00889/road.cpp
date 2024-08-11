#include <bits/stdc++.h>
using namespace std;
long long v[100005],a[100005],f[100005];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    long long n,d;
    cin>>n>>d;
    for (int i=2;i<=n;i++){
        scanf("%lld",&v[i]);
        f[i]=f[i-1]+v[i];
    }
    for (int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    a[0]=1e18;
    long long ans=0,pre=1,sum=0;
    for (int i=1;i<=n;i++){
        if (a[pre]>a[i-1]) pre=i-1;
        ans+=a[pre]*ceil((f[i]-sum)/double(d));
        sum+=ceil((f[i]-sum)/double(d))*d;
        //cout<<pre<<" "<<sum<<" "<<ans<<"\n";
    }
    cout<<ans;
    return 0;
}
