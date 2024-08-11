#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
int n, m, flag[30];
string s1[N];
struct node {
    int id;
    string s;
} a[N];
bool operator < (const node &x, const node &y) {
    return x.s < y.s;
}
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        memset(flag, 0, sizeof(flag));
        cin >> s1[i];
        a[i].id = i;
        for (int j = 0; j < s1[i].length(); j++) {
            flag[s1[i][j] - 'a']++;
        }
        string s = "";
        for (int j = 25; ~j; j--) {
            for (int k = 1; k <= flag[j]; k++) {
                s += char(j + 'a');
            }
        }
        a[i].s = s;
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        memset(flag, 0, sizeof(flag));
         for (int j = 0; j < s1[i].length(); j++) {
            flag[s1[i][j] - 'a']++;
        }
        string s = "";
        for (int j = 0; j <= 25; j++) {
            for (int k = 1; k <= flag[j]; k++) {
                s += char(j + 'a');
            }
        }
        if (i == a[1].id) {
            if (s < a[2].s) printf("1");
            else printf("0");
        }
        else {
            if (s < a[1].s) printf("1");
            else printf("0");
        }
    }
    return 0;
}