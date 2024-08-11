#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, op, cnt, scnt, usedmem = 0;

map <string, int> saddr;
map <string, int> iaddr;

struct Node{
    int l, r, tsize;
    vector <int> ch;
    string t, n, iname;
}t[12800];

bool isbasic(string t){
    return (t == "byte" || t == "short" || t == "int" || t == "long");
}

int getsize(string t);
int getcsize(string t);
int gettsz(string t);

struct Strct{
    string n;
    int k, msize, csize, truesz;
    vector <string> t, mn;
}strct[12800];

int getcsize(string t){
    return strct[saddr[t]].csize;
}
int gettsz(string t){
    return strct[saddr[t]].truesz;
}
Strct getstrct(string t){
    return strct[saddr[t]];
}

void fillu(Strct s, int &u){
    for (int i = 0; i < s.k; i++){
        string t = s.t[i];
        if (!isbasic(t)) fillu(getstrct(s.t[i]), u);
        else{
            int f = getsize(t);
            if (u%f != 0) u = ceil(u*1.0/f)*f;
            u += f;
        }
    }
}

int getsize(string t){
    if (t == "byte") return 1;
    if (t == "short") return 2;
    if (t == "int") return 4;
    if (t == "long") return 8;
    return strct[saddr[t]].msize;
}

int addinst(string tt, string n, int d, int trg = -1, string p = "rp--"){
    cnt++;
    int id = cnt;
    //cout << "typename:" << tt << ", var name=" << n << ", l=";
    t[id].l = ceil(usedmem*1.0/getsize(tt))*getsize(tt);
    t[id].r = t[id].l+getsize(tt)-1;
    t[id].t = tt;
    t[id].tsize = getsize(tt);
    t[id].n = n;
    if (p == "rp--") t[id].iname = n;
    else t[id].iname = p+"."+n;
    iaddr[t[id].iname] = id;
    if (!isbasic(tt)){
        for (int i = 0; i < strct[saddr[tt]].k; i++){
            int ad = addinst(strct[saddr[tt]].t[i], strct[saddr[tt]].mn[i], d+1, -1, t[id].iname);
            t[id].ch.push_back(ad);
            t[id].l = min(t[id].l, t[ad].l);
        }
        t[id].r = t[id].l+getsize(tt)-1;
    }
    //cout << "a var name=" << t[id].iname << endl;
    usedmem = (trg == -1 ? t[id].r+1 : t[id].l+strct[saddr[tt]].csize);
    //cout << " -left=" << t[id].l << endl;
    return id;
}

void addstrct(){
    string n;
    int k;
    cin >> n >> k;
    scnt++;
    strct[scnt].n = n;
    strct[scnt].k = k;
    string tt, nn;
    while (k--){
        cin >> tt >> nn;
        strct[scnt].t.push_back(tt);
        strct[scnt].mn.push_back(nn);
    }
    int u = 0, f = 0, csize = 0;
    fillu(strct[scnt], u);
    for (int i = 0; i < strct[scnt].k; i++){
        if (isbasic(strct[scnt].t[i])){
            f = getsize(strct[scnt].t[i]);
            csize = max(csize, f);
        }
        else csize = max(csize, getcsize(strct[scnt].t[i]));
    }
    strct[scnt].csize = csize;
    strct[scnt].msize = ceil(u*1.0/csize)*csize;
    strct[scnt].truesz = u;
    saddr[n] = scnt;
    cout << strct[scnt].msize << " " << strct[scnt].csize << endl;
}

int findt(int c){
    int ans = -1, lst = 666666666666666669;
    for (int i = 1; i <= cnt; i++){
        if (t[i].l <= c && t[i].r >= c && isbasic(t[i].t)){
            if (t[i].r-t[i].l+1 < lst){
                lst = t[i].r-t[i].l+1;
                ans = i;
            }
        }
    }
    return ans;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    string a, b;
    int c;
    while (n--){
        cin >> op;
        if (op == 1){
            addstrct();
        }
        if (op == 2){
            cin >> a >> b;
            cout << t[addinst(a, b, 0)].l << endl;
        }
        if (op == 3){
            cin >> a;
            cout << t[iaddr[a]].l << endl;
        }
        if (op == 4){
            cin >> c;
            int r = findt(c);
            if (r != -1) cout << t[r].iname << endl;
            else cout << "ERR\n";
        }
    }
    return 0;
}
