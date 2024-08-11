#include<bits/stdc++.h>

using namespace std;
int n;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    int ans = 0, p = -1;
    while(n > 0)
    {
        ans++;
        if((n - 1) % 3 == 0 && p == -1) p = ans;
        n = n - (n / 3 + (n % 3 != 0));
    }
    printf("%d %d\n", ans, p);
    return 0;
}
