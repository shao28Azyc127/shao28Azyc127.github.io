#include <bits/stdc++.h>
using namespace std;
int n, t, x, cur;
string s[1000005], s1, s2;
map<string,int> mp, MP;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    mp["byte"] = 1;
    mp["short"] = 2;
    mp["int"] = 4;
    mp["long"] = 8;
    cin >> n;
    while (n--)
    {
        cin >> t;
        if (t == 2)
        {
            cin >> s1 >> s2;
            cur = (cur + mp[s1] - 1) / mp[s1] * mp[s1];
            for (int i = cur; i < cur + mp[s1]; i++)
            {
                s[i] = s2;
            }
            MP[s2] = cur;
            cout << cur << endl;
            cur += mp[s1];
        }
        if (t == 3)
        {
            cin >> s1;
            if (MP[s1] == "")
            {
                cout << "ERR\n";
                continue;
            }
            cout << MP[s1] << endl;
        }
        if (t == 4)
        {
            cin >> x;
            cout << s[x] << endl;
        }
    }
    return 0;
}