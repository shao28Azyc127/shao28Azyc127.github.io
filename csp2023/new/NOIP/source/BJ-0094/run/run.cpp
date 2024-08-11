#include <bits/stdc++.h>
#define mp make_pair
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
const int MAXM = 1e5 + 5;
int C,T;
int n,m,k,d;
ll dp[MAXN][MAXN];
vector<pair<int,int> > chal[MAXM];
vector<int> Y[MAXM];
vector<ll> sumz[MAXM];

template <class T>
    inline void clear(T &x){
        T y;
        swap(x,y);
    }


int main(){
    #ifndef kevin
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    #endif
    scanf("%d%d",&C,&T);
    if (17 <= C && C <= 18){
        while (T --){
            scanf("%d%d%d%d",&n,&m,&k,&d);
            ll ans = 0;
            while (m --){
                int x,y;
                ll v;
                scanf("%d%d%lld",&x,&y,&v);
                if (y > k)continue;
                ans += max(0ll,v - (ll)y * d);
            }
            printf("%lld\n",ans);
        }
        return 0;
    }
    while (T --){
        clear(chal);
        clear(Y);
        clear(sumz);
        memset(dp,0xc0,sizeof(dp));
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for (int i = 1;i <= m;i ++){
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            chal[x].push_back(mp(y,z));
        }
        for (int i = 1;i <= n;i ++){
            sort(chal[i].begin(),chal[i].end());
            for (auto it : chal[i]){
                Y[i].push_back(it.first);
                sumz[i].push_back(sumz[i].size() ? it.second + sumz[i].back() : it.second);
            }
        }
        
        dp[0][0] = 0;
        for (int i = 1;i <= n;i ++){
            for (int j = 1;j <= k;j ++){
                dp[i][j] = dp[i - 1][j - 1] - d;
                int idx = upper_bound(Y[i].begin(),Y[i].end(),j) - Y[i].begin() - 1;
                // printf("IDX %d\n",idx);
                if (idx >= 0)
                    dp[i][j] += sumz[i][idx];
                // printf("DP (%d,%d) = %lld\n",i,j,dp[i][j]);
            }
            for (int j = 0;j <= k;j ++)
                dp[i][0] = max(dp[i][0],dp[i - 1][j]);
            int idx = upper_bound(Y[i].begin(),Y[i].end(),0) - Y[i].begin() - 1;
            // printf("IDX %d\n",idx);
            if (idx >= 0)
                dp[i][0] += sumz[i][idx];
        }
        ll ans = 0xc0c0c0c0c0c0c0c0;
        for (int i = 0;i <= k;i ++)
            ans = max(ans,dp[n][i]);
        printf("%lld\n",ans);
    }
    
    return 0;
}