#include <bits/stdc++.h>
using namespace std;
int n;
long long d,v[100010],x[100010],val[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i = 1;i < n;i++)
    {
        scanf("%lld",&v[i]);
        x[i + 1] = x[i] + v[i];
    }
    for(int i = 1;i <= n;i++) scanf("%lld",&val[i]);
    val[n] = -0x7fffffff;
    long long t = 1,left = 0;
    long long ans = 0;
    while(t < n)
    {
        for(int i = t + 1;i <= n;i++)
        {
            if(val[i] < val[t])
            {
                if(x[i] - x[t] <= left)
                {
                    left -= (x[i] - x[t]);
                    t = i;
                    break;
                }
                long long k = ceil(1.0 * (x[i] - x[t] - left) / d);
                ans += val[t] * k;
                left = left + k * d - (x[i] - x[t]);
                t = i;
                break;
            }
        }

    }
    cout << ans;
    return 0;
}
