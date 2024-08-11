#include <bits/stdc++.h>

using namespace std;

bool check(string a)
{
    if (a.size() % 2 == 0)
    {
        string s;
        if (a.size() == 2 && (a[0] == a[1]))
            return 1;
        if (a.size() == 2 && (a[0] != a[1]))
            return 0;
        for (int i = 1; i < a.size(); i++)
            if (a[i] == a[0])
                a[0] = a[i] = '1';
        if (a[0] != '1')
            return 0;
        for (int i = 1; i < a.size(); i++)
            if (a[i] != '1')
                s += a[i];
        if (check(s))
            return 1;
    }
    return 0;
}
int main ()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    string s, a;
    int i, j, ans = 0, n;
    cin >> n >> s;
    for (i = 0; i < s.size(); i++)
    {
        a.clear();
        for (j = i; j < s.size(); j++)
        {
            a += s[j];
            //cout << i << "-" << j << ":" << a << endl;
            if (check (a))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
