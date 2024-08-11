#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 10;
bool a[maxn];
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    if (n == 1)
    {
        printf("1 1");
    }
    int ans1 = 0, ans2 = 0, tot = n;
    while (tot > 0)
    {
        ans1++;
        int num = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!a[j])
            {
                num = (num + 1) % 3;
                if (num == 0)
                {
                    a[j] = true;
                    tot--;
                    if (j == n)
                    {
                        ans2 = ans1;
                    }
                }
            }
        }
    }
    printf("%d %d", ans1, ans2);
    return 0;
}
