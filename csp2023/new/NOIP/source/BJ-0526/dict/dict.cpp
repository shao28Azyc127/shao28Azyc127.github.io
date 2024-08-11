#include <bits/stdc++.h>

using namespace std;

string s[3005];
string d[3005];
int xiao[3005];
int da[3005];

int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int i, j, k;
    int n, m;
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        cin >> s[i];
        d[i] = s[i];
        sort(&s[i][0], &s[i][m]);
        sort(&d[i][0], &d[i][m], greater<char>());
    }
    string ans = "";
    for(i=1; i<=n; i++)
    {
        bool flag = true;
        for(j=1; j<=n; j++)
        {
            if(i == j) continue;
            if(s[i] + d[j] > d[j] + s[i])
            {
                flag = false;
                break;
            }
        }
        if(flag) ans += "1";
        else ans += "0";
    }
    cout << ans << endl;
    return 0;
}
