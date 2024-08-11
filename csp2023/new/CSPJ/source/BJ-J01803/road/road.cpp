#include <iostream>
using namespace std;
int n,d,v[100005],a[100005],need;
long long sum[100005];
int ans,minn;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for (int i=1; i<n; ++i)
    {
        cin >> v[i];
        sum[i]=sum[i-1]+v[i];

    }
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    int y=(sum[n-1]+d-1)/d;
    ans = y*a[1];
    minn = a[1];
    for (int i=2; i<=n; ++i)
    {
        if(a[i]<minn)
        {
            ans -= (minn-a[i])*(y-(sum[i-1]+d-1)/d);
            minn = a[i];
        }
    }

    cout << ans;
    return 0;
}
