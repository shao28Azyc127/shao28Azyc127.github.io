#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

const int N = 1000;
int T, cnt;
ll now, pos[N];
string che[N];
struct Val {
    int onel, sz;
};
struct NAME {
    string val;
    int st;
};
map<string, Val> mp1;
map<string, NAME> mp2;

void pretreatment() {
    mp1["byte"] = {1, 1};
    mp1["short"] = {2, 2};
    mp1["int"] = {4, 4};
    mp1["long"] = {8, 8};
}

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    pretreatment();
    cin >> T;
    while (T--) {
        int op; cin >> op;
        if (op == 1) return 0;
        else if (op == 2) {
            string t, n; cin >> t >> n;
            if (now == 0) mp2[n].st = 0;
            else mp2[n].st = (((now - 1) / mp1[t].onel) + 1) * mp1[t].onel;
            mp2[n].val = t;
            now = mp2[n].st + mp1[t].onel;
            pos[++cnt] = mp2[n].st;
            che[cnt] = n;
        } else if (op == 3) {
            string s; cin >> s;
            cout << mp2[s].st << endl;
        } else {
            int addr;  cin >> addr;
            int id = upper_bound(pos + 1, pos + cnt + 1, addr) - pos - 1;
            if (addr < pos[id] + mp1[mp2[che[id]].val].onel) {
                cout << mp2[che[id]].st << endl;
            } else {
                cout << "ERR" << endl
            }
        }
    }
    return 0;
}
