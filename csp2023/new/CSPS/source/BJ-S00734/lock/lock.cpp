#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, tot;
string a[10], tmp;
string s[1005];
map <string, int> mp;
map <string, int> mp1;
void sol(string t)
{ 
    for(int i = 0; i < t.length(); ++ i)
    {
        for(int j = '0'; j <= '9'; ++ j)
        {
            string tmp1 = t;
            if(t[i] == char(j)) continue;
            tmp1[i] = char(j);
            s[++ tot] = tmp1;
            tmp1 = t;
        }
    }
    for(int i = 0; i < t.length() - 1; ++ i)
    {
        int x = t[i] - '0', y = t[i + 1] - '0';
        int xx = x + 1, yy = y + 1;
        if(xx == 10) xx = 0;
        if(yy == 10) yy = 0;
        string tmp1 = t;
        while(xx != x)
        {
            tmp1[i] = char(xx + '0'), tmp1[i + 1] = char(yy + '0');
            s[++ tot] = tmp1;
            ++ xx, ++ yy; 
            if(xx == 10) xx = 0;
            if(yy == 10) yy = 0;
        }

    }
}

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; ++ i)
    {
        string tmp2 = "";
        for(int j = 0; j < 5; ++ j)
        {
            int x; cin >> x;
            tmp2 += char(x + '0');

        }
        a[i] = tmp2;
        sol(a[i]);
    }
    if(n == 1) 
    {
        int ans = 0;
        for(int i = 1; i <= tot; ++ i)
        {
            ++ mp[s[i]];
            if(mp[s[i]] == 1) ++ ans;
        }
        cout << ans << endl;
        return 0;
    }
    int res = 0;
    for(int i = 1; i <= tot; ++ i)
    {
        ++ mp[s[i]];
        if(mp[s[i]] == n && mp1[s[i]] == 0)
        {
            mp1[s[i]] = 1;
            ++ res;
        }
    }
    cout << res << endl;
    return 0;
}
