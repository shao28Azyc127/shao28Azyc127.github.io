#include <cstdio>
#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
LL n, op;
vector<LL> s, a, b, t;
vector<string> m;
vector<vector<LL>> tS, oS;
vector<unordered_map<string, LL>> cS;
vector<vector<string>> pS;
unordered_map<string, int> d, e;
int main() {
    //freopen("struct3.in", "r", stdin);
    //freopen("struct.out", "w", stdout);
    s.push_back(1);
    s.push_back(2);
    s.push_back(4);
    s.push_back(8);
    a.push_back(1);
    a.push_back(2);
    a.push_back(4);
    a.push_back(8);
    d["byte"] = 0;
    d["short"] = 1;
    d["int"] = 2;
    d["long"] = 3;
    tS.push_back(vector<LL>(0));
    oS.push_back(vector<LL>(0));
    tS.push_back(vector<LL>(0));
    oS.push_back(vector<LL>(0));
    tS.push_back(vector<LL>(0));
    oS.push_back(vector<LL>(0));
    tS.push_back(vector<LL>(0));
    oS.push_back(vector<LL>(0));
    m.push_back("byte");
    m.push_back("short");
    m.push_back("int");
    m.push_back("long");
    scanf("%lld", &n);
    for (int i = 0; i < n; i ++ ) {
        scanf("%lld", &op);
        if (op == 1) {
            string sS1;
            LL kS1;
            cin >> sS1;
            scanf("%lld", &kS1);
            s.push_back(0);
            a.push_back(0);
            m.push_back(sS1);
            tS.push_back(vector<LL>(0));
            cS.push_back(unordered_map<string, LL>(0));
            oS.push_back(vector<LL>(0));
            pS.push_back(vector<string>(0));
            for (int j = 0; j < kS1; j ++ ) {
                string tS1, nS1;
                cin >> tS1 >> nS1;
                a[a.size() - 1] = max(a[a.size() - 1], a[d[tS1]]);
                tS[tS.size() - 1].push_back(d[tS1]);
                cS[cS.size() - 1][nS1] = j;
                oS[oS.size() - 1].push_back(j == 0 ? 0 : ((oS[oS.size() - 1][j - 1] + s[tS[tS.size() - 1][j - 1]] - 1) / a[tS[tS.size() - 1][j]] + 1) * a[tS[tS.size() - 1][j]]);
                pS[pS.size() - 1].push_back(nS1);
            }

            s[s.size() - 1] = ((oS[oS.size() - 1][oS[oS.size() - 1].size() - 1] + s[tS[tS.size() - 1][tS[tS.size() - 1].size() - 1]] - 1) / a[a.size() - 1] + 1) * a[a.size() - 1];
            d[sS1] = s.size() - 1;
        }

        if (op == 2) {
            string tS2, nS2;
            cin >> tS2 >> nS2;
            b.push_back(b.size() == 0 ? 0 : ((b[b.size() - 1] + s[t[t.size() - 1]] - 1) / a[d[tS2]] + 1) * a[d[tS2]]);
            t.push_back(d[tS2]);
            e[nS2] = t.size() - 1;
            printf("%lld\n", b[b.size() - 1]);
        }

        if (op == 3) {
            string sS3;
            cin >> sS3;
            if (sS3.find('.') == -1) {
                printf("%lld\n", b[e[sS3]]);
            } else {
                string p1S3 = "", p2S3 = "";
                int j = 0;
                for (; j < sS3.size(); j ++ ) {
                    if (sS3[j] == '.') break;
                    p1S3 = p1S3 + sS3[j];
                }

                j++;
                for (; j < sS3.size(); j ++ ) {
                    p2S3 = p2S3 = sS3[j];
                }

                printf("%lld\n", b[e[p1S3]] + oS[t[e[p1S3]]][cS[t[e[p1S3]]][p2S3]]);
            }
        }

        if (op == 4) {
            LL addrS4;
            scanf("%lld", &addrS4);
            bool okS4 = true;
            for (int j = 0; j < b.size() && okS4; j ++ ) {
                if (b[j] <= addrS4 && b[j] + s[t[j]] >= addrS4) {
                    if (t[j] < 4) {
                        cout << m[t[j]] << endl;
                        okS4 = false;
                    }

                    for (int k = 0; k < oS[t[j]].size() && okS4; k ++ ) {
                        if (b[j] + oS[t[j]][k] <= addrS4 && b[j] + oS[t[j]][k] + s[tS[t[j]][k]] >= addrS4) {
                            cout << m[t[j]] << "." << pS[t[j]][k] << endl;
                            okS4 = false;
                        }
                    }
                }
            }

            if (okS4) printf("ERR\n");
        }
    }

    return 0;
}
