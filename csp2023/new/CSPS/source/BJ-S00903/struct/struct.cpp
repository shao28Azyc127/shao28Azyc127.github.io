#include<iostream>
#include<map>
#include<vector>
using namespace std;
struct str {
    long long occ;//occupy
    int lg2aln;//align
    int cnt;
    bool basic;
    //the first string is always name of variable, and the latter is for type.
    map<string, pair<string, long long> > name2tppos;
    long long vp[105];
    string vn[105];
    str() : occ(0), lg2aln(0), basic(false), cnt(0), name2tppos() {}
    str(long long occ, int lg2aln, bool basic) : occ(occ), lg2aln(lg2aln), basic(basic), name2tppos() {}
};
map<string, str> tps;
struct var {
    long long pos;
    string tpnm;
};
map<string, var> vs;
long long vp[105];
string vn[105];
long long tot = 0;
int cnt = 0;
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    tps.insert(make_pair("byte", str(1ll, 0, true)));
    tps.insert(make_pair("short", str(2ll, 1, true)));
    tps.insert(make_pair("int", str(4ll, 2, true)));
    tps.insert(make_pair("long", str(8ll, 3, true)));
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            string s;
            int k;
            cin >> s >> k;
            str tmp;
            for (int i = 1; i <= k; ++i) {
                string t, n;
                long long pos;
                cin >> t >> n;
                str &ctp = tps[t];
                if (ctp.lg2aln > tmp.lg2aln) tmp.lg2aln = ctp.lg2aln;
                pos = ((((tmp.occ-1) << 1) >> (ctp.lg2aln + 1)) + 1) << ctp.lg2aln;
                tmp.occ = pos + ctp.occ;
                tmp.name2tppos.insert(make_pair(n, make_pair(t, pos)));
                tmp.vp[++tmp.cnt] = pos;
                tmp.vn[tmp.cnt] = n;
            }
            tmp.occ = ((((tmp.occ-1) << 1) >> (tmp.lg2aln + 1)) + 1) << tmp.lg2aln;
            tps.insert(make_pair(s, tmp));
            cout << tmp.occ << " " << ((1 << (tmp.lg2aln + 1)) >> 1) << '\n';
        } else if (op == 2) {
            string t, n;
            cin >> t >> n;
            str &ctp = tps[t];
            var tmp;
            tot = tmp.pos = ((((tot-1) << 1) >> (ctp.lg2aln + 1)) + 1) << ctp.lg2aln;
            tmp.tpnm = t;
            tot += ctp.occ;
            vs.insert(make_pair(n, tmp));
            vp[++cnt] = tmp.pos;
            vn[cnt] = n;
            cout << tmp.pos << '\n';
        } else if (op == 3) {
            string s;
            cin >> s;
            int spos = 0;
            long long pos = 0;
            string ss = s.substr(0, spos = s.find('.'));
            ++spos;
            var curv = vs[ss];
            pos = curv.pos;
            auto it = tps.find(curv.tpnm);
            while (spos) {
                int nfd = s.find('.', spos);
                //cout << s << endl;
                //cout << spos << " " << pos << " " << nfd << '\n';
                string ss = s.substr(spos, nfd - spos);
                spos = nfd;
                ++spos;
                auto q = it->second.name2tppos[ss];
                pos += q.second;
                it = tps.find(q.first);
            }
            cout << pos << '\n';
        } else if (op == 4) {
            long long pos;
            string s;
            cin >> pos;
            int i = 1;
            for (; i <= cnt; ++i) {
                if (vp[i] >= pos) {
                    break;
                }
            }
            --i;
            //cout <<i;
            pos -= vp[i];
            auto it = tps.find(vs[s = vn[i]].tpnm);
            bool err = false;
            if (pos >= it->second.occ) puts("ERR"), err = true;
            else {
                while (pos) {
                    //cout << it->second.occ << " ";
                    if (it->second.basic) {
                        if (pos < it->second.occ) break;
                        puts("ERR");
                        err = true;
                        break;
                    }
                    int i = 1;
                    long long cnt = it->second.cnt, *vp = it->second.vp;
                    for (; i <= cnt; ++i) {
                        if (vp[i] > pos) {
                            break;
                        }
                    }
                    --i;
                    //cout << pos << " " << i << " " << vp[i] << " " <<it->second.vn[i] << '\n';
                    pos -= vp[i];
                    s += '.';
                    s += it->second.vn[i];
                    it = tps.find(it->second.name2tppos[it->second.vn[i]].first);
                }
                if (!err) cout << s << '\n';
            }
        }
    }
    return 0;
}
