#include <bits/stdc++.h>
using namespace std;
int w = 0, op = 0, cur = 0, cur1 = 0, k = 0;
struct add {
    int ads = 0, ade = 0;
    string name = "";
}addre[101];
struct str {
    int siz = 0;
    string name = "", t[101], n[101];
}a[101];
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> w;
    for (int i = 1; i <= w; ++i) {
        cin >> op;
        if (op == 1) {
            ++cur;
            int maxn = 0;
            cin >> a[cur].name >> k;
            for (int i = 1; i <= k; ++i) cin >> a[cur].t[i] >> a[cur].n[i];
            for (int i = 0; i <= k; ++i)
                if (a[cur].t[i] == "bool") ++a[cur].siz, maxn = max(1, maxn);
                else if (a[cur].t[i] == "short") a[cur].siz += 2, maxn = max(2, maxn);
                else if (a[cur].t[i] == "int") a[cur].siz += 4, maxn = max(4, maxn);
                else a[cur].siz += 8, maxn = max(8, maxn);
            a[cur].siz = ceil(1.0 * a[cur].siz / maxn) * maxn;
        }
        else if (op == 2) {
            string t1 = 0, n1 = 0;
            cin >> t1 >> n1;
            for (int i = 1; i <= cur; ++i)
                if (a[i].name == t1) {
                    addre[++cur1].name = n1, addre[cur1].ads = addre[cur1 - 1].ade + 1, addre[cur1].ade = addre[cur1].ads + a[i].siz;
                    break;
                }
        }
        else if (op == 3) {
            string s = "";
            cin >> s;
            for (int i = 1; i <= cur1; ++i)
            if (addre[i].name == s) {
                cout << addre[i].ads << endl;
                break;
            }
        }
        else {
            int addr = 0;
            cin >> addr;
            for (int i = 1; i <= cur1; ++i)
                if (addre[i].ads <= addr && addre[i].ade) {
                    cout << addre[i].name << endl;
                    break;
                }
        }
    }
    return 0;
}
