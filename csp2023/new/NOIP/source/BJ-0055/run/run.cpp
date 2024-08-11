#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
#define fi first
#define se second
// #define int long long

const ll inf = 1e18;
// const int p = 998244353;
const int N = 1e3+5;

int c,T;
int n,m,k,d;
ll f[N][N];

vector<pii> v[N];
void solve1(){
    cin >> n >> m >> k >> d;

    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            f[i][j] = -inf;
        }
        v[i].clear();
    }
    for (int i = 1; i <= n; i++) f[i][0] = 0;

    for (int i = 1; i <= m; i++){
        int x,y,val;
        cin >> x >> y >> val;
        v[x].push_back({y,val});
    }
    for (int i = 1; i <= n; i++){
        sort(v[i].begin(), v[i].end());
    }

    for (int i = 1; i <= n; i++){
        int p = 0; ll sum = 0;
        for (int j = 1; j <= min(i,k); j++){
            while(p < v[i].size() && j >= v[i][p].fi){
                sum += v[i][p].se;
                p++;
            }
            f[i][j] = max(f[i][j], f[i-1][j-1]-d+sum);
        }
        for (int j = 0; j <= min(i-1,k); j++){
            f[i][0] = max(f[i][0], f[i-1][j]);
        }
    }
    ll mx = 0;
    for (int i = 0; i <= min(n,k); i++){
        mx = max(mx, f[n][i]);
    }
    cout << mx << "\n";
}
signed main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> c >> T;
    while(T--){
        if (c <= 9) solve1();
    }
    
    return 0;
}