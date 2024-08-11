#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

int n;
namespace solve1
{
    const int N = 810;
    int ans;
    string str;
    bool f[N][N];
    void main()
    {
        cin >> str;
        str = ' ' + str;
        for (int len = 2; len <= n; len += 2)
            for (int i = 1; i + len - 1 <= n; i++)
            {
                int j = i + len - 1;
                if ((i + 1 == j || f[i + 1][j - 1]) && str[i] == str[j])
                {
                    f[i][j] = 1;
                    ans++;
                    continue;
                }
                for (int k = i; k < j; k++)
                    if (f[i][k] && f[k + 1][j])
                    {
                        f[i][j] = 1;
                        break;
                    }
                if (f[i][j])
                    ans++;
            }
        cout << ans << endl;
    }
}
namespace solve2
{
    const int N = 2e6 + 10;
    int ans;
    string str;
    vector<pair<int, int>> v, w, s;
    int f[N];
    void main()
    {
        cin >> str;
        str = ' ' + str;
        for (int i = 1; i < n; i++)
            if (str[i] == str[i + 1])
                v.push_back({i, i + 1});
        s = v;
        while (1)
        {
            w.clear();
            for (auto ech : v)
            {
                int l = ech.first, r = ech.second;
                if (l - 1 >= 1 && r + 1 <= n && str[l - 1] == str[r + 1] && str[l - 1] != str[l])
                    w.push_back({l - 1, r + 1}), s.push_back({l - 1, r + 1});
            }
            if (w.empty())
                break;
            v = w;
        }
        sort(s.begin(), s.end());
        for (int i = s.size() - 1; i >= 0; i--)
        {
            int l = s[i].first, r = s[i].second;
            f[l] += 1 + f[r + 1];
        }
        for (int i = 1; i <= n; i++)
            ans += f[i];
        cout << ans << endl;
    }
}

signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    if (n <= 800)
        solve1::main();
    else
        solve2::main();
    return 0;
}

