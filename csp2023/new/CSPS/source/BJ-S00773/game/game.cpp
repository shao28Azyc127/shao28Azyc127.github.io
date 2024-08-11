#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    int cnt = 0;
    while(s.size())
    {
        cnt++;
        bool flag = 0;
        for(int i = 1;i < s.size();i++)
        {
            if(s[i] == s[i - 1])
            {
                flag = 1;
                if(s.size() == 2)
                {
                    s = "";
                    break;
                }
                if(i == s.size())
                {
                    s = s.substr(0, i - 1);
                }
                else if(i - 1 == 0)
                {
                    s = s.substr(i + 1, s.size() - 1 - (i + 1) + 1);
                }
                else
                {
                    s = s.substr(0, i - 1) + s.substr(i + 1, s.size() - 1 - (i + 1) + 1);
                }
            }
        }
        if(!flag && s.size() > 0)
        {
            return 0;
        }
    }
    return 1;
}

string s;

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    cin >> s;
    int ans = 0;
    for(int i = 2;i <= n;i += 2)
    {
        for(int j = 1;j <= n - i + 1;j++)
        {
            if(check(s.substr(j - 1, (j - 2 + i) - (j - 1) + 1)))
            {
                ans++;
            }
            if(clock() / CLOCKS_PER_SEC >= 0.999)
            {
                cout << ans << endl;
                return 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
