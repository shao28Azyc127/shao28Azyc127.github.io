#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool flag[10000000];

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, ans = 0, cnt = 0;
    cin >> n;
    int s = n, last = n, now = 0;
    while (n > 0)
    {
        cnt++;
        if (n % 3 == 1 && ans == 0)
        {
            ans = cnt;
        }
        n -= 1 + (n - 1) / 3;
    }
    cout << cnt << " " << ans << endl;
    return 0;
}