#include <bits/stdc++.h>
#define write(n) for (int i = 0; i < n; i++) addr[pos++] = name;
#define endl '\n'
using namespace std;
typedef long long ll;
const int maxn = 110;
int n, op;
ll pos;
string type, name, addr[810];
inline bool check(string a, string b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) return false;
    }
    return true;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
                    
    while(n--) {
        cin >> op;
        if (op == 2) {
            cin >> type >> name;
            if (type[0] == 'b') addr[pos++] = name;
            if (type[0] == 's') {
                if(pos % 2) pos = (pos + 1) / 2 * 2;
                cout << pos << endl;
                write(2);
            }
            if (type[0] == 'i'){
                if (pos % 4) pos = (pos + 3) / 4 * 4;
                cout << pos << endl;
                write(2);
            }
            if (type[0] == 'l') {
                if (pos % 8) pos = (pos + 7) / 8 * 8;
                cout << pos << endl;
                write(8);
            }
        }
        if (op == 3) {
            cin >> name;
            for (int i = 0; i < 800; i++) {
                if (check(addr[i], name)) {
                    cout << i << endl;
                    break;
                }
            }
        }
        if (op == 4) {
            int address;
            cin >> address;
            cout << addr[address] << endl;
        }
    }
    return 0;
}