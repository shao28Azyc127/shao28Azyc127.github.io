#include<bits/stdc++.h>
using namespace std;

const int NR = 3000;

int n, m, pn;
bool ans[NR + 5];

struct S {
    bool tp;
    int id;
    string s;
} p[NR * 2 + 5];

bool cmp(S x, S y) {
    return x.s < y.s || (x.s == y.s && x.tp < y.tp);
}

bool cmp1(char x, char y) {
    return x < y;
}

bool cmp2(char x, char y) {
    return x > y;
}

int main() {
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        sort(str.begin(), str.end(), cmp1);
        pn++;
        p[pn].tp = 0;
        p[pn].id = i;
        p[pn].s = str;
        sort(str.begin(), str.end(), cmp2);
        pn++;
        p[pn].tp = 1;
        p[pn].id = i;
        p[pn].s = str;
    }
    sort(p + 1, p + pn + 1, cmp);
    int cnt = 0;
    for(int i = pn; i >= 1; i--) {
        if(p[i].tp == 1) {
            cnt++;
        }
        else if(cnt == n) {
            ans[p[i].id] = 1;
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}