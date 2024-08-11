#include <cstdio>
#include <cmath>
using namespace std;

const int N = 1e5 + 10;
typedef long long ll;
int n, ans;
ll d, price[N], dis[N];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    scanf("%d%lld", &n, &d);
    for (int i = 1; i < n; ++i)
    {
        scanf("%lld", &dis[i]);
    }
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &price[i]);
    }
    price[n] = 0;
    int cur = 1;
    double oil = 0;
    ll ans = 0;
    while (cur != n)
    {
        ll toDis = 0;
        int next = cur;
        for (; next <= n &&
         price[next] >= price[cur]; ++next)
        {
            toDis += dis[next];
        }
        ll plusOil = ceil(toDis * 1.0 / d - oil);
        ans += price[cur] * plusOil;
        oil += plusOil;
        oil -= toDis * 1.0 / d;
        cur = next;
    }
    printf("%lld\n", ans);
}
