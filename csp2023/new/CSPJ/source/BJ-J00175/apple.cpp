#include <bits/stdc++.h>
using namespace std;
int ans = 0;
int aple(int n, int a)
{
    if(ans == 0 && (n - 1) % 3 == 0) ans = a;
    if(n == 1) return 1;
    return aple(n - (n - 1) / 3 - 1, a + 1) + 1;
}
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    cout << aple(n, 1) << ' ' << ans;
    return 0;
}
