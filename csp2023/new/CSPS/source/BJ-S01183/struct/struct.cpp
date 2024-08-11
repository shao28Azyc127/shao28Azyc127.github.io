

#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#define ll long long

using namespace std;

struct Ct {
    int t;
    string nm;
};

struct Ob {
    int o[109];
    int a[109];
    int s[109];
    int aa;
    int siz;
};

struct Node {
    string pth;
    string nm;
    ll l;
    ll r;
    ll siz;
};

int N;
int idx;
Node V[100009];
int cnt;
int rt[109];
int cc;
map<string, int> id;
vector<Ct> dt[109];
Ob DT[109];
vector<int> E[100009];
string pth;
string tp;
map<string, int> node;

string Get_Str () {
    string x = "";
    char c = getchar();
    while ((c < 'a' || c > 'z') && c != '.') c = getchar();
    while ((c >= 'a' && c <= 'z') || c == '.') x += c, c = getchar();
    return x;
}

void Create (int typ, string nm, bool f, int p, ll l, ll r) {
    int ii = 1;
    V[++idx] = {pth, nm, l, r, r - l + 1};
    node[pth] = idx;
    if (f) rt[++cnt] = idx;
    E[p].push_back(idx);
    for (auto x : dt[typ]) {
        tp = pth, pth = pth + "." + x.nm;
        Create(x.t, x.nm, 0, idx, l + DT[x.t].o[ii], l + DT[x.t].o[ii] + DT[x.t].siz - 1);
        pth = tp;
        ii++;
    }
}

string Query (int x, ll dz) {
    if (V[x].r < dz) return "ERR";
    for (int i = 0; i < E[x].size(); i++) {
        if (V[E[x][i]].l > dz) {
            i--;
            if (i < 0) return "ERR";
            return Query(E[x][i], dz);
        }
    }
    return V[x].pth;
}

int main () {
    int op;
    int n;
    int a;
    string s;
    string t;
    Ob tt;
    ll dz;

    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    id["byte"] = 1, id["short"] = 2, id["int"] = 3, id["long"] = 4;
    DT[1].aa = DT[1].siz = 1;
    DT[2].aa = DT[2].siz = 2;
    DT[3].aa = DT[3].siz = 4;
    DT[4].aa = DT[4].siz = 8;
    cc = 4;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &op);
        if (op == 1) {
            s = Get_Str(), id[s] = ++cc;
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                s = Get_Str(), t = Get_Str();
                dt[cc].push_back({id[s], t});
            }
            memset(tt.o, 0, sizeof(tt.o));
            memset(tt.s, 0, sizeof(tt.s));
            memset(tt.a, 0, sizeof(tt.a));
            for (int i = 1; i <= dt[cc].size() + 1; i++) tt.a[i] = DT[dt[cc][i - 1].t].aa, tt.s[i] = DT[dt[cc][i - 1].t].siz, tt.aa = max(tt.aa, DT[dt[cc][i - 1].t].aa);
            for (int i = 2; i <= dt[cc].size() + 1; i++) tt.o[i] = (ll)((tt.o[i - 1] + tt.s[i - 1] - 1) / tt.a[i] + 1) * tt.a[i];
            tt.siz = ((ll)(tt.o[n] + tt.s[n] - 1) / tt.aa + 1) * tt.aa;
            DT[cc] = tt;
        }
        else if (op == 2) {
            s = Get_Str(), t = Get_Str();
            pth = t;
            Create(id[s], t, 1, 0, (ll)((V[rt[cnt]].l + V[rt[cnt]].siz - 1) / DT[id[s]].aa + 1) * DT[id[s]].aa, (ll)((V[rt[cnt]].l + V[rt[cnt]].siz - 1) / DT[id[s]].aa + 1) * DT[id[s]].aa + DT[id[s]].siz - 1);
        }
        else if (op == 3) {
            s = Get_Str();
            printf("%lld\n", V[node[s]].l);
        }
        else {
            scanf("%lld", &dz);
            for (int i = 1; i <= cnt; i++)
                if (V[rt[i]].l > dz) {
                    i--;
                    cout << Query(rt[i], dz) << endl;
                    break;
                }
        }
    }
    fclose(stdin), fclose(stdout);
    return 0;
}