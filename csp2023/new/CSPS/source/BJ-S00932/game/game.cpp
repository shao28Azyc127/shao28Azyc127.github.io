#include <bits/stdc++.h>
using namespace std;

const int N = 2e6 + 10;
int n, ans = 0, a[N], tmp;
string s;
vector <int> f[N];
map <vector <int>, int> mp;

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        a[i + 1] = int(s[i]);
    }
    f[1].push_back(a[1]);
    mp[f[1]]++;
    for (int i = 2; i <= n; i++) {
        if (f[i - 1].size() != 0) {
            if (f[i - 1][f[i - 1].size() - 1] == a[i]) {
                f[i] = f[i - 1];
                f[i].pop_back();
            }
            else {
                f[i] = f[i - 1];
                f[i].push_back(a[i]);
            }
        }
        else {
            f[i].push_back(a[i]);
        }
        if (f[i].size() == 0) {
            ans += tmp;
            tmp++;
            ans++;
        }
        else {
            ans += mp[f[i]];
            mp[f[i]]++;
        }
    }
    printf("%d", ans);
    return 0;
}
