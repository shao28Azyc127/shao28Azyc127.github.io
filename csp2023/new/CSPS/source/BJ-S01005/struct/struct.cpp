#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r;
};

map<int, string> m1;
map<string, node> m2;

int n, op, x, flag, lx;
string s, s1;

int main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    while (n--) {
        cin >> op;
        if (op % 2 == 0) {
            if (op == 4) {
                cin >> x;
                if (m1[x].size() == 0) {
                    cout << "ERR" << endl;
                }else {
                    cout << m1[x] << endl;
                }
            }else {
                cin >> s;
                if (s.size() == 4) {
                    if (s == "byte") {
                        x = 1;
                        m1[++flag] = "byte";
                        cin >> s;
                        m2[s] = node{flag, flag};
                    }else {
                        x = 8;
                        for (int i = 1; i <= 8; i++) {
                            m1[++flag] = "long";
                        }
                        cin >> s;
                        m2[s].l = flag - 7;
                        flag = (flag + 7) / 8 * 8;
                        m2[s].r = flag;
                    }
                }else {
                    if (s == "int") {
                        x = 4;
                        for (int i = 1; i <= 4; i++) {
                            m1[++flag] = "int";
                        }
                        cin >> s;
                        m2[s].l = flag - 3;
                        flag = (flag + 3) / 4 * 4;
                        m2[s].r = flag;
                    }else {
                        x = 2;
                        m1[++flag] = "short";
                        m1[++flag] = "short";
                        cin >> s;
                        m2[s].l = flag - 1;
                        flag = (flag + 1) / 2 * 2;
                        m2[s].r = flag;
                    }
                }
                cout << m2[s].l << " " << m2[s].r << endl;
            }
        }else {
            if (op == 3) {
                cin >> s;
                cout << m2[s].l << " " << m2[s].r << endl;
            }else {
                cin >> x >> s1;
                int i;
                x = lx = 0;
                for (i = x; i >= 1; i--) {
                    cin >> s;
                    if (s.size() == 4) {
                        if (s == "byte") {
                            lx = max(lx, 1);
                            x += 1;
                            m1[++flag] = "byte";
                            cin >> s;
                            m2[s1 + '.' + s] = node{flag - 7, flag};
                        }else {
                            lx = max(lx, 8);
                            x += 8;
                            for (int i = 1; i <= 8; i++) {
                                m1[++flag] = "long";
                            }
                            cin >> s;
                            m2[s1 + '.' + s] = node{flag - 7, flag};
                        }
                    }else {
                        if (s == "int") {
                            lx = max(lx, 4);
                            x += 4;
                            for (int i = 1; i <= 4; i++) {
                                m1[++flag] = "int";
                            }
                            cin >> s;
                            m2[s1 + '.' + s] = node{flag - 3, flag};
                        }else {
                            lx = max(lx, 2);
                            x += 2;
                            m1[++flag] = "short";
                            m1[++flag] = "short";
                            cin >> s;
                            m2[s1 + '.' + s] = node{flag - 1, flag};
                        }
                    }
                }
                flag += (x + lx - 1) / lx * lx - x;
                cout << (x + lx - 1) / lx * lx << " " << s;
            }
        }
    }
	return 0;
}
