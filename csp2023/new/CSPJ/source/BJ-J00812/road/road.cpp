#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, d;
struct node{
    ll v, a, id;
}p[100005];
/**bool cmp(const node& p1, const node& p2){
    return p1.a < p2.a;
}*/
ll s[100005], mon[100005], tmp;
ll cnt;
ll ans;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out","w", stdout);
    scanf("%lld%lld", &n, &d);
    for(int i = 1;i <= n - 1;i ++)
    {
        scanf("%lld", &p[i].v);
    }
    for(int i = 1;i <= n;i ++)
    {
        scanf("%lld", &p[i].a);
    }
    cnt = 1;
    mon[cnt] = p[1].a;
    s[cnt] = p[1].v;
    for(int i = 2;i <= n - 1;i ++)
    {
        if(mon[cnt] <= p[i].a)
        {
            s[cnt] += p[i].v;
        }
        else
        {
            cnt ++;
            mon[cnt] = p[i].a;
            s[cnt] += p[i].v;
        }
    }
    for(int i = 1;i <= cnt;i ++)
    {
        if(s[i] % d == 0)
        {
            ans += s[i]*mon[i]/d;
        }
        else
        {
            tmp = s[i]/d + 1;
            ans += tmp*mon[i];
            s[i + 1] -= (tmp*d - s[i]);
        }
    }
    printf("%lld", ans);
    return 0;
}
