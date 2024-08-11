#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define ll long long
ll n, ans = 0;
string st;

bool chk(int x, int y)
{
    if ((y - x) % 2 == 0) return false;
    int dic[30];
    memset(dic, 0, sizeof(dic));
    string s;
    for (int i = x; i <= y; i++)
    {
        s[i] = st[i];
        dic[st[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        if (dic[i] % 2 == 1) return false;
    while (true)
    {
        bool flag1 = true, flag2 = false;
        for (int i = x; i <= y; i++)
            if (s[i] != '0') flag1 = false;
        if (flag1) return true;
        int a = x;
        for (int i = x + 1; i <= y; i++)
        {
            if (s[i] == '0') continue;
            else if (s[i] == s[a]) s[i] = '0', s[a] = '0', flag2 = true;
            else a = i;
        }
        if (!flag2) return false;
    }
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> st;
    if (n > 8000)
    {
        for (int i = 0; i <= n - 2; i++)
            if (st[i] == st[i + 1]) ans++;
        for (int i = 0; i <= n - 4; i++)
            if (st[i] == st[i + 1] && st[i + 2] == st[i + 3]) ans++;
        for (int i = 0; i <= n - 4; i++)
            if (st[i] == st[i + 3] && st[i + 1] == st[i + 2]) ans++;
        for (int i = 0; i <= n - 4; i++)
            if (st[i] == st[i + 1] == st[i + 2] == st[i + 3]) ans--;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 1] && st[i + 2] == st[i + 3] && st[i + 4] == st[i + 5]) ans++;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 3] && st[i + 1] == st[i + 2] && st[i + 4] == st[i + 5]) ans++;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 1] && st[i + 2] == st[i + 5] && st[i + 3] == st[i + 4]) ans++;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 1] && st[i + 2] == st[i + 3] == st[i + 4] == st[i + 5]) ans--;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 1] == st[i + 2] == st[i + 3] && st[i + 4] == st[i + 5]) ans--;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 1] == st[i + 2] == st[i + 3] == st[i + 4] == st[i + 5]) ans += 3;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 5] && st[i + 1] == st[i + 4] && st[i + 2] == st[i + 3]) ans++;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 5] && st[i + 1] == st[i + 2] && st[i + 3] == st[i + 4]) ans++;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 1] == st[i + 4] == st[i + 5] && st[i + 2] == st[i + 3]) ans -= 2;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 3] == st[i + 4] == st[i + 5] && st[i + 1] == st[i + 2]) ans--;
        for (int i = 0; i <= n - 6; i++)
            if (st[i] == st[i + 1] == st[i + 2] == st[i + 5] && st[i + 3] == st[i + 4]) ans--;
        cout << ans << '\n';
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (chk(i, j)) ans++;
    cout << ans << '\n';
    return 0;
}
