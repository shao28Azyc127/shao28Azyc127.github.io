#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long n,d,v[100010],a[100010],p[100010],ans = 1e18;
void ss(int s,long long k,long long sum)
{
    if(s == n)
    {
        ans = min(ans,sum);
        return;
    }
    for(int i = s+1;i <= n;i++)
    {
        long long l = p[i]-p[s];
        if(l <= k)ss(i,k-l,sum);
        else
        {
            long long x = (l-k)/d+((l-k)%d!=0);
            ss(i,x*d+k-l,sum+x*a[s]);
        }
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i <= n-1;i++)
    {
        cin >> v[i];
    }
    for(int i = 1;i <= n;i++)
    {
        p[i] = p[i-1]+v[i-1];
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    if(n <= 1000)
    {
        ss(1,0,0);
        cout << ans;
    }
    else
    {
        cout << p[n]/d+(p[n]%d!=0)*a[1];
    }
    return 0;
}

