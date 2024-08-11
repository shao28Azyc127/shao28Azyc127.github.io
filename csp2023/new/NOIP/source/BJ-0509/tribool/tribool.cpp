#include <bits/stdc++.h>
using namespace std;
int c, t, n, m, tmp1, tmp2, ans;
int b[100005];
int e[15][15];
char ch, a[100005], d[100005];
bool flag[100005];
bool f;
string s;
char inv(char x) {
    if (x == 'T') x = 'F';
    else if (x == 'F') x = 'T';
    else x == 'U';
    return x;
}
void adde(int id) {
    if (b[id] < 2) {
        b[id]++;
        return;
    } else {
        void(id++);
    }
    return;
}
bool check() {
    for (int i = 1; i <= n; i++) {
        if (b[i] != 2) return false;
    }
    return true;
}
void dfs() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) a[i] = 'T';
        else if (b[i] == 1) a[i] = 'F';
        else a[i] = 'U';
        d[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        if (e[i][1] == 1) {
            if (e[i][4] == 1) a[e[i][2]] = 'T';
            else if (e[i][4] == 2) a[e[i][2]] = 'F';
            else a[e[i][2]] = 'U';
        } else if (e[i][1] == 2) {
            a[e[i][2]] = a[e[i][3]];
        } else {
            a[e[i][2]] = inv(a[e[i][3]]);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (d[i] != a[i]) {
            f = 1;
            break;
        }
        if (d[i] == 'U') cnt++;
    }
    if (f == 0) ans = min(ans, cnt);
    if (check()) return;
    adde(1);
    dfs();
}
int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        if (c == 1 || c == 2) {
            for (int i = 0; i < m; i++) {
                cin >> s;
                if (s[0] == 'T' || s[0] == 'F' || s[0] == 'U') {
                    if (s[0] == 'T') e[i][4] = 1;
                    else if (s[0] == 'F') e[i][4] = 2;
                    else e[i][4] = 3;
                    e[i][1] = 1;
                    scanf("%d", &tmp1);
                    e[i][2] = tmp1;
                    a[tmp1] = s[0];
                    //printf("%c", a[tmp1]);
                    //flag[tmp1] = 1;
                } else if (s[0] == '+') {
                    e[i][1] = 2;
                    scanf("%d%d", &tmp1, &tmp2);
                    e[i][2] = tmp1;
                    e[i][3] = tmp2;
                    //printf("%c%c", a[tmp1], a[tmp2]);
                    a[tmp1] = a[tmp2];
                    //printf("%c%c", a[tmp1], a[tmp2]);
                    //if (a[tmp2] == 'U') flag[tmp1] = 1;
                } else {
                    e[i][1] = 3;
                    scanf("%d%d", &tmp1, &tmp2);
                    e[i][2] = tmp1;
                    e[i][3] = tmp2;
                    a[tmp1] = inv(a[tmp2]);
                }
            }
            dfs();
            printf("%d\n", ans);
        } else if (c == 3 || c == 4) {
             for (int i = 0; i < m; i++) {
                cin >> s;
                if (s[0] == 'T' || s[0] == 'F' || s[0] == 'U') {
                    scanf("%d", &tmp1);
                    a[tmp1] = s[0];
                    //printf("%c", a[tmp1]);
                    //flag[tmp1] = 1;
                } else if (s[0] == '+') {
                    scanf("%d%d", &tmp1, &tmp2);
                    //printf("%c%c", a[tmp1], a[tmp2]);
                    a[tmp1] = a[tmp2];
                    //printf("%c%c", a[tmp1], a[tmp2]);
                    //if (a[tmp2] == 'U') flag[tmp1] = 1;
                } else {
                    scanf("%d%d", &tmp1, &tmp2);
                    a[tmp1] = inv(a[tmp2]);
                }
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] == 'U') ans++;
            }
            printf("%d\n", ans);
        } else if (c == 5 || c == 6) {
            for (int i = 0; i < m; i++) {
                cin >> s;
                if (s[0] == 'T' || s[0] == 'F' || s[0] == 'U') {
                    scanf("%d", &tmp1);
                    a[tmp1] = s[0];
                    //printf("%c", a[tmp1]);
                    //flag[tmp1] = 1;
                } else if (s[0] == '+') {
                    scanf("%d%d", &tmp1, &tmp2);
                    //printf("%c%c", a[tmp1], a[tmp2]);
                    a[tmp1] = a[tmp2];
                    //printf("%c%c", a[tmp1], a[tmp2]);
                    //if (a[tmp2] == 'U') flag[tmp1] = 1;
                } else {
                    scanf("%d%d", &tmp1, &tmp2);
                    a[tmp1] = inv(a[tmp2]);
                }
            }
            for (int i = 1; i <= n; i++) {
                if (a[i] == 'U') ans++;
                //printf("%c", a[i]);
                //printf("q");
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
