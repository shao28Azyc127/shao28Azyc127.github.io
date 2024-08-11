//Bad news: I did'nt review the manacher method :(((((((((((
//Or the AC code is not based on it... IDK

#include <bits/stdc++.h>
using namespace std;

int ans, n;
string c;

bool check(string s)
{
    if(s.length() & 1)
    {
        return false;
    }
    if(s.length() == 0)
    {
        return true;
    }
    int l = 0, r = s.length() - 1;
    for(int i = 1; i < s.length(); i++)
    {
        if(s[i] == s[i - 1])
        {
            if(i == r)
            {
                return check(s.substr(l, (i - 1) - l));
            }
            return check(s.substr(l, (i - 1) - l) + s.substr(i + 1, r - (i + 1) + 1));
        }
    }
    return false;
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n;
    cin >> c;
    c = "_" + c;
    for(int l = 1; l < n; l++)
    {
        for(int r = l + 1; r <= n; r++)
        {
            if(check(c.substr(l, (r - l + 1))))
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}