#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
#define fi first
#define se second

const int inf = 1e9;
// const int p = 998244353;
const int N = 3005;

int n,m;

vector<int> v[N], v2[N];
pair<string, int> s[N];

void solve(int i){
    int p = 1;
    if (s[1].se == i){
        p = 2;
    }
    string now = s[p].fi;
    for (int j = 0; j < m; j++){
        if (v[i][j] > (int)(now[j]-'a')){
            cout << 0;
            return;
        }
        if (v[i][j] < (int)(now[j]-'a')){
            cout << 1;
            return;
        }
    }
    cout << 0;
    return;
}
signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            char c;
            cin >> c;
            v[i].push_back((int)(c-'a'));
            v2[i].push_back((int)(c-'a'));
        }
    }
    if (n == 1){
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
    for (int i = 1; i <= n; i++){
        sort(v2[i].begin(), v2[i].end(), [&](int a, int b){
            return a > b;
        });
    } 
    for (int i = 1; i <= n; i++){
        for (int y:v2[i]){
            s[i].fi += (char)('a'+y);
        }
        s[i].se = i;
    }
    sort(s+1, s+n+1);
    for (int i = 1; i <= n; i++){
        solve(i);
    }
    cout << '\n';

    // cout << (double)clock()/CLOCKS_PER_SEC << "\n";
    return 0;
}