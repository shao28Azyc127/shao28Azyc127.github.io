# include <bits/stdc++.h>
# define int long long
using namespace std;
int n;
map <string, int> siz;
map <string, string> mp;
map <string, int> bg;
map <string, int> f;
map <string, vector <string>> nam;
map <string, vector <string>> tyy;
vector <string> v;
int now;
int nxt(int x, int mod)
{

    if(x % mod == 0) return x;
    return (x / mod + 1) * mod;
}
signed main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ios::sync_with_stdio(0);
    siz["byte"] = 1;
    siz["short"] = 2;
    siz["int"] = 4;
    siz["long"] = 8;
    f["byte"] = 1;
    f["short"] = 2;
    f["int"] = 4;
    f["long"] = 8;
    cin >> n;
    while(n--){
        int opt;
        cin >> opt;
        if(opt == 1){
            string name;
            int k;
            cin >> name >> k;
            for(int j = 1; j <= k; j++){
                string s, t;
                cin >> s >> t;
                f[name] = max(f[name], siz[s]);
                nam[name].push_back(t);
                tyy[name].push_back(s);
            }
            siz[name] = k * f[name];
            cout << siz[name] << " " << f[name] << endl;
        }
        if(opt == 2){
            string ty, name;
            cin >> ty >> name;
            int mod = f[ty];
            now = nxt(now, mod);
            mp[name] = ty;
            bg[name] = now;
            cout << now << endl;
            v.push_back(name);
            if(ty == "byte" || ty == "short" || ty == "int" || ty == "long") {
                now += mod;
                continue;
            }
            v.pop_back();
            for(int j = 0; j < nam[ty].size(); j++){
                string w = name + "." + nam[ty][j];
                v.push_back(w);
                mp[w] = tyy[ty][j];
                bg[w] = now;
                now += mod;
            }
            //cout << now << endl;
        }
        if(opt == 3){
            string q;
            cin >> q;
            cout << bg[q] << endl;
        }
        if(opt == 4){
            int a;
            cin >> a;
            bool f = 0;
            for(int j = 0; j < v.size();j++) {
                string cur = v[j];
                int bgg = bg[cur]; string tty = mp[cur];
                int ed = bgg + siz[tty] - 1;
                if(bgg <= a && a <= ed) cout << cur << endl, f = 1;
            }
            if(f == 0) {
                cout << "ERR" << endl;
            }
        }
    }
    return 0;
}
