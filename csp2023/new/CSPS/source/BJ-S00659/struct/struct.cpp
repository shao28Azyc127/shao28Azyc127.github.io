# include <cstdio>
# include <vector>
# include <iostream>
# include <unordered_map>
typedef long long ll;
using namespace std;

struct St{
    ll sz;
    int mt;
    vector <string> mem;
    unordered_map <string, int> x;
    unordered_map <string, int> t;
    void init(){
        sz = 0, mt = 0;
        mem.clear();
        x.clear();
        t.clear();
    }
};
vector <St> v;
unordered_map <string, int> st;
int cnt;

struct El{
    string name;
    ll pos;
    int tp;
};
vector <El> e;
unordered_map <string, int> ele;
int ecn = -1;
ll maxn = 0;

void init(){
    for (int i = 0; i <= 3; i++){
        St x;
        x.init();
        v.push_back(x);
        v[i].sz = v[i].mt = (1 << i);
    }
    st["byte"] = 0, st["short"] = 1, st["int"] = 2, st["long"] = 3;
    cnt = 3;
}

int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    int n;
    cin >> n;
    init();
    while (n--){
        int op;
        cin >> op;
        if (op == 1){
            string s;
            cin >> s;
            St x;
            x.init();
            v.push_back(x), cnt++;
            st[s] = cnt;
            int k;
            cin >> k;
            while (k--){
                cin >> s;
                int tp = st[s];
                cin >> s;
                v[cnt].mem.push_back(s);
                v[cnt].x[s] = v[cnt].mem.size() - 1;
                v[cnt].t[s] = tp;
                v[cnt].mt = max(v[cnt].mt, v[tp].mt);
            }
            k = v[cnt].mem.size();
            for (int i = 0; i < k; i++)
                v[cnt].sz += (v[v[cnt].t[v[cnt].mem[i]]].sz + v[cnt].mt - 1) / v[cnt].mt * v[cnt].mt;
            cout << v[cnt].sz << ' ' << v[cnt].mt << endl;
        }
        if (op == 2){
            string t, name;
            cin >> t >> name;
            st[name] = st[t];
            El now;
            e.push_back(now), ecn++;
            ele[name] = ecn;
            cout << maxn << endl;
            e[ecn].name = name, e[ecn].tp = st[name], e[ecn].pos = maxn;
            maxn += v[st[name]].sz;
        }
        if (op == 3){
            string s;
            cin >> s;
            string tmp = "";
            int len = s.length();
            int i;
            for (i = 0; i < len; i++){
                if (s[i] == '.')
                    break;
                tmp += s[i];
            }
            ll ans = e[ele[tmp]].pos;
            int pos = st[tmp];
            tmp.clear(), i++;
            while (1){
                if (i >= len){
                    int x = v[pos].x[tmp];
                    for (int j = 0; j < x; j++)
                        ans += (v[v[pos].t[v[pos].mem[j]]].sz + v[pos].mt - 1) / v[pos].mt * v[pos].mt;
                    break;
                }
                if (s[i] == '.'){
                    int x = v[pos].x[tmp];
                    for (int j = 0; j < x; j++)
                        ans += (v[v[pos].t[v[pos].mem[j]]].sz + v[pos].mt - 1) / v[pos].mt * v[pos].mt;
                    pos = v[pos].t[tmp];
                    tmp.clear(), i++;
                    continue;
                }
                tmp += s[i];
                i++;
            }
            cout << ans << endl;
        }
        if (op == 4){
            vector <string> s;
            ll addr;
            cin >> addr;
            if (addr >= maxn){
                cout << "ERR" << endl;
                continue;
            }
            int pos = -1;
            for (int i = 0; i <= ecn; i++){
                if (i != ecn && e[i + 1].pos <= addr)
                    continue;
                pos = i;
                break;
            }
            addr -= e[pos].pos;
            s.push_back(e[pos].name);
            pos = e[pos].tp;
            int mt = v[pos].mt;
            bool val = true;
            while (pos > 3){
                int k = v[pos].mem.size();
                for (int i = 0; i < k; i++){
                    int tmp = addr;
                    addr -= (v[v[pos].t[v[pos].mem[i]]].sz + mt - 1) / mt * mt;
                    if (addr < 0){
                        mt = v[pos].mt;
                        s.push_back(v[pos].mem[i]);
                        pos = v[pos].t[v[pos].mem[i]];
                        addr = tmp;
                        if (addr >= v[pos].sz)
                            val = false;
                        break;
                    }
                }
                if (!val)
                    break;
            }
            if (!val)
                cout << "ERR" << endl;
            else {
                int k = s.size();
                for (int i = 0; i < k - 1; i++)
                    cout << s[i] << '.';
                cout << s[k - 1] << endl;
            }
        }
    }
    return 0;
}