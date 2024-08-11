#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,m,k,d,dp[98128912];
struct challenges
{
    ll x;
    ll y1;
    ll y2;
    ll v;
}challenge[100005];
ll cnt = 1;

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    scanf("%d%d",&c,&t);
    for (ll all = 1;all <= t;all++)
    {
        for (ll i = 1;i <= n;i++)
        {
            dp[i] = 0;
        }
        for (ll i = 1;i <= m;i++)
        {
            challenge[i].x = 0;
            challenge[i].y1 = 0;
            challenge[i].y2 = 0;
            challenge[i].v = 0;
        }
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for (ll i = 1;i <= m;i++)
        {
            scanf("%d%d%d",&challenge[i].x,&challenge[i].y1,&challenge[i].v);
            if (challenge[i].x - challenge[i - 1].x <= challenge[i].y1)
            {
                challenge[i].y2 = challenge[i].x - challenge[i - 1].x;
                challenge[i].y1 = challenge[i - 1].y1 + challenge[i].y2;
            }
        }
        /*for (int i = 1;i <= m;i++)
        {
            cout << challenge[i].x << " " << challenge[i].y1 <<" " <<challenge[i].y2 << " " << challenge[i].v << endl;
        }*/
        for (ll i = 1;i <= n;i++)
        {
            bool flag = false;
            for (ll j = 1;j <= m;j++)
            {
                if (i == challenge[j].x && challenge[j].y1 <= k)
                {
                    //cout << "*" << challenge[cnt].x << " " << i << " " << challenge[j].y1 << " " << k << endl;
                    dp[i] = max(dp[i - 1],dp[i - challenge[j].y2] - challenge[j].y2 * d + challenge[j].v);
                    flag = true;
                    //cout << dp[i] << " " << dp[i - challenge[j].y2] - challenge[j].y2 * d + challenge[j].v << endl;
                }
            }
            if (flag == false)
            {
                //cout << challenge[j].x << " " << i << " " << challenge[j].y1 << " " << k << endl;
                dp[i] = max(dp[i - 1],dp[i - 1] - d);
            }
        }
        /*for (ll i = 1;i <= n;i++)
        {
            cout << dp[i] << endl;
        }*/
        printf("%d\n",dp[n]);
    }
    return 0;
}
