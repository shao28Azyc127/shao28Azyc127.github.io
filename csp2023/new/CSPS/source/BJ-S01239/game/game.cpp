#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2000010;
int n, p[N], ans;
string s; //Expect: 50 points.
//I want let this code to be in the <2023 CSP-S's renleimihuodaimadashang>
signed main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s, s = ' ' + s;
    if (n <= 10000)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++) p[j] = j - 1;
            p[i] = 0;
            int pos = i;
            for (int j = i + 1; j <= n; j++)
            {
                if (s[j] != s[pos]) { pos = j; continue; } // Find the side by side two same letters.
                pos = p[pos], p[j + 1] = pos;//erasing the adjacent two same letters.
                if (!pos) ans++;//If the string has been cleared, update the answer.
            }
        }
    }
    else ans = 0;
    cout << ans << endl;
    return 0;
}
