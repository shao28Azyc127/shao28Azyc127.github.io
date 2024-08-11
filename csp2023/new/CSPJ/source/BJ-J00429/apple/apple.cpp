#include <bits/stdc++.h>
using namespace std;
int n, k = 1, d = -1;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while (n > 0)
    {
        if (n % 3 == 1 && d == -1) d = k;
        int f = (n - 1) / 3 + 1;
        n -= f;
        k++;
    }
    printf("%d %d\n", k - 1, d);
    return 0;
}
