#include <iostream>
#include <cstdio>
using namespace std;

int a[10000005], s[10000005];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, ans1 = 1, l, now = 1, ans2 = 1;
    cin >> n;
    l = n;
    while (l > 0)
    {
        if (a[now] == 1)
        {
            now++;
            if (now > n)
            {
                now = 1;
                ans1++;
            }
            continue;
        }
        a[now] = 1;
        l--;
        if (now == n)
        {
            ans2 = ans1;
        }
        now++;
        while (a[now] == 1)
        {
            now++;
        }
        now++;
        while (a[now] == 1)
        {
            now++;
        }
        now++;
        while (a[now] == 1)
        {
            now++;
        }
        if (l == 0)
        {
            break;
        }
        if (now > n)
        {
            now = 1;
            ans1++;
        }
    }
    cout << ans1 << " " << ans2;
    return 0;
}
