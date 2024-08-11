#include<bits/stdc++.h>
using namespace std;
const int MX = 3005;
typedef long long LL;
int n, m, len;
string s[MX], s1[MX], sl[MX], sr[MX];
int main()
{
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) {
        sort(s[i].begin(), s[i].end());
        sl[i] = s[i];
        for (int j = 0; j < m / 2; j++) swap(s[i][j], s[i][m - j - 1]);
        sr[i] = s[i];
    }
    for (int i = 1; i <= m; i++) s[0] += "z";
    len = sqrt(n);
    for (int i = 1; (i - 1) * len + 1 <= n; i++) {
        int l = (i - 1) * len + 1, r = min(n, i * len);
        string mn = s[0];
        for (int j = 1; j <= n; j++) if (j < l || j > r) mn = min(mn, sr[j]);
        for (int j = l; j <= r; j++) {
            for (int k = l; k <= r; k++)
                if (k != j) mn = min(mn, sr[k]);
            if (sl[j] < mn) cout << 1;
            else cout << 0;
        }
    }
    return 0;
}
