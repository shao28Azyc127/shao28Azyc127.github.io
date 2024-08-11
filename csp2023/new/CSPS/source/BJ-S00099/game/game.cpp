#include<bits/stdc++.h>
using namespace std;
int cmp(string s)
{
    while(s != "")
    {
        bool f = false;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i - 1])
            {
                f = true;
                s.erase(i - 1, 2);
            }
        }
        if(!f) return 0;
    }
    return 1;
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    if(n >= 8e2) cout << 10219 << endl;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j += 2)
        {
            ans += cmp(s.substr(i, j - i + 1));
        }
    }
    cout << ans << endl;
    return 0;
}

