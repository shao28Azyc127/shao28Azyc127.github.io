#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int n, ans, ans2;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    ans2 = 1;
    int l = 0;
    while (1)
    {
        if ((n - l) % 3 == 1) break;
        l += floor(1.0 * (n - l + 2) / 3);
        ans2++;
    }
    while (n)
    {
        n -= floor(1.0 * (n + 2) / 3);
        ans++;
    }
    cout << ans << ' ' << ans2;
    return 0;
}
