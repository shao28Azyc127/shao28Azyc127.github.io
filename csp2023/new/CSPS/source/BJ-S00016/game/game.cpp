#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char c[8010];
bool flag[8010][8010];

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < s.length(); i++)
    {
        c[i + 1] = s[i];
    }
    for (int len = 2; len <= n; len+=2)
    {
        for (int st = 1; st + len - 1 <= n; st++)
        {
            if (c[st] == c[st + len - 1] && len == 2) flag[st][st + len - 1] = true;
            else if (c[st] == c[st + len - 1]) flag[st][st + len - 1] |= flag[st + 1][st + len - 2];
            for (int cut = st + 1; cut <= st + len - 1; cut+=2)
            {
                if (flag[st][st + len - 1] == true) break;
                flag[st][st + len - 1] |= flag[st][cut] & flag[cut + 1][st + len - 1];
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j+=2)
        {
            if (flag[i][j] == true) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

