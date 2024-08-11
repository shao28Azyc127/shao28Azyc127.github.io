#include <bits/stdc++.h>
using namespace std;
string a[3010], b[3010];
int c[3010];
signed main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        a[i] = s;
        reverse(s.begin(), s.end());
        b[i] = s;
        if (a[i] == b[i]) c[i] = 1;
    }
    sort(b + 1, b + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < b[1] || (a[i] < b[2] && a[i] == b[1] && c[i] == 1)) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return 0;
}