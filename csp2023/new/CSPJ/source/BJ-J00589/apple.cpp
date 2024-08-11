#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cerr.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    int res = 0;
    int lst = n;
    while (lst)
    {
        cnt++;
        lst -= 1;
        if (lst % 3 == 0 && res == 0)
        {
            res = cnt;
        }
        int take = lst / 3;
        lst -= take;
    }
    cout << cnt << ' ' << res << endl;
    return 0;
}