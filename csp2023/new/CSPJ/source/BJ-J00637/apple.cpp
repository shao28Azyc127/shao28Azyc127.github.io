#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long n1, cnt, ans;

int main ()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%lld", &n1);
    while (n1 > 1)
    {

        if (n1 % 3 == 1)
        {
            if (ans == 0) ans = cnt + 1;
                else ans = min(ans, cnt + 1);
        }
        n1 = n1 - ceil((double)n1 / 3);
        cnt++;
    }
    if (n1 == 1) cnt++;
    if (ans == 0) ans = cnt;
    printf("%lld %lld", cnt, ans);

    return 0;
}
