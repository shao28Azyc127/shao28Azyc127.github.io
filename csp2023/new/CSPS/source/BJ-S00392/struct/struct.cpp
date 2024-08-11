#include <bits/stdc++.h>
using namespace std;
struct str {
    string leixing;
    string name;
} a[105];
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    int tmp = 0;
    cin >> n;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            string s;int k;
            cin >> s >> k;
            for (int i = 1;i <= k;i++) {
                cin >> a[i].leixing >> a[i].name;
            }
            int size_struct = 0, change = 0;
            for (int i = 1;i <= k;i++) {
                if (a[i].leixing == "byte" && change == 0) change = 1;
                if (a[i].leixing == "short" && change < 2) change = 2;
                if (a[i].leixing == "int" && change < 4) change = 4;
                if (a[i].leixing == "long" && change < 8) change = 8;
            }
            size_struct = k * change;
            cout << size_struct << " " << change << endl;
        }
        if (op == 2) {
            string t,n;
            cin >> t >> n;
            cout << tmp << endl;
        }
    }
    return 0;
}