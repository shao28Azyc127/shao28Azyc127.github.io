#include<cstdio>
#include<iostream>
using namespace std;
long long a[100010],sum[100010];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n;
    long long k;
    scanf("%d%lld",&n,&k);
    for (int i = 2;i <= n;i++)
    {
        long long v;
        scanf("%lld",&v);
        sum[i] = sum[i - 1] + v;
    }
    for (int i = 1;i <= n;i++)
        scanf("%lld",&a[i]);
    int last = 1;
    long long ans = 0,cnt = 0;
    for (int i = 1;i <= n;i = last)
    {
        while(last < n && a[last] >= a[i]) last++;
        long long x = sum[last] - sum[i];
        x -= cnt;
        ans += (x / k + (x % k != 0 ? 1 : 0)) * a[i];
        cnt += (x / k + (x % k != 0 ? 1 : 0)) * k - (sum[last] - sum[i]);
        if (last == n) break;
    }
    printf("%lld\n",ans);
}
