#include <bits/stdc++.h>
using namespace std;
int n, nc, yc, abe, adList[80005], tempList[80005], newList[80005];
map<string, int> dic, adr, num, typos;
struct node {
    string s;
    int k;
    string t[105], n[105];
    int dq;
} nds[105];
struct yuan {
    string t, n;
    int l, r;
} yua[105];
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    dic["byte"] = 1;
    dic["short"] = 2;
    dic["int"] = 4;
    dic["long"] = 8;
    cin >> n;
    int op;
    while (n--) {
        cin >> op;
        if (op == 1) {
            ++nc;
            cin >> nds[nc].s >> nds[nc].k;
            int dq = 0, sz = 0;
            for (int i = 1; i <= nds[nc].k; ++i) {
                cin >> nds[nc].t[i] >> nds[nc].n[i];
                dq = max(dq, dic[nds[nc].t[i]]);
            }
            nds[nc].dq = dq;
            sz = nds[nc].k * nds[nc].dq;
            cout << sz << " " << dq << "\n";
            dic[nds[nc].s] = sz;
            typos[nds[nc].s] = nc;
        } else if (op == 2) {
            ++yc;
            cin >> yua[yc].t >> yua[yc].n;
            cout << abe + 1 << "\n";
            yua[yc].l = abe + 1;
            abe += dic[yua[yc].t];
            yua[yc].r = abe;
            adr[yua[yc].n] = yua[yc].l;
            for (int i = yua[yc].l; i <= yua[yc].r; ++i) adList[i] = yua[yc].l;
            for (int i = yua[yc].l; i <= yua[yc].r; ++i) newList[i] = yc;
            num[yua[yc].n] = yc;
        } else if (op == 3) {
            string s;
            cin >> s;
            bool flag = true;
            for (int i = 0; i < s.length(); ++i) if (s[i] == '.') {
                flag = false;
                break;
            }
            if (flag == true) cout << adr[s] << "\n";
            else {
                string temp = "", temp2 = "";
                for (int i = 0; i < s.length(); ++i) {
                    if (s[i] == '.') {
                        int l = yua[num[temp]].l;
                        memset(tempList, 0, sizeof(tempList));
                        int rr = l - 1;
                        for (int j = 1; j <= nds[1].k; ++j) {
                            for (int k = rr; k <= nds[1].dq; ++k) {
                                tempList[k] = rr;
                            }
                            rr += nds[1].dq;
                        }
                        for (int j = i + 1; j < s.length(); ++j) {
                            temp2 += s[j];
                        }
                        for (int j = 1; j <= nds[1].k; ++j) {
                            if (nds[1].n[j] == temp2) {
                                cout << tempList[j * nds[1].dq] << "\n";
                            }
                        }
                        break;
                    }
                    temp += s[i];
                }
            }
        } else {
            long long x;
            cin >> x;
            if (x > 80000) cout << "ERR" << "\n";
            else if (newList[x] == 0) cout << "ERR" << "\n";
            else {
                if (yua[newList[x]].t != nds[1].s) {
                    cout << yua[newList[x]].n << "\n";
                } else {
                    cout << nds[1].s << ".";
                    for (int i = 1; i <= yc; ++i) {
                        if (yua[i].t == nds[1].s) {
                            if ((x - yua[i].l) % nds[1].dq == 0) {
                                cout << nds[1].n[(x - yua[i].l) / nds[1].dq] << "\n";
                            } else {
                                cout << nds[1].n[(x - yua[i].l) / nds[1].dq + 1] << "\n";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}