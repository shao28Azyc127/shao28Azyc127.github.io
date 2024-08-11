#include<bits/stdc++.h>

using namespace std;

int n, d, v[100005], a[100005], dp[10000005];
long long sum;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    for(int i = 1; i <= n - 1; i++)
    {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= sum; j++)
        {
            if(i == 1)
            {
                dp[j] = INT_MAX;
            }
            for(int k = 1; k * d <= j; k++)
            {
                dp[j] = min(dp[j], dp[j - k * d] + a[i] * k);
            }
        }
    }
    printf("%d", dp[sum]);

    return 0;
}