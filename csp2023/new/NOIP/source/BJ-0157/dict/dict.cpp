#include <algorithm>
#include <iostream>
#include <string>
#include <ctime>
#include <cstring>
using namespace std;

int n, m;
string s[3005];

int cnt[26];
void counting_sort(string &s) {
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < m; i++)
        cnt[s[i] - 'a']++;
    int sz = 0;
    for (int i = 0; i < 26; i++)
        while (cnt[i]--)
            s[sz++] = i + 'a';
}


bool cmp(string &x, string &y) {
    for (int i = 0; i < m; i++) {
        char xch = x[i], ych = y[m - i - 1];
        if (xch < ych)
            return true;
        if (xch > ych)
            return false;
    }
    return false;
}

bool cmp_all(int i) {
    for (int j = 1; j <= n; j++)
        if (i != j && !cmp(s[i], s[j]))
            return false;
    return true;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        counting_sort(s[i]);
    }

    for (int i = 1; i <= n; i++)
        printf("%d", cmp_all(i));
    return 0;
}
