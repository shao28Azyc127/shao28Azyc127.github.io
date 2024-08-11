#include <iostream>
#include <stack>

using namespace std;

const int N = 2e6 + 5;

typedef long long ll;
bool f[8005][8005];
char str[N];
int dep[N];
int n;

void solve1() {
    stack<pair<int, int> > sx;
    ll res = 0;
    for (int i = 1; i <= n; i ++ ) {
        if (sx.empty()) {
            res += dep[0];
            sx.push({str[i], i});
            continue;
        }
        if (sx.top().first == str[i]) {
            dep[sx.size()] = 0;
            sx.pop();
            dep[sx.size()] ++;
            res += dep[sx.size()];
        } else {
            sx.push({str[i], i});
            continue;
        }
    }
    cout << res;
    return ;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    ll res = 0;
    cin >> n;
    cin >> (str + 1);
    if (n > 800) {
        solve1();
        return 0;
    }
    for (int i = 1; i < n; i ++ ) {
        if (str[i] == str[i + 1]) {
            f[i][i + 1] = 1;
            res ++;
        }
    }
    for (int len = 4; len <= n; len ++ ) {
        for (int l = 1; l + len - 1 <= n; l ++ ) {
            int r = l + len - 1;
            f[l][r] = (str[l] == str[r]) && f[l + 1][r - 1];
            for (int k = l + 1; k < r; k ++ ) {
                f[l][r] |= f[l][k] && f[k + 1][r];
                if (f[l][r]) {
                    break;
                }
            }
            res += f[l][r];
        }
    }
    cout << res << '\n';
    cout.flush();
    return 0;
}