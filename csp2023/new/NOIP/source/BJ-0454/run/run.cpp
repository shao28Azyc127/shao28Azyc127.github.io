#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#define int long long
using namespace std;
int dp[10010][10010];
struct tz
{
    int x,y,v;
}t[10000010];
bool cmp(tz x,tz y)
{
    if(x.x != y.x) return x.x < y.x;
    else if(x.y != y.y) return x.y < y.y;
    else return x.v > y.v;
}
bool u[10000010];
int mx[10010];
signed main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c,tt;
    cin >> c >> tt;
    while(tt--)
    {
        int n,m,k,d;
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= n; i++) mx[i] = 0;
        for(int i = 1; i <= m; i++)
        {
            cin >> t[i].x >> t[i].y >> t[i].v;
            u[i] = 0;
        }
        sort(t + 1,t + m +1,cmp);
        for(int i = 0; i <= k; i++)
        {
            dp[0][i] = 0;
        }
        int cur = 1;
        for(int i = 1;i <= n; i++)
        {
            for(int j = 0; j <= k; j++)
            {
                if(j > i) dp[i][j] = 0;
                else if(i == t[cur].x)
                {
                    if(j >= t[cur].y) dp[i][j] = dp[i - 1][j - 1] - d + t[cur].v,u[cur] = 1;
                    else if(j != 0) dp[i][j] = dp[i - 1][j - 1] -d;
                    else dp[i][j] = mx[i - 1];
                    if(i == t[cur + 1].x && j + 1 == t[cur + 1].y && j + 1 <= k) cur++,t[cur].v += t[cur - 1].v;
                }
                else if(j == 0)
                {
                    dp[i][j] = mx[i - 1];
                }
                else dp[i][j] = dp[i - 1][j - 1] - d;
                mx[i] = max(mx[i],dp[i][j]);
            }
            if(u[cur] || i + 1 > t[cur].x) cur++;
        }
        cout << mx[n] << endl;
    }
    return 0;
}
