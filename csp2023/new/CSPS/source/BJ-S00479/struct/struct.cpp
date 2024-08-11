#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 2e6 + 5;

typedef long long ll;

map<string, int> stt;
int tsk[N];
string tskn[N];
map<string, int> cd;
int n, cnt = 0, nw = 0;

int find(int x) {
    int xs = lower_bound(tsk, tsk + cnt, x) - tsk;
    xs --;
    if (xs < 0 || xs >= cnt) {
        return -1;
    }
    if (x >= nw) {
        return -1; 
    }
    return xs;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cd["long"] = 8;
    cd["int"] = 4;
    cd["short"] = 2;
    cd["byte"] = 1;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) {
        int op;
        cin >> op;
        if (op == 2) {
            string a, b;
            cin >> a >> b;
            tskn[cnt ++] = b;
            tsk[cnt] = nw;
            stt[b] = nw;
            nw += cd[a];
        } else if (op == 3) {
            string a;
            cin >> a;
            cout << stt[a] << '\n';
        } else {
            ll x;
            cin >> x;
            auto xs = find(x);
            if (xs == -1) {
                cout << "ERR\n";
            } else {
                cout << tskn[xs] << "\n";
            }
        }
    }
    return 0;
}