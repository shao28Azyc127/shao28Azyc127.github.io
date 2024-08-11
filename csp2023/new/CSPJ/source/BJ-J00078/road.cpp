#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long v[N], a[N], n, d, b[N], c=1e9, e, ans;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i=1;i<=n-1;i++)
    {
        cin >> v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=n-1;i!=0;i=e-1)
    {
        c=1e9;
        for(int j=1;j<=i;j++)
        {
            if(a[j]<c)
            {
                c=a[j];
                e=j;
            }
        }
        b[e]=1;
    }
    e=0;
    for(int i=1;i<=n-1;i++)
    {
        c=0;
        if(b[i]==1)
        {
            for(int j=i;(j==i)?1:(b[j]!=1);j++)
            {
                c+=v[j];
            }
            ans+=(c-e)/d*a[i]+a[i];
            e=d-(c-e)%d;
        }
    }
    cout << ans;
    return 0;
}
