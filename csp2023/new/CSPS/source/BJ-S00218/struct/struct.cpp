#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef pair<int,int> pii;
typedef long double db;

#define fi first
#define se second

const int N = 1e5+5;
const int inf = 1e9;

int T;
map<string, int> m1;
map<string, int> m2;

string s;

int t1, t2;
vector<pair<int,string> > v[N];

ll sz[N], qi[N];
ll get(ll x, ll y){
    if (x%y == 0) return x;
    return x+(y-x%y);
}

void solve(){
    ll sum;
    cin >> sum;
    int pos = 0;
    ll ans = 0;

    string s = "";
    while(v[pos].size()){
        for (int i = 0; i < v[pos].size(); i++){
            auto y = v[pos][i];
            ans = get(ans, qi[y.fi]);
            if (ans > sum){
                cout << "ERR" << endl;
                return;
            }
            // cout << "SZ " << sz[y.fi] << endl;
            if (ans+sz[y.fi]-1 >= sum){
                if (pos) s += '.';
                s += y.se;
                pos = y.fi;
                break;
            }else if (i == v[pos].size()-1){
                cout << "ERR" << endl;
                return;
            }
            ans += sz[y.fi];
            // cout << ans << endl;
        }
        
    }
    if (s == ""){
        cout << "ERR" << endl;
        return;
    }
    cout << s << endl;
    return;
}
signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> T;
    m1["byte"] = 1, m1["short"] = 2, m1["int"] = 3, m1["long"] = 4;
    sz[1] = qi[1] = 1, sz[2] = qi[2] = 2, sz[3] = qi[3] = 4, sz[4] = qi[4] = 8;
    t1 = 4;

    int p = 0;
    for (int tt = 1; tt <= T; tt++){
        // cout << tt << endl;
        int op, k;
        cin >> op;
        if (op == 1){
            cin >> s >> k;
            m1[s] = ++t1;

            int now = 0;
            for (int j = 1; j <= k; j++){
                string t,n;
                cin >> t >> n;
                int to = m1[t];
                now = get(now, qi[to]);
                now += sz[to];
                v[t1].push_back(pair<int,string>{to,n});
                qi[t1] = max(qi[t1], qi[to]);
            }
            sz[t1] = get(now, qi[t1]);
            cout << sz[t1] << " " << qi[t1] << endl;
        }
        if (op == 2){
            string t,n;
            cin >> t >> n;
            int to = m1[t];
            p = get(p, qi[to]);
            cout << p << endl;
            p += sz[to];
            // cout << "N: " << n << endl;
            v[0].push_back(pair<int,string>{to,n});
        }if (op == 3){
            string s;
            cin >> s;

            string ss = "";
            ll pos = 0, ans = 0;
            for (int i = 0; i < s.size(); i++){
                if (s[i] == '.' || i == s.size()-1){
                    if (i == s.size()-1) ss += s[i];
                    for (auto y:v[pos]){
                        ans = get(ans, qi[y.fi]);
                        if (y.se == ss){
                            pos = y.fi;
                            break;
                        }
                        ans += sz[y.fi];
                    }
                }
                if (s[i] == '.'){
                    ss = "";
                    continue;
                } 
                ss += s[i];
            }
            cout << ans << endl;
        }if (op == 4){
            solve();
        }
    }
    
    return 0;
}