#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int ans1 = 0, ans2 = 0;
    while (n > 0)
    {
        ans1++;
        if (n % 3 == 1 && ans2 == 0) ans2 = ans1;
        n = floor(1.0 * n * 2 / 3);
    }
    printf("%d %d\n", ans1, ans2);
    return 0;
}