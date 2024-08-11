#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            printf("NO\n");
            continue;
        }
        int p = (-b + sqrt(delta)) / 2 / a;
        int q = (-b - sqrt(delta)) / 2 / a;
        printf("%d\n", max(p, q));
    }
    return 0;
}
