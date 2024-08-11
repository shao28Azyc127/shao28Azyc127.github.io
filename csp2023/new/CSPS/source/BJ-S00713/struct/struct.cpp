#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N = 8010, M = 131;
int n;
map<string, int> siz;
struct member{
    string name;
    int l, r;
};
int p;
vector<member> mem;
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    siz["byte"] = 1;
    siz["short"] = 2;
    siz["int"] = 4;
    siz["long"] = 8;
    cin >> n;
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            string type;
            cin >> type;
            int k;
            cin >> k;
            int maxm = 0;
            int sum = 0;
            for (int i = 1; i <= k; i++) {
                string t, name;
                cin >> t >> name;
                maxm = max(maxm, siz[t]);
            }
            siz[type] = maxm * k;
        }
        if (op == 2) {
            string t, name;
            cin >> t >> name;
            mem.push_back({name, p, p + siz[t] - 1});
            p += siz[t];
        }
        if (op == 3) {
            string s;
            cin >> s;
            for (int i = 0; i < mem.size(); i++) {
                if (mem[i].name == s) {
                    cout << mem[i].l << endl;
                    break;
                }
            }
        }
        if (op == 4) {
            int addr;
            cin >> addr;
            for (int i = 0; i < mem.size(); i++) {
                if (mem[i].l <= addr && mem[i].r >= addr) {
                    cout << mem[i].name << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
