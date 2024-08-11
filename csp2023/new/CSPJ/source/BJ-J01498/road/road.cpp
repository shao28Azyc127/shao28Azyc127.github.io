#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long w[100005], v[100005];
int a[100005], n, d;
long long ans = 9e18;

void dfs(int s, int e, long long sum)
{
    if (s == e)
    {
        ans = min(ans, sum);
    }
    long long minn = 0;
    int pos = -1;
    for (int i = s; i <= e; i++)
    {
        if (w[i] < minn) pos = i;
        minn = min(minn, w[i]);
    }
    long long sum1 = 0;
    for (int i = 2; i <= s; i++) sum1 += a[i];
    long long sum2 = 0;
    for (int i = 2; i <= e; i++) sum2 += a[i];
    int l = floor((sum2 - sum1) * 1.0 / d);
    dfs(s, pos, sum + l * minn);
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%d", &n, &d);
    long long minn = 2e9;
    long long sum = 0;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &w[i]);
        if (w[i] < minn) pos = i, minn = w[i];
    }
    if (minn == w[1])
    {
        long long t = ceil(sum * 1.0 / d);
        printf("%lld", t * minn);
        return 0;
    }
    int sum2 = 0;
    for (int i = 2; i <= pos; i++)
    {
        sum2 += a[i];
    }
    ans = ceil((sum - sum2) * 1.0 / d) * minn;
    dfs(1, pos, 0);
    return 0;
}
