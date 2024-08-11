#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, cnt = 0, ans;
    bool f = 1;
    cin >> n;
    int t = n;
    while(t)
    {
        if(t % 3 == 1 && f)
            ans = cnt + 1, f = 0;
        t -= (t + 2) / 3;
        ++cnt;
    }
    cout << cnt << ' ' << ans << endl;
    return 0;
}
