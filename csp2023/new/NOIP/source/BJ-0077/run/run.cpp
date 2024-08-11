#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1005;
int x[maxn], y[maxn], xx[maxn], yy[maxn], v[maxn];
int s[maxn];
#define pii pair<int, int>
#define mp make_pair
vector<pii > from[maxn << 1];
int f[maxn << 1][maxn << 1], ans[maxn << 1];
signed main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, T;
    cin>>c>>T;
    while(T--){
        int n, m, k, d;
        cin>>n>>m>>k>>d;
        for(int i=0;i<m;i++){
            int x0, y0;
            cin>>x0>>y0>>v[i];
            x[i] = x0 - y0;
            y[i] = x0;
            s[i<<1] = x[i];
            s[i<<1|1]=y[i];
        }
        sort(s, s + 2 * m);
        int sn = unique(s, s+2*m) - s;
        int tn = s[sn - 1];
        for(int i=0;i<sn;i++){ans[i]=0;from[i].clear();}
        for(int i=0;i<m;i++){
            xx[i] = lower_bound(s, s+sn, x[i]) - s;
            yy[i] = lower_bound(s, s+sn, y[i]) - s;
            from[xx[i]].push_back(mp(yy[i], v[i]));
        }
        int res = 0;
        for(int i=0;i<sn;i++){
            int sum = 0, len = 0;
            for(int j=i;j>=0;j--){
                for(int k=0;k<from[j].size();k++){
                    if(from[j][k].first <= i) sum += from[j][k].second;
                }
                f[i][j] = (j ? ans[j-1] : 0) + sum - len * d;
                //cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
                ans[i] = max(ans[i], f[i][j]);
                if(j != 0){
                    len += s[j] - s[j - 1];
                    if(len > k) break;
                }
            }
            res = max(res, ans[i]);
        }
        cout<<res<<endl;
    }
    return 0;
}
