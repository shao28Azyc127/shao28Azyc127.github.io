#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin >> n;
    int ans = 0, ans1 = 0;
    while(n > 0)
    {
        ans++;
        if(n % 3 == 1 && ans1 == 0) ans1 = ans;
        n -= (n + 2) / 3;
    }
    cout << ans << " " << ans1;
    return 0;
}
