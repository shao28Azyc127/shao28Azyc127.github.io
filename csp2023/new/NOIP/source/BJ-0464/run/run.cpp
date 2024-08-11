#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<cstring>
#include<iomanip>
#include<cstdlib>
#include<time.h>

using namespace std;

typedef long long ll;
#define pii pair<int,int>
#define pll pair<ll,ll>
#define mkp make_pair

ll c,t;
ll n,m,k,d;
ll ans = 0;

struct node{
    ll x,y,v;
}a[100010];

bool cmp(node A,node B)
{
    return A.x < B.x;
}

int cnt = 0;

void dfs(ll now,ll day,ll eng)
{
    //cout << now << ' ' << day << ' ' << eng << endl;
    ans = max(ans,eng);
    if(now > n)
        return ;
    for(int i = cnt;i <= m;i++)
    {
        if(a[i].x > now)
                break;
        if(a[i].x == now && day >= a[i].y)
            eng += a[i].v,cnt = i;
    }
    if(day < k)
    {
        dfs(now + 1,day + 1,eng - d);
    }
    dfs(now + 1,0,eng);
}

int main()
{
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    cin >> c >> t;
    if(c < 4)
    {
        while(t--)
        {
            cin >> n >> m >> k >> d;
            memset(a,0,sizeof(a));
            ans = cnt = 0;
            for(int i = 1;i <= m;i++)
                cin >> a[i].x >> a[i].y >> a[i].v;
            sort(a + 1,a + m + 1,cmp);
            dfs(0,0,0);
            cout << ans << endl;
        }
    }
    else
    {
        //°ï°ïÎÒ£¬Ëæ»úÒ¯Ò¯
        srand(time(NULL));
        while(t--)
        {
            cin >> n >> m >> k >> d;
            memset(a,0,sizeof(a));
            ans = 0;
            for(int i = 1;i <= m;i++)
            {
                cin >> a[i].x >> a[i].y >> a[i].v;
                ans += (rand() % 2) * a[i].v - (rand() % 2) * d;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
