#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
#define fi first
#define se second

const int inf = 1e9;
const int p = 998244353;
const int N = 2e5+50;

int c,T,n,m;
int a[N];

int fa[N], val[N];
bool vis[N];
vector<int> v[N];
void init(){
    for (int i = 1; i <= 2*n+10; i++){
        fa[i] = i;
        val[i] = 0;
        vis[i] = 0;
        v[i].clear();
    }
}
int get(int x){
    if (fa[x] == x) return x;
    return fa[x] = get(fa[x]);
}
void merge(int x, int y){
    x = get(x), y = get(y);
    if (x != y){
        fa[x] = y;
    }
}

int rev(int x){
    if (x <= n) return x+n;
    if (x <= 2*n) return x-n;
    if (x == 2*n+1) return 2*n+2;
    if (x == 2*n+2) return 2*n+1;
    return 2*n+3;
}

void dfs(int x){
    if (vis[x]) return;
    vis[x] = 1;
    for (int y:v[x]){
        dfs(y);
    }
}
void solve(){
    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        a[i] = i;
    }
    init();
    for (int i = 1; i <= m; i++){
        char c; 
        int x,y;
        cin >> c;
        if (c == 'T'){
            cin >> x;
            a[x] = 2*n+1;
        }if (c == 'F'){
            cin >> x;
            a[x] = 2*n+2;
        }if (c == 'U'){
            cin >> x;
            a[x] = 2*n+3;
        }if (c == '+'){
            cin >> x >> y;
            a[x] = a[y];
        }if (c == '-'){
            cin >> x >> y;
            a[x] = rev(a[y]);
        }
    }

    for (int i = 1; i <= n; i++){
        merge(i, a[i]);
        merge(i+n, rev(a[i]));
    }
    for (int i = 1; i <= n; i++){
        int t = get(i), t2 = get(i+n);
        // cout << t << " " << t2 << "\n";
        if (t == t2){
            val[t] = 1;
        }else{
            v[t].push_back(t2);
            v[t2].push_back(t);
        }
    }
    val[2*n+3] = 1;
    for (int i = 1; i <= 2*n+3; i++){
        if (val[i]) dfs(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++){
        if (vis[get(i)]) ans++;
    }
    cout << ans << "\n";
}
signed main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> c >> T;
    while(T--){
        solve();
    }
    
    return 0;
}