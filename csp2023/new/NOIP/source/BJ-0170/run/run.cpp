

#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[100010], g[100010], c, T, n, m, k, d;
vector<int> vec[100010];
struct node{
    int l, r, v;
}s[100010];
signed main (){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >> c >> T;
    while(T--){
        memset(s, 0, sizeof(s));
        memset(f, 128, sizeof(f));
        memset(g, 128, sizeof(g));
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= n; i++) if(vec[i].size()) vec[i].clear();
        for(int i = 1; i <= m; i++){
            int x, y, v;
            cin >> x >> y >> v;
            s[i].l = x - y + 1, s[i].r = x, s[i].v = v;
            vec[s[i].l].push_back(i);
        }
        // for(int i = 1; i <= n; i++){
        //     cout << i << endl;
        //     for(auto j : vec[i]){
        //         cout << j << ' ';
        //     }cout << endl;
        // }
        
        f[0] = g[0] = 0;
        for(int i = 1; i <= n; i++){
            int v = 0, sum = 0;
            f[i] = g[i] = f[i - 1];
            for(int j = i; j >= max(1ll, i - k + 1); j--){
                v -= d;
                for(auto k : vec[j]){
                //    if(i == 6) cout << s[k].l << ' ' << s[k].r << ' ' << s[k].v << endl;
                
                    if(s[k].r <= i) sum += s[k].v;
                //    cout << sum << endl;
                }
           //     if(i == 6 && j == 1) cout << v << ' ' << sum << endl;
                f[i] = max(f[i], g[j - 1] + v + sum) ;
            }
        }
        // for(int i = 1; i <= n; i++) cout << f[i] << ' ';
        // cout << endl;
        // for(int i = 1; i <= n; i++) cout << g[i] << ' ';
        // cout << endl; 
        cout << f[n] << endl;
    }
    return 0;
}