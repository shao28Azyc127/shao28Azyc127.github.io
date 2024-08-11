#include <bits/stdc++.h>
using namespace std;
int n, k, x, m, cnt;
bool flag;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    x = n;
    while (x >= 1)
    {
        if (x % 3 == 0)
        {
            m = x / 3;
        }
        else
        {
            m = x / 3 + 1;
        }
        if (x % 3 == 1 && !(flag))
        {
            k = cnt + 1;
            flag = true;
        }
        x -= m;
        cnt++;
    }
    cout << cnt << " " << k;
    return 0;
}