#include<cmath>
#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back

using namespace std;
typedef __int128 ll;
typedef pair<int, int> PII;

template<typename T> inline void read(T &x){
    x = 0; bool F = 0; char c = getchar();
    for (;!isdigit(c);c = getchar()) if (c == '-') F = 1;
    for (;isdigit(c);c = getchar()) x = x*10+(c^48);
    if (F) x = -x;
}

template<typename T> inline void checkmax(T &x, const T &y){if (x<y) x = y;}

template<typename T> inline void checkmin(T &x, const T &y){if (x>y) x = y;}

const int N = 1e5+5;
vector<int> to[N], son[N];
ll a[N], b[N], c[N];
int Time[N];
int End; // mid
int n;

// sum{max(b[i] + x*c[i], 1)}>=a[i]

inline ll up(ll a, ll b){return (a+b-1)/b;}

inline ll sum(ll l, ll r, ll b, ll c){
    // cout << l << " " << r << endl;
    if (c>0){
        return (r-l+1)*b + c*(r-l+1)*(r+l)/2;
    }
    else{
        ll p = up(b+1, -c);
        if (r<p){
            return (r-l+1)*b + c*(r-l+1)*(r+l)/2;
        }
        if (l>=p) return r-l+1;
        // l ... p ... r
        // ......1 ... 1
        // printf("p: %lld\n", p); getchar();
        return sum(l, p-1, b, c) + sum(p, r, b, c);
    }
}

inline void cal(int i){
    // read(Time[i]);
    ll ans, p;
    if (c[i] == 0){
        ans = End - up(a[i], b[i]) + 1;
    }
    else{
        int l = 1, r = End, mid;
        while (l<=r){
            mid = l+r>>1;
            if (sum(mid, End, b[i], c[i])<a[i]) r = mid-1;
            else l = mid+1;
        }
        ans = r;
    }
    if (ans>0) Time[i] = ans;
    else Time[i] = 0;
}

void dfs1(int u, int fa){
    for (int v: to[u]){
        if (v == fa) continue;
        son[u].pb(v);
        dfs1(v, u);
    }
}

void dp(int u){
    for (int v: son[u]){
        dp(v); checkmin(Time[u], Time[v]-1);
    }
}

priority_queue<PII> q;

bool check(int mid){
    End = mid;
    for (int i = 1;i<=n;i++) cal(i), printf("%d\n", Time[i]);
    while (!q.empty()) q.pop();
    dp(1); q.push({-Time[1], 1});
    // for (int i = 1;i<=n;i++) printf("%d ", Time[i]); printf("\n");
    int u;
    for (int i = 1;i<=n;i++){ // Time
        u = q.top().second; q.pop();
        // printf("%d %d %d\n", u, i, Time[u]);
        if (i>Time[u]) return 0;
        for (int v: son[u]){
            q.push({-Time[v], v});
        }
    }
    return 1;
}

int main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    read(n); for (int i = 1;i<=n;i++) read(a[i]), read(b[i]), read(c[i]); int u, v;
    for (int i = 1;i<n;i++) read(u), read(v), to[u].pb(v), to[v].pb(u);
    dfs1(1, 0);
    /* for (int i = 1;i<=n;i++){
        printf("%d: ", i);
        for (int j: son[i]) printf("%d ", j);
        printf("\n");
    } */
    int l = 1, r = 1e9, mid;
    while (l<=r){
        mid = l+r>>1;
        if (check(mid)) r = mid-1;
        else l = mid+1;
    }
    printf("%d\n", l);
    return 0;
}
/*
self check:
1. freopen
2. long long
3. size of array
4. code for testing
5. initializing
*/
