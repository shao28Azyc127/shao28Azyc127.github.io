#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
const int N = 105;
const int S = 80005;
int n;
string ne[S];
map<string, int> sz;
map<string, int> tid;
struct typ {
    string nam;
    int cf;
    int siz;
    int dq;
    int tp[N];
    string na[N];
} str[N];
int ptr = 0;
void pushv(int ps, string nme) {
    while(true) {
        if(ptr % ps == 0) {
            break;
        }
        ne[ptr] = "ERR";
        ptr++;
    }
    for(int j = 0; j < ps; j++) {
        ne[ptr + j] = nme;
    }
    ptr += ps;
}
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    cin >> n;
    int op;
    sz["byte"] = 1;
    sz["short"] = 2;
    sz["int"] = 4;
    sz["long"] = 8;
    string s, t;
    for(int ti = 1; ti <= n; ti++) {
        cin >> op;
        if(op == 1) {
            cin >> str[ti].nam >> str[ti].cf;
            for(int i = 1; i <= str[ti].cf; i++) {
                cin >> str[ti].na[i];
                str[ti].tp[i] = sz[str[ti].na[i]];
                cin >> str[ti].na[i];
                while(str[ti].siz % str[ti].tp[i] != 0) {
                    str[ti].siz++;
                }
                str[ti].siz += str[ti].tp[i];
                str[ti].dq = max(str[ti].dq, str[ti].tp[i]);
            }
            tid[str[ti].nam] = ti;
            cout << str[ti].siz << " " << str[ti].dq << endl;
        } else if(op == 2) {
            cin >> s >> t;
            if(sz.find(s) != sz.end()) {
                pushv(sz[s], t);
                cout << ptr - sz[s] << endl;
                continue;
            }
            int td = tid[s];
            while(true) {
                if(ptr % str[td].dq == 0) {
                    break;
                }
                ne[ptr] = "ERR";
                ptr++;
            }
            cout << ptr << endl;
            for(int i = 1; i <= str[td].cf; i++) {
                pushv(str[td].tp[i], t + "." + str[td].na[i]);
            }
        } else if(op == 3) {
            cin >> s;
            bool ok = false;
            for(int i = 0; i < ptr; i++) {
                if(s.size() > ne[i].size()) {
                    continue;
                }
                ok = true;
                for(int j = 0; j < s.size(); j++) {
                    if(s[j] != ne[i][j]) {
                        ok = false;
                        break;
                    }
                }
                if(ok) {
                    cout << i << endl;
                    break;
                }
            }
        } else if(op == 4) {
            int tp;
            cin >> tp;
            if(tp >= ptr) {
                cout << "ERR" << endl;
                continue;
            }
            cout << ne[tp] << endl;
        } else {
            printf("dthkxy AK IOI\n");
        }
    }
    return 0;
}
/*
14
1 a 4
short aa
int ab
byte ac
long ad
2 a aa
2 a xx
2 a cc
4 13
4 2
4 1
4 8
4 28
3 xx.ab
3 aa.ad
4 103
2 int qwq
4 72

24 8
0
24
48
ERR
ERR
aa.aa
aa.ac
xx.ab
28
16
ERR
72
qwq
*/
