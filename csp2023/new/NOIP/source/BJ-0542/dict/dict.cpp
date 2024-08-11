#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
using namespace std;
const int N = 3010;
char t[N];
int n, m;
set<int> st;
struct node {
    string s;
    int code;
} s1[N], s2[N];
bool cmp(node a, node b) {
    return a.s < b.s;
}
int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            t[j] = s[j];
        }

        sort(t, t + m);
        s2[i].s = t;
        reverse(t, t + m);
        s1[i].s = t;
        s1[i].code = i;
        s2[i].code = i;
    }
    /*
    for (int i = 1; i <= n; i++) {
        cout << "s1 i :" << s1[i] << endl;
        cout << "s2 i :" << s2[i] << endl;
    }
    */
    sort(s1 + 1, s1 + n, cmp);
    for (int i = 1; i <= n; i++) {
        if (s2[i].code == s1[1].code || s2[i].s < s1[1].s) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
