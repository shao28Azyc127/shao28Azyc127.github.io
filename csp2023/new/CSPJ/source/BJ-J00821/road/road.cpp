#include <bits/stdc++.h>
using namespace std;

int n, d, v[100010];
long long ans = 0;

struct oil
{
    int dir, nid, val;
} a[100010];

bool cmp1(oil x, oil y)
{
    if(x.val != y.val) return x.val < y.val;
    else return x.dir < y.dir;
}

bool cmp2(oil x, oil y)
{
    return x.dir < y.dir;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);

    cin>>n>>d;
    for(int i = 1; i < n; i++)
    {
        cin>>v[i+1];
    }
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i].val;
        a[i].dir = i;
    }
    sort(a+1, a+1+n, cmp1);
    for(int i = 1; i <= n; i++)
    {
        a[i].nid = i;
    }
    sort(a+1, a+1+n, cmp2);

    int nowdir = 1, nownid = a[1].nid, sy = 0;
    long long s = 0;
    for(int i = 2; i <= n; i++)
    {
        s += v[i];
        if(a[i].nid < nownid || a[i].dir == n)
        {
            if((s-sy) % d == 0)
            {
                ans += ((s-sy)/d) * a[nowdir].val;
                nowdir = a[i].dir;
                nownid = a[i].nid;
                sy = 0;
                s = 0;
            }
            else
            {
                ans += ((s-sy)/d + 1) * a[nowdir].val;
                nowdir = a[i].dir;
                nownid = a[i].nid;
                sy = d - ((s-sy) % d);
                s = 0;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}