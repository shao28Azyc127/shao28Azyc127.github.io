#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int MAXN = 2e6 + 5;

typedef long long ll;

int l, n, d[MAXN << 1];
ll ans;
char s[MAXN], t[MAXN << 1];
vector<int> ans2;

namespace Force {
    bool check(string s) {
        while (!s.empty()) {
            string news;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == s[i + 1]) ++i;
                else news += s[i];
            }
            if (news.size() == s.size()) return false;
            s = news;
        }
        return true;
    }
    void run(int n) {
        string s;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            for (int j = 2; i + j - 1 < n; ++j) {
                if (check(s.substr(i, j))) ++ans;
            }
        }
        cout << ans << endl;
    }
}

int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d", &l);
    if (l <= 800) {
        Force::run(l);
        return 0;
    }
    scanf("%s", s + 1);
    t[++n] = '&';
    t[++n] = '#';
    for (int i = 1; i <= l; ++i) {
        t[++n] = s[i];
        t[++n] = '#';
    }
    t[++n] = '@';
    int p = 0, r = 0;
    for (int i = 1; i <= n; ++i) {
        if (i < r) d[i] = min(d[2 * p - i], r - i);
        else d[i] = 1;
        while (t[i - d[i]] == t[i + d[i]]) ++d[i];
        if (i + d[i] - 1 > r) {
            r = i + d[i] - 1;
            p = i;
        }
    }
    int la = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (t[i] == '#' && d[i] > 1) {
            int p = i - d[i] + 1;
            if (la && p != la) {
                ans2.push_back(cnt);
                cnt = 0;
            }
            la = i + d[i] - 1;
            ans += d[i] / 2;
            //printf("%d ", i);
            //printf("prev=%d next=%d ", i - d[i] + 1, i + d[i] - 1);
            ++cnt;
        }
    }
    //printf("\n");
    if (cnt) ans2.push_back(cnt);
    // for (int i : ans2) {
    //     printf("%d ", i);
    // }
    // printf("\n");
    for (int i : ans2) ans += 1ll * i * (i - 1) / 2;
    //ans += 1ll * cnt * (cnt - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}