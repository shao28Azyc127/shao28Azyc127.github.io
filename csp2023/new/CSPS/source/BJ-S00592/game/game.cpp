#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

typedef long long ll;

const int N = 2000010;

int n;
string s;
bool f[810][810];
int ans;

bool check (int l, int r) {
    //cout << l << " " << r << endl;
    if (l >= r || (r - l + 1) % 2 == 1) return false;
    if (l + 1 == r && s[l] == s[r]) {
            //cout << "p1" << endl;
            return true;
    }
    else if (l + 1 == r ) {
        return false;
    }
    if (s[l] == s[r]) {
            //cout << "p" << endl;
            return check (l + 1, r - 1);
    }
    for (int i = l; i <= (l + r) / 2; i ++ ) {
        if (check (l, i) && check (i + 1, r)) {
            return true;
        }
    }

    return false;
}

int sum[N][30];
int last[30];
int dp[N], g[N];

int main () {
    freopen ("game.in", "r", stdin);
    freopen ("game.out", "w", stdout);

    ios::sync_with_stdio(false);

    cin >> n >> s;

    s = '#' + s;

    if (n <= 800) {
        for (int len = 2; len <= n; len ++ ) {
            for (int i = 1; i + len - 1 <= n; i ++ ) {
                int j = i + len - 1;
                if (check (i, j)) {
                    //cout << "--" << i << " " << j << endl;
                    ans ++ ;
                }
            }
        }
        cout << ans << endl;
    }
    else {
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 0; j < 26; j ++ ) {
                sum[i][j] = sum[i - 1][j] + (s[i] - 'a' == j);
            }
        }

        for (int i = 1; i <= n; i ++ ) {
            int x = s[i] - 'a';
            dp[i] = dp[i - 1];
            if (check (last[x], i)) {
                dp[i] += g[last[x] - 1] + 1;
                g[i] =  g[last[x] - 1] + 1;
            }

            //cout << f[i] << " ";
            last[x] = i;
        }
        cout << dp[n] << endl;
    }


    return 0;
}
