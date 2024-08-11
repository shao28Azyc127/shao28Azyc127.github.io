#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdio>
#define ll long long
using namespace std;
struct var {
    string tp;
    string name;
    ll mem, dq, address;
} v[100005];
struct stru {
    string name;
    vector<int> elem;
    ll mem, dq;
} s[100005];
int vtot, stot;
ll address;
map<string, int> _stru, _var;
inline ll get_mem(string _tp) {
    if (_tp == "byte") return 1;
    else if (_tp == "short") return 2;
    else if (_tp == "int") return 4;
    else if (_tp == "long") return 8;
    else return s[_stru[_tp]].mem;
}
inline ll get_dq(string _tp) {
    if (_tp == "byte") return 1;
    else if (_tp == "short") return 2;
    else if (_tp == "int") return 4;
    else if (_tp == "long") return 8;
    else return s[_stru[_tp]].dq;
}
int main() {
	freopen("struct.in", "r", stdin);
	freopen("struct.out", "w", stdout);
    int n; cin >> n;
    while (n--) {
        int op; cin >> op;
        if (op == 1) {
            string str; int k, kk;
            cin >> str >> k;
            kk = k;
            s[++stot].name = str;
            _stru[str] = stot;
            ll nowdq = 0;
            while (k--) {
                string _tp, _name;
                cin >> _tp >> _name;
                nowdq = max(nowdq, get_dq(_tp));
                v[++vtot] = (var){_tp, _name, get_mem(_tp), get_dq(_tp), 0};
                _var[_name] = vtot;
                s[stot].elem.push_back(vtot);
            }
            s[stot].mem = nowdq * kk, s[stot].dq = nowdq;
            cout << s[stot].mem << ' ' << s[stot].dq << '\n';
        } else if (op == 2) {
            string _tp; string _name;
            cin >> _tp >> _name;
            v[++vtot] = (var){_tp, _name, get_mem(_tp), get_dq(_tp), address};
            _var[_name] = vtot;
            cout << address << '\n';
            address += v[vtot].mem;
        } else if (op == 3) {
            string str; cin >> str;
            int nowid = _var[str];
            cout << v[nowid].address << '\n';
        } else if (op == 4) {
            ll nowadd; cin >> nowadd;
            bool outed = false;
            for (int i = 1; i <= vtot; i++) {
                if (v[i].address > nowadd) {
                    cout << v[i - 1].name << '\n';
                    outed = true;
                    break;
                }
            }
            if (!outed) cout << v[vtot].name << '\n';
        }
    }
	return 0;
}

