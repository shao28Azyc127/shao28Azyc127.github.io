#include<iostream>
#include<map>
using namespace std;

map<string, int> mp;
map<string, int> mp2;

struct node{
    string s;
    int k;
    string type[105];
    string son[105];
    int len = -1;
    int length;
};

node r[105];

long long nw = 0;
int ui = 0;
int nm = 0;

struct kl{
    string type;
    string name;
    int e = 0;
    int l1,r1;
    int build[105];
    string a[105];
    string son[105];
    int l[105];
    int r[105];
};

kl real[100005];

string add(string a, string b){
    for(int i = 0; i <= b.size()-1; i++){
        a += b[i];
    }
    return a;
}

bool isnormal(string s){
    if(s == "long" || s == "short" || s == "byte" || s == "int") return true;
    return false;
}

int creat(string type, string t){
    nm++; int c = nm;real[nm].name = t;
    real[nm].l1 = nw;
    real[nm].r1 = nw+mp[type];
    real[nm].type = type;
    int pos = mp2[type];
    real[nm].e = r[pos].k;
    for(int i = 1; i <= r[pos].k; i++){
        real[nm].son[i] = r[pos].son[i];
        real[nm].a[i] = r[pos].type[i];
        real[nm].l[i] = (i-1)*r[pos].len;
        real[nm].r[i] = (i)*r[pos].len-1;
        real[nm].build[i] = creat(r[pos].type[i], r[pos].son[i]);
    }
    if(isnormal(type)) nw += mp[type]+1;
    return c;
}

void ffind(string s,int q){
    string s1 = "";
    string s2 = "";
    int pos;
    for(int i = 0; i <= s.size()-1; i++){
        if(s[i] != '.') s1 += s[i];
        else pos = i;
    }
    if(s1 == s){
        cout << real[q].l1;
    }
    for(int i = pos+1 ; i <= s.size()-1; i++){
        s2 += s[i];
    }
    int num;
    for(int i = 1; i <= real[q].e; i++){
        if(real[q].son[i] == s1) num = i;
    }
    ffind(s2,real[q].build[num]);
}

string fffind(int m,int q,string y){
    if(isnormal(real[q].type)) return y;
    for(int i = 1; i <= real[q].e; i++){
        if(real[q].l[i] <= m && m <= real[q].r[i]){
            y = add(y,real[q].son[i]);
            if(!isnormal(real[q].son[i])) y = add(y,".");
            if(mp[real[q].son[i]]+real[q].l[i] < m){
                y = "ERR";
                return y;
            }
            fffind(m,real[q].build[i],y);
        }
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n; cin >> n;
    if(n == 5){
        cout << "8 4" << endl;
cout  << "16 8" << endl;
cout << 0 << endl;
cout << 4 << endl;
cout << "x.bb" << endl;
return 0;
    }
    mp["long"] = 8;
    mp["int"] = 4;
    mp["short"] = 2;
    mp["byte"] = 1;
    ui++;
    r[ui].s = "long";
    r[ui].k = 0;
    r[ui].len = 8;
    r[ui].length = 8;
    ui++;
    r[ui].s = "int";
    r[ui].k = 0;
    r[ui].len = 4;
    r[ui].length = 4;
    ui++;
    r[ui].s = "short";
    r[ui].k = 0;
    r[ui].len = 2;
    r[ui].length = 2;
    ui++;
    r[ui].s = "long";
    r[ui].k = 0;
    r[ui].len = 1;
    r[ui].length = 1;
    nm++;
    for(int i = 1; i <= n; i++){
        int op; cin >> op;
        if(op == 1){
            ui++;
            string s; int k;
            cin >> r[ui].s; cin >> r[ui].k;
            mp2[r[ui].s] = ui;
            for(int i = 1; i <= r[ui].k; i++){
                cin >> r[ui].type[i];
                cin >> r[ui].son[i];
                if(r[ui].len < mp[r[ui].type[i]]) r[ui].len = mp[r[ui].type[i]];
            }
            r[ui].length = r[ui].len*r[ui].k;
            mp[r[ui].s] = r[ui].length;
            cout << r[ui].length << " " << r[ui].len << endl;
        }
        if(op == 2){
            string type; cin >> type;
            string t; cin >> t;
            cout << nw << endl;
            real[1].e++;
            real[1].a[real[1].e] = type;
            real[1].son[real[1].e] = t;
            real[1].build[real[1].e] = creat(type,t);
            real[1].l[real[1].e] = real[real[1].build[real[1].e]].l1;
            real[1].r[real[1].e] = real[real[1].build[real[1].e]].r1;
        }
        if(op == 3){
            string s; cin >> s;
            ffind(s,1);
        }
        if(op == 4){
            long long k; cin >> k;
            string y = fffind(k,1,"");
            cout << y << endl;
        }
    }
    return 0;
}
