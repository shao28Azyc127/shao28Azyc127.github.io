#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, d, v[100005], sum[100005], a[100005], ans[100005];
ll now = 1, lst = 0, sumans = 0;
stack<ll> s;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%lld%lld", &n, &d);
    for (int i = 1; i <= n - 1; i++)
    {
        scanf("%lld", &v[i]);
        sum[i] = sum[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = n; i >= 1; i--)
    {
        while (!s.empty() && a[s.top()] > a[i]) s.pop();
        if (s.empty()) ans[i] = n;
        else ans[i] = s.top();
        s.push(i);
    }
    while (now < n)
    {
        int dis = sum[ans[now] - 1] - sum[now - 1], oil;
        if ((dis - lst) % d == 0)
            oil = (dis - lst) / d;
        else
            oil = ((dis - lst) / d + 1);
        sumans += oil * a[now];
        lst = oil * d - (dis - lst);
        now = ans[now];
        //printf("%d %d %d %d\n", now, lst, oil, sumans);
    }
    printf("%lld\n", sumans);
    return 0;
}
