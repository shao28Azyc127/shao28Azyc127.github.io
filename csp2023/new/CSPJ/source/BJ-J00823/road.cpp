#include<bits/stdc++.h>
using namespace std;
long long v[100010], a[100010];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    scanf("%d%d", &n, &d);
    for(int i = 2; i <= n; i++)
    {
        scanf("%lld", &v[i]);
        v[i] += v[i - 1];
    }
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    int j = 1;
    long long res = 0, nowpos = 0;
    for(int i = 1; i <= n; i++)
    {
        if(nowpos >= v[n]) break;
        while(j < n && a[j] >= a[i])
        {
            j++;
        }
        res += max(0ll, (v[j] - nowpos + d - 1)) / d * a[i];
        i = j - 1;
        nowpos += (v[j] - nowpos + d - 1) / d * d;
    }
    printf("%lld", res);
    return 0;
}
