#include <bits/stdc++.h>
using namespace std;

struct x
{
    int id;
    int maxi, minn;
    x()
    {
        id = maxi = 0;
        minn = 2e9;
    }
    bool operator < (const x &o) const
    {
        return maxi < o.maxi;
    }
} dict[3010];

bool ans[3010];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (register int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (register int j = 0; j < m; j++)
        {
            dict[i].maxi = max(dict[i].maxi, (int)s[j]);
            dict[i].minn = min(dict[i].minn, (int)s[j]);
        }
        dict[i].id = i;
    }

    sort(dict + 1, dict + n + 1);
    if (dict[1].minn >= dict[2].maxi) ans[dict[1].id] = false;
    else ans[dict[1].id] = true;
    for (int i = 2; i <= n; i++)
    {
        if (dict[i].minn >= dict[1].maxi) ans[dict[i].id] = false;
        else ans[dict[i].id] = true;
    }

    for (int i = 1; i <= n; i++)
        cout << ans[i];
    cout << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
