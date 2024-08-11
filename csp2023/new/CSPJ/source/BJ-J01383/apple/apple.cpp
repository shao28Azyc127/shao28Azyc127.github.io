#include <bits/stdc++.h>
using namespace std;
int n;
int b[1000000005];
int cnt;
int sum;
int ans;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int w = n;
    cnt = n;
    while (cnt > 0)
    {
        n = cnt;
        cnt = 0;
        sum++;
        for (int i = 1; i <= n; i++)
        {
            if (i % 3 != 1)
            {
                cnt++;
                b[cnt] = i;
            }
            if (i % 3 == 1 && b[i] == w)
            {
                ans = sum;
            }
        }
    }
    cout << sum << " " << ans;
    return 0;
}
