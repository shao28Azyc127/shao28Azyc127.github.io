// 50
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

bool f[10010][10010]; // f[i][j] = is[i,i + 2 * j] a clearable string

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    int ans = 0;
    for(int i = 1;i < n;i++)
    {
        if(s[i] == s[i+1]) f[i][i+1] = 1;
        ans += f[i][i+1];
    }
    for(int len = 3;len <= n;len += 2)
    {
        for(int i = 1;i + len <= n;i++)
        {
            f[i][i+len] |= f[i+1][i+len-1] && s[i] == s[i+len];
            for(int k = i+1;k < i+len;k++)
            {
                f[i][i+len] |= f[i][k] && f[k+1][i+len];
                if(f[i][i+len]) break;
            }
            //if(f[i][i+len]) cout << i << " " << i+len << "\n";
            ans += f[i][i+len];
        }
    }
    cout << ans;
    return 0;
}
