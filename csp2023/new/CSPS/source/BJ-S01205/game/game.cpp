#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out","w",stdout);
    cin >> n;
    cin >> s;
    long long ans = 0;
    bool flag = 1;
    int cur = 0;
    while(flag)
    {
        flag = false;
        for(int i = 0; i < s.size() - 1; i++)
        {
            if(s[i] == s[i + 1])
            {
                ans++;
                if(i == 0)
                {
                    cur++;
                    ans += cur - 1;
                }
                cout << s[i] << s[i + 1] << endl;
                if(s.size() == 2)
                {
                    s = "";
                    flag = false;
                    break;
                }
                s = s.substr(0, i) + s.substr(i + 2);
                flag = true;
                cout << s << endl;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
