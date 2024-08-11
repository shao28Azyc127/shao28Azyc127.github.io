#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double db;
typedef pair<int,int> pii;
#define fi first
#define se second

const int inf = 1e9+5;
// const int p = 998244353;
const int N = 2005;
const int M = 5e5+5;
int c,n,m,q;

bool ok[N][N], can[N][N];
int a[M], b[M], op;
int aa[M], bb[M];
bool cmp(int a, int b){
    if (op == 1){
        if (a > b) return 1;
        return 0;
    }else{
        if (a < b) return 1;
        return 0;
    }
}

void cal(){
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            ok[i][j] = can[i][j] = 0;
        }
    }

    if (a[1] > b[1]) op = 1;
    else op = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            if (cmp(a[i], b[j])) ok[i][j] = 1;
        }
    }
    for (int i = 1; i <= m; i++){
        if (!ok[1][i]) break;
        can[1][i] = 1;
    }

    for (int i = 2; i <= n; i++){
        int mx = 0;
        for (int j = 1; j <= m; j++){
            if (can[i-1][j] && ok[i][j]) mx = j, can[i][j] = 1;
            if (ok[i][j] && can[i][j-1]){
                mx = j;
                can[i][j] = 1;
            }
        }
        for (int j = mx; j >= 1; j--) if (ok[i][j]) can[i][j] = 1;
    }
    cout << can[n][m];
}

int mx[M][21], mn[M][21];

void cal3(){
    int now = 0;
    for (int i = 1; i <= m; i++){
        if (a[1] >= b[i]) break;
        now = i;
    }

    // cout << now << "\n";
    for (int i = 2; i <= n; i++){
        if (a[i] <= a[i-1]){
            for (int j = 20; j >= 0; j--){
                if (now+(1<<j)-1 <= m && mn[now][j] > a[i]){
                    now = now+(1<<j);
                }
            }
            if (now > m || b[now] <= a[i]) now--;
        }else{
            for (int j = 20; j >= 0; j--){
                if (now >= (1<<j) && mx[now-(1<<j)+1][j] <= a[i]){
                    now = now-(1<<j);
                }
            }
        }
        if (!now){
            cout << 0;
            return;
        }
        if (now == m){
            cout << 1;
            return;
        }
    }
    if (now == m) cout << 1;
    else cout << 0;
}
void cal4(){
    int now = 0;
    for (int i = 1; i <= m; i++){
        if (a[1] <= b[i]) break;
        now = i;
    }

    // cout << now << "\n";
    for (int i = 2; i <= n; i++){
        if (a[i] >= a[i-1]){
            for (int j = 20; j >= 0; j--){
                if (now+(1<<j)-1 <= m && mx[now][j] < a[i]){
                    now = now+(1<<j);
                }
            }
            if (now > m || b[now] >= a[i]) now--;
        }else{
            for (int j = 20; j >= 0; j--){
                if (now >= (1<<j) && mn[now-(1<<j)+1][j] >= a[i]){
                    now = now-(1<<j);
                }
            }
        }
        if (!now){
            cout << 0;
            return;
        }
        if (now == m){
            cout << 1;
            return;
        }
    }
    if (now == m) cout << 1;
    else cout << 0;
}
void cal2(){

    for (int i = 1; i <= m; i++){
        mx[i][0] = mn[i][0] = b[i];
    } 
    // cout << "\n";

    for (int i = 1; i <= 20; i++){
        for (int j = 1; j+(1<<i)-1 <= m; j++){
            mx[j][i] = max(mx[j][i-1], mx[j+(1<<i-1)][i-1]);
            mn[j][i] = min(mn[j][i-1], mn[j+(1<<i-1)][i-1]);
        }
    }

    if (a[1] < b[1]){
        cal3();
    }else if (a[1] > b[1]){
        cal4();
    }else cout << 0;

}
void solve1(){
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) aa[i] = a[i];
    for (int i = 1; i <= m; i++) bb[i] = b[i];
    if (c <= 7) cal();
    else cal2();
    for (int i = 1; i <= q; i++){
        int kx,ky;
        cin >> kx >> ky;
        for (int j = 1; j <= n; j++) a[j] = aa[j];
        for (int j = 1; j <= m; j++) b[j] = bb[j];
        for (int j = 1; j <= kx; j++){
            int p,v;
            cin >> p >> v;
            a[p] = v;
        }
        for (int j = 1; j <= ky; j++){
            int p,v;
            cin >> p >> v;
            b[p] = v;
        }
        if (c <= 7) cal();
        else cal2();
    }
}
signed main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> c >> n >> m >> q;
    solve1();
    cout << "\n";
    return 0;
}