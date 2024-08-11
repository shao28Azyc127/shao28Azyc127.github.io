#include <bits/stdc++.h>
using namespace std;
int m;
string a[10001];
map<string, int>head;
int adr = 0;
int main() {
    freopen("struct.in", "r", stdin);
   freopen("struct.out", "w", stdout);
    cin >> m;
    while (m--) {
        int op;
        cin >> op;
        if (op == 2) {
            string t, n;
            cin >> t >> n;
            if (t=="byte") {
                a[adr] = n;
                head[n] = adr;
                adr += 1;
            } else if(t == "short") {
                if (adr % 2 != 0) {
                    adr  += 1;
                }
                head[n] = adr;
                for (int i = adr; i < adr + 2; i++) {
                    a[i] = n;
                }
                adr += 2;
            }else if(t == "int") {
                    while (adr% 4) {
                        adr ++;
                    }
                    head[n] = adr;
                for (int i = adr; i < adr + 4; i++) {
                    a[i] = n;
                }
                adr += 4;
            } else if (t == "long") {
                    while (adr% 8) {
                        adr ++;
                    }
                    head[n] = adr;
                for (int i = adr; i < adr + 8; i++) {
                    a[i] = n;
                }
                adr += 8;
            }
            cout << head[n] << endl;
        } else if (op == 3) {
            string n;
            cout << head[n] << endl;
        } else if (op == 4) {
            int b;
            cin >>b;
            if(a[b] == "") cout << "ERR" << endl;
            else {
                cout << a[b] << endl;
            }
        }
    }
    return 0;
}