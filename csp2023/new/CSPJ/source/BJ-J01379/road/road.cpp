#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

long long n , x , d[100005] , a[100005] , oil , ans;

int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    scanf("%lld%lld" , &n , &x);
    for (int i = 1; i < n; i++) scanf("%lld" , &d[i]);
    for (int i = 1; i <= n; i++) scanf("%lld" , &a[i]);
    for (int i = 1; i <= n;)
    {
        int j , sum = -oil;
        oil = 0;
        for (j = i + 1; j <= n; j++)
        {
            sum += d[j - 1];
            if (a[i] > a[j]) break;
        }
        oil -= sum;
        if (sum % x != 0) sum += x;
        oil += (sum / x * x);
        ans += (sum / x) * a[i];
        i = j;
    }
    printf("%lld" , ans);

    return 0;
}
