#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;

int n, m, cnt[3015][30], lst[3015][30];
bitset<3015> ans;

struct node {
    string s;
    int id;
    bool operator < (const node &rhs) const {
        for (int i = 0; i < m; i++) {
            if (s[i] != rhs.s[i]) {
                return s[i] < rhs.s[i];
            }
        }
        return id < rhs.id;
    }
} str[3015];

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> str[i].s;
        str[i].id = i;
        for (int j = 0; j < m; j++) {
            cnt[i][str[i].s[j] - 'a']++;
        }
    }
    sort(str, str + n);
    // for (int i = 0; i < n; i++) {
    //     cout << str[i].s << ' ' << str[i].id << endl;
    //     for (int j = 0; j < 26; j++) {
    //         cout << (char)(j + 'a') << ' ' << cnt[i][j] << endl;
    //     }
    // }
    int pos;
    ans[str[0].id] = 1;
    for (int i = 1; i < n; i++) {
        ans[str[i].id] = 1;
        pos = 0;
        for (int j = 0; j < m; j++) {
            while (!cnt[str[i].id][pos] && pos < 26) {
                pos++;
            }
            // printf("%d ", pos);
            if (pos < str[0].s[j] - 'a') {
                break;
            }
            else if (pos > str[0].s[j] - 'a') {
                ans[str[i].id] = 0;
                break;
            }
            else {
                cnt[str[i].id][pos]--;
            }
        }
        // putchar('\n');
    }
    for  (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}