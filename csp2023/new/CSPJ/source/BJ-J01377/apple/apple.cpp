#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int x = n, cnt = 0, ans = -1;
    while(x > 0)
    {
        if (x % 3 == 1 && ans == -1) ans = cnt + 1;
        x -= (x % 3 == 0 ? x / 3 : x / 3 + 1);
        cnt++;
    }
    printf("%d %d\n", cnt, ans);
    return 0;
}
