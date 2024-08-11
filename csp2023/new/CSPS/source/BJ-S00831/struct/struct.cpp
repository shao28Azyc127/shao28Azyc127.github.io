#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<map>
#include<cassert>
#define maxn 105 //1e5+5
#define fopen(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);

using namespace std;

struct Elem {
    long long n, k, sz; //n = elements number; k = max delta
    map<string, int> sid;
    vector<string> nm;
    vector<long long> a; //Æ«ÒÆÁ¿
    vector<Elem*> s; //³ÉÔ±
    Elem(int siz = 0) {
        n = 0, k = sz = siz;
    }
    void resize(int nn) {
        n = nn;
        sz = k = 0;
        a.resize(nn + 5); s.resize(nn + 5); nm.resize(nn + 5);
    }
    long long baseon(long long addr) {
        return (addr + k - 1) / k * k;
    }
    void insert(int i, Elem* x, string name) {
        sid[name] = i;
        nm[i] = name;
        if(i > 1) a[i] = x->baseon(a[i - 1] + s[i - 1]->sz), sz += x->sz + a[i] - a[i - 1] - s[i - 1]->sz;
        else a[i] = 0, sz += x->sz;
        k = max(k, x->k);
        s[i] = x;
        //cout << i << ' ' << name << ' ' << a[i] << endl;
    }
    void insert(Elem* x, string name) {
        int i = ++n;
        if(i == 1) {
            a.resize(1), s.resize(1); nm.resize(1);
        }
        nm.push_back(name);
        sid[name] = i;
        if(i > 1) a.push_back(x->baseon(a[i - 1] + s[i - 1]->sz)), sz += x->sz + a[i] - a[i - 1] - s[i - 1]->sz;
        else a.push_back(0), sz += x->sz;
        k = max(k, x->k);
        s.push_back(x);
    }
} a[maxn + 5], Byte(1), Short(2), Int(4), Long(8);

map<string, int> id;//f : name -> id;

int q, op, an, k;
long long adi; //address int
string str, tp, nm, ads; //ads=address string

signed main() {
    fopen("struct");
    ios::sync_with_stdio(false); cin.tie(0);
    a[0].resize(0);
    a[1] = Byte, a[2] = Short, a[3] = Int, a[4] = Long, an = 4;
    id["byte"] = 1, id["short"] = 2, id["int"] = 3, id["long"] = 4;
    cin >> q; 
    while(q--) {
        cin >> op;
        switch(op) {
            case 1 :{
                an++; 
                cin >> str;
                id[str] = an;
                cin >> k;
                a[an].resize(k);
                for(int i = 1; i <= k; i++) {
                    cin >> tp >> nm;
                    a[an].insert(i, &a[id[tp]], nm);
                }
                a[an].sz = (a[an].sz + a[an].k - 1) / a[an].k * a[an].k;
                cout << a[an].sz << ' ' << a[an].k << '\n';
                break;
            }
            case 2: {
                cin >> tp >> nm;
                a[0].insert(&a[id[tp]], nm);
                cout << a[0].a[a[0].sid[nm]] << '\n';
                break;
            }
            case 3: {
                bool err = false;
                Elem *r;
                r = &a[0];
                adi = 0;
                cin >> ads;
                ads += ".";
                int n = ads.size();
                ads = " " + ads;
                nm = "";
                for(int i = 1; i <= n; i++) {
                    if(ads[i] == '.') {
                        if(r->sid[nm] == 0) {
                            cout << "ERR\n";
                            err = true;
                            break;
                        }
                        adi += r->a[r->sid[nm]];
                        r = r->s[r->sid[nm]];
                        nm = "";
                    }
                    else nm += ads[i];
                }
                if(err) break;
                cout << adi << '\n';
                break;
            }
            case 4: {
                bool err = false;
                Elem *r;
                r = &a[0];
                ads = "";
                cin >> adi;
                while(true) {
                    if(adi >= r->sz) {
                        cout << "ERR\n";
                        err = true;
                        break;
                    }
                    if(r->n == 0) break;
                    for(int j = 1; j <= r->n; j++) {
                        if(j == r->n || adi < r->a[j + 1]) {
                            if(r->nm[j].size() == 0) assert(false);
                            adi -= r->a[j];
                            ads += r->nm[j] + ".";
                            r = r->s[j];
                            break;
                        }
                    }
                }
                if(err) break;
                if(ads.size() > 0) ads.erase(ads.size() - 1, 1);
                cout << ads << '\n';
                break;
            }
        }
    }
}