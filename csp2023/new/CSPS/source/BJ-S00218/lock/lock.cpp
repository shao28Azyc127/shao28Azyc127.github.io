#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double db;
#define fi first
#define se second

const int N = 1e5+5;
const int inf = 1e9;
const int p = 1e9+7;


int n, ans;
int a[N][6], now[6];
bool check(){
    for (int i = 1; i <= n; i++){
        int t[6];
        for (int j = 1; j <= 5; j++) t[j] = now[j]-a[i][j];
        int p1 = -1, p2 = -1;
        for (int j = 1; j <= 5; j++){
            if (t[j] != 0){
                if (p1 == -1) p1 = j;
                else if (p2 == -1){
                    p2 = j;
                    if (p2-p1 > 1) return 0;
                    if (t[p2] != t[p1] && (t[p2] != t[p1]+10) && (t[p1] != t[p2]+10)) return 0;
                } else return 0;
            }
        }
        if (p1 == -1 && p2 == -1) return 0;
    }
    return 1;
}
void dfs(int d){
    if (d > 5){
        if (check()){
            ans++;
        } 
        return;
    }
    for (int i = 0; i <= 9; i++){
        now[d] = i;
        dfs(d+1);
    }
}
signed main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0u); cout.tie(0u);
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 5; j++){
            cin >> a[i][j];
        }
    }

    dfs(1);
    cout << ans << endl;

    return 0;
}