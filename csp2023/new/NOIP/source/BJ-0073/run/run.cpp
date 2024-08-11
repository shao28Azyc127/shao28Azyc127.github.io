#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<int, int> > keen[100005];
int x[100005], y[100005], v[100005];
ll vw[100005];
ll dp[3005][3005];
int spc[3005];
signed main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--){
        int n, m, k, d;
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= m; i++){
            cin >> x[i] >> y[i] >> v[i];
            if(c <= 9) keen[x[i]].push_back(make_pair(y[i], v[i]));
        }
        if(c <= 9){
            for(int i = 0; i <= n; i++)
                for(int j = 0; j <= k; j++) dp[i][j] = -1e15;
            dp[0][0] = 0;
            for(int i = 1; i <= n; i++){
                for(int j = 0; j <= k; j++) vw[j] = 0;
                for(int j = 0; j < keen[i].size(); j++){
                    int y = keen[i][j].first;
                    int v = keen[i][j].second;
                    vw[y] += v;
                }
                for(int j = 0; j <= k; j++) dp[i][0] = max(dp[i - 1][j], dp[i][0]);
                for(int j = 1; j <= k; j++){
                    vw[j] += vw[j - 1];
                    dp[i][j] = dp[i - 1][j - 1] + vw[j] - d;
                //    cout << i << '-' << j << "=" << dp[i][j] << endl;
                }
            }
            ll ans = 0;
            for(int i = 0; i <= k; i++){
                ans = max(dp[n][i], ans);
            }
            cout << ans << '\n';
            for(int i = 1; i <= n; i++){
                keen[i].clear();
                for(int j = 0; j <= k; j++) dp[i][j] = -1e15;
            }
        } else if(c == 10 || c == 11){
            int tot = 0;
            ll ans = 0;
            for(int i = 1; i <= m; i++){
                spc[++tot] = x[i] - y[i];
                spc[++tot] = x[i];
            }
            sort(spc + 1, spc + 1 + tot);
            tot = unique(spc + 1, spc + 1 + tot) - spc - 1;
            for(int i = 0; i <= tot; i++)
                for(int j = 0; j <= k; j++) dp[i][j] = -1e15;
            dp[0][0] = 0;
            for(int i = 1; i <= tot; i++) keen[i].clear();
            for(int i = 1; i <= m; i++){
                int xx = lower_bound(spc + 1, spc + 1 + tot, x[i]) - spc;
                keen[xx].push_back(make_pair(y[i], v[i]));
             //   cout << x[i] << "=" << xx << endl;
            }
            for(int i = 1; i <= tot; i++){
                for(int j = 0; j <= k; j++) vw[j] = 0;
                for(int j = 0; j < keen[i].size(); j++){
                    int y = keen[i][j].first;
                    int v = keen[i][j].second;
                    vw[y] += v;
                }
                int t = spc[i] - spc[i - 1];
                for(int j = 0; j <= k; j++) dp[i][0] = max(dp[i - 1][j], dp[i][0]);
                for(int j = t; j <= k; j++){
                    vw[j] += vw[j - 1];
                    dp[i][j] = dp[i - 1][j - t] + vw[j] - d * t;
               //     cout << spc[i] << "-" << j << "=" << dp[i][j]  << "from" << spc[i - 1] << "," << j-t << "=" <<  dp[i - 1][j - t] << " " << vw[j] << " " << d * t << '\n';
                    ans = max(ans, dp[i][j]);
                }
            }
            cout << ans << '\n';
            continue;
        }
    }
    return 0;
}
