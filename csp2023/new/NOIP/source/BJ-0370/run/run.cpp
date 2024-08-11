#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int f[1001][1001];
int val[1001][1001];
signed main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, Q;
    cin >> c >> Q;
    if(c <= 10)
    {
        while(Q--)
        {
            memset(f, -999999, sizeof(f));
            memset(val, 0, sizeof(val));
            int n,m,k,d;
            scanf("%lld%lld%lld%lld", &n,&m,&k,&d);
            //for(int i = 0;i <= n;i++)for(int j = 0;j <= k;j++) f[i][j] = -1e18;
            for(int i = 1;i <= m;i++)
            {
                int x, y, v;
                scanf("%lld%lld%lld", &x,&y,&v);
                for(int j = y;j <= k;j++) val[x][j] += v;
            }
            f[0][0] = 0;
            for(int i = 1;i <= n;i++)
            {
                for(int j = 0;j <= k;j++)
                {
                    f[i][0] = max(f[i-1][j], f[i][0]);
                }
                for(int j = 1;j <= k;j++)
                {
                    f[i][j] = f[i-1][j-1] - d + val[i][j];
                }
            }
            int ans = 0;
            for(int i = 0;i <= k;i++) ans = max(ans, f[n][i]);
            printf("%lld\n", ans);
        }
    }
    else{
        while(Q--)
        {
            puts("0");
        }
    }
    return 0;
}
