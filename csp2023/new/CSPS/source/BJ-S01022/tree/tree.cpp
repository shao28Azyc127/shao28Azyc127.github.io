#include <iostream>
#include <vector>
#include <cstdio>
#define int long long
using namespace std;
int n, a[100010], b[100010], c[100010];
vector<int> v[100010];
int ans = 0;
int sum[100010];
int vis[100010];
int maxn, maxn_id;
bool flag;
void dfs(int x, int fa){
    if(vis[x] == 0){
        if(maxn > max((long long)1, b[x])){
            maxn_id = x;
            maxn = max((long long)1, b[x]);
        }
        return;
    }

    for(int i = 0; i < v[x].size(); i++){
        if(v[x][i] != fa){
            dfs(v[x][i], x);
        }
    }
}
signed main(){
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    bool flag_A = true, flag_C = true;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >>b[i] >> c[i];
        if(c[i] != 0){
            flag_C = false;
        }
    }

    for(int i = 1; i <= n - 1; i++){
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        if(x + 1 != y){
            flag_A = false;
        }
    }
    if(flag_A){

    for(ans = 1; ; ans++){
        bool flag = true;
        for(int j = 1; j <= n; j++){
            if(j <= ans){
                sum[j] += max((long long)1, b[j] + ans * c[j]);
            }
            if(sum[j] < a[j]){
                flag = false;
            }
        }
        if(flag){
            cout << ans <<endl;
            return 0;
        }
    }
    }
    if(flag_C){
        vis[1] = 1;
        for(ans = 1; ; ans++){
            maxn = 0x3f3f3f3f, maxn_id = -1;
            flag = true;
            dfs(1, 0);


            for(int i = 1; i <= n; i++){
                if(vis[i] == 1){
                    sum[i] += max((long long)1, b[i]);
                }
                if(sum[i] < a[i]){
                    flag = false;
                }
            }

            if(flag){
                cout << ans <<endl;
                return 0;
            }
             if(maxn_id != -1){
                vis[maxn_id] = 1;
            }
        }
    }
    return 0;
}
