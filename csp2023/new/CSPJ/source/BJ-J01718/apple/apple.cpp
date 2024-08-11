#include <bits/stdc++.h>
using namespace std;

long long n, ans, now;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while(n)
    {
        now++;
        if(n % 3 == 1 && !ans)
        {
            ans = now;
        }
        n -= (n + 2) / 3;
    }
    cout << now << " " << ans << endl;
    return 0;
}