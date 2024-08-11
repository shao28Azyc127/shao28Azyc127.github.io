#include <cstdio>
#include <algorithm>
using namespace std;

#define N 100000 + 10
typedef long long ll;

int v[N];
int a[N];
ll dis[N];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    int n, d;
    scanf("%d%d", &n, &d);
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &v[i]);
        dis[i] = dis[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    ll ans = 0;
    int price = a[1];
    int oil = 0;
    for (int i = 1; i < n; )
    {
        int j = i + 1;
        while (j < n && price < a[j])
            j++;
        i = j;
        int cost = dis[j] / d + (dis[j] % d > 0);
        ans += (ll)(cost - oil) * price;
        oil = cost;
        price = a[j];
    }

    printf("%lld\n", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}