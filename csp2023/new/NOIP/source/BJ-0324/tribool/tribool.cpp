#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int c, T;
int n, m;

struct Edge {
    int v, time;
    int type; // 0: false, 1, true, 2, special.
    char special; // F, false, T, true, U, unknown;
};

struct Res {
    int start, type;
    char special;
};

struct Edge2 {
    int v, type;
};

vector <Edge> e[MAXN];
Res starts[MAXN];
char ans[MAXN];
vector <Edge2> e2[MAXN];
bool vis[MAXN];

Res findStart(int cur, int curtime, bool TFtype) {
    if (e[cur].size() == 0) {
        return (Res) {cur, TFtype, '#'};
    }
    for (int i = e[cur].size() - 1; i >= 0; i--) {
        if (e[cur][i].time < curtime) {
            if (e[cur][i].type == 2) {
                return (Res) {e[cur][i].v, 2, e[cur][i].special};
            }
            if (e[cur][i].type == 0) {
                return findStart(e[cur][i].v, e[cur][i].time, !TFtype);
            }
            if (e[cur][i].type == 1) {
                return findStart(e[cur][i].v, e[cur][i].time, TFtype);
            }
        }
    }
    return (Res) {cur, TFtype, '#'};
}

void printRes(int id, Res r) {
    cout << "Res: " << id << "======================" << endl;
    cout << "start: " << r.start;
    cout << " type: " << r.type;
    cout << " special: " << r.special;
    cout << endl; 
}

void color(int cur) {
    //cout << cur << " ";
    vis[cur] = true;
    if (e2[cur].size() == 0) return;
    for (int i = 0; i < e2[cur].size(); i++) {
        ans[e2[cur][i].v] = 'U';
        if (!vis[e2[cur][i].v]) color(e2[cur][i].v);
    }
}

bool colorTF(int cur, bool color) {
    //cout << cur;
    //bool ok = true;
    for (int i = 0; i < e2[cur].size(); i++) {
        
        if (ans[e2[cur][i].v] == '#') {
            //vis[e2[cur][i].v] = true;
            if (e2[cur][i].type == 0) {
                ans[e2[cur][i].v] = (!color == 0) ? 'F' : 'T';
                return colorTF(e2[cur][i].v, !color);
            }
            if (e2[cur][i].type == 1) {
                ans[e2[cur][i].v] = (color == 0) ? 'F' : 'T';
                return colorTF(e2[cur][i].v, color);
            }
            ans[e2[cur][i].v] = '#';
            //vis[e2[cur][i].v] = false;
        }
        else {
            //for (int j = 1; j <= n; j++) {
            //    cout << ans[j];
            //}
            //cout << " " << cur << " " << e2[cur][i].v << " type" << e2[cur][i].type << " color: " << color << endl;
            if (ans[e2[cur][i].v] == 'U') {
                return false;
            }
            char tgtcolor;
            if (e2[cur][i].type == 0) {
                tgtcolor = ((!(color == 0)) ? 'F' : 'T');
            }
            else if (e2[cur][i].type == 1) {
                tgtcolor = ((color == 0) ? 'F' : 'T');
            }
            //cout << tgtcolor << " " << ans[e2[cur][i].v] << endl;
            if (tgtcolor != ans[e2[cur][i].v]) {
                return false;
            }
        }
    }
    return true;
}

void colorTFin(int cur, bool color) {
    //cout << cur;
    for (int i = 0; i < e2[cur].size(); i++) {
        
        if (ans[e2[cur][i].v] == '#') {
            if (e2[cur][i].type == 0) {
                ans[e2[cur][i].v] = (!color == 0) ? 'F' : 'T';
                colorTFin(e2[cur][i].v, !color);
            }
            if (e2[cur][i].type == 1) {
                ans[e2[cur][i].v] = (color == 0) ? 'F' : 'T';
                colorTFin(e2[cur][i].v, color);
            }
            //ans[e2[cur][i]] = '#';
        }


    }
    //cout << "colored res: ";
    //for (int j = 1; j <= n; j++) {
    //    cout << ans[j];
    //}
    //cout << endl;
}

int main() {
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(false);
    //cin.tie(0);
    //edges[MAXN + 1].push_back((Edge) {MAXN + 1});
    cin >> c >> T;

    while (T--) {
        cin >> n >> m;
        //cout << "###############################" << endl;
        for (int i = 1; i <= n; i++) {
            e[i].clear();
            e2[i].clear();
            ans[i] = '#';
            vis[i] = false;
        }
        
        for (int i = 1; i <= m; i++) {
            char op;
            cin >> op;
            if (op == '+') {
                int u, v;
                cin >> u >> v;
                e[u].push_back((Edge) {v, i, 1, '#'});
            }
            else if (op == '-') {
                int u, v;
                cin >> u >> v;
                e[u].push_back((Edge) {v, i, 0, '#'});
            }
            else {
                int u;
                cin >> u;
                e[u].push_back((Edge) {u, i, 2, op});
            }
        }

        for (int i = 1; i <= n; i++) {
            starts[i] = findStart(i, INF, true);
            e2[i].push_back((Edge2) {starts[i].start, starts[i].type});
            e2[starts[i].start].push_back((Edge2) {i, starts[i].type});
            //printRes(i, starts[i]);
        }

        for (int i = 1; i <= n; i++) {
            if (starts[i].start == i && starts[i].type == 0) {
                ans[i] = 'U';
                color(i);
            }
            if (starts[i].type == 2) {
                ans[i] = starts[i].special;
                colorTFin(i, ((ans[i] == 'T') ? true : false));
                if (ans[i] == 'U') {
                    color(i);
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            bool ok = true;
            if (ans[i] != 'U') {
                if (ans[i] == '#') {
                    ans[i] = 'T';
                    bool ok1 = colorTF(i, 1);
                    ans[i] = 'F';
                    //cout << endl;
                    bool ok2 = colorTF(i, 0);
                    //cout << i << " " << ok1 << " " << ok2 << endl;
                    ok = ok1 || ok2;
                    if (ok && ok1 == false) {
                        ans[i] = 'F';
                        colorTFin(i, 0);
                    }
                    else if (ok && ok2 == false) {
                        ans[i] = 'T';
                        colorTFin(i, 1);
                    }
                    else if (ok1 == true && ok2 == true) {
                        ans[i] = 'T';
                        //cout << "coloring i:" << i << endl;
                        colorTFin(i, 1);
                    }
                    else {
                        ans[i] = '#';
                    }
                }
                //else {
                    //ok = colorTF(i, ((ans[i] == 'T') ? true : false));
                //}
            }
            if (!ok) {
                ans[i] = 'U';
                color(i);
            }
        }

        int anscnt = 0;
        for (int i = 1; i <= n; i++) {
            //cout << ans[i];
            if (ans[i] == 'U') {
                anscnt++;
            }
        }
        //cout << endl;


        cout << anscnt << endl;

    }
    return 0;
}