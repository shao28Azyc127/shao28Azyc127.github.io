#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int n, op, k, tot, lim[205], sz[205], mem = 0;
string c[100005];
string s, t, x;
map<string, int> m;
struct node{
    int tot = 0;
    string pos[105];
    map<string, int> m;
    struct per{
        int tp, name, r, mem;
    }b[205];
}a[205];
struct yuan{
    int tp, name, l, r;
    yuan(){
    }
    yuan(int _tp, int _name, int _l, int _r){
        tp = _tp;
        name = _name;
        l = _l;
        r = _r;
    }
}ys[205];
inline void init(){
    m["byte"] = 1;
    m["short"] = 2;
    m["int"] = 3;
    m["long"] = 4;
    tot = 4;
    sz[1] = lim[1] = 1;
    sz[2] = lim[2] = 2;
    sz[3] = lim[3] = 4;
    sz[4] = lim[4] = 8;
}
inline void full(string s, int tp){
    for(int i = 1;i <= a[tp].tot;i++){
        if(mem % lim[a[tp].b[i].tp] == 0){
            for(int j = mem;j < mem + sz[a[tp].b[i].tp];j++){
                c[j] = s + '.' + a[tp].pos[i];
            }
            mem += sz[a[tp].b[i].tp];
        }
        else{
            mem = (mem / lim[a[tp].b[i].tp] + 1) * lim[a[tp].b[i].tp];
            for(int j = mem;j < mem + sz[a[tp].b[i].tp];j++){
                c[j] = s + '.' + a[tp].pos[i];
            }
            mem += sz[a[tp].b[i].tp];
        }
    }
}
signed main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n;
    init();
    while(n--){
        cin >> op;
        if(op == 1){
            cin >> s >> k;
            if(!m[s]){
                m[s] = ++tot;
            }
            for(int i = 1;i <= k;i++){
                cin >> t >> x;
                a[m[s]].m[x] = ++a[m[s]].tot;
                a[m[s]].pos[a[m[s]].tot] = x;
                lim[m[s]] = max(lim[m[s]], lim[m[t]]);
                if(sz[m[s]] % lim[m[t]] == 0){
                    sz[m[s]] += sz[m[t]];
                }
                else{
                    sz[m[s]] = (sz[m[s]] / lim[m[t]] + 1) * lim[m[t]];
                    sz[m[s]] += sz[m[t]];
                }
                a[m[s]].b[i].tp = m[t];
                a[m[s]].b[i].name = a[m[s]].m[x];
                a[m[s]].b[i].r = sz[m[s]];
                a[m[s]].b[i].mem = sz[m[t]];
            }
            cout << sz[m[s]] << " " << lim[m[s]] << "\n";
        }
        else if(op == 2){
            cin >> t >> x;
            if(!m[x]){
                m[x] = ++tot;
            }
            ys[m[x]].tp = m[t];
            if(mem % lim[m[t]] == 0){
                ys[m[x]].l = mem;
                mem += sz[m[t]];
                ys[m[x]].r = mem - 1;
            }
            else{
                mem = (mem / lim[m[t]] + 1) * lim[m[t]];
                ys[m[x]].l = mem;
                mem += sz[m[t]];
                ys[m[x]].r = mem - 1;
            }
            full(x, m[t]);
            cout << ys[m[x]].l << "\n";
        }
        else if(op == 3){
            cin >> s;
            for(int i = 0;i < mem;i++){
                if(c[i] == s){
                    cout << i << "\n";
                    break;
                }
            }
        }
        else{
            cin >> k;
            if(c[k] == ""){
                cout << "ERR" << "\n";
            }
            else{
                cout << c[k] << "\n";
            }
        }
    }
	return 0;
}
