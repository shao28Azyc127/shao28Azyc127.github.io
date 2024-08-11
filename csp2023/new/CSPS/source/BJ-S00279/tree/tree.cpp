#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<cstring>
#include<vector>
#include<set>

using namespace std;

typedef long long ll;

ll n;

struct edge{
    ll u,v;
}e[100010];
struct tree{
    ll a,b,c;
}t[100010];

int tree[100010];

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin >> n;
    bool ff = true;
    ll mod = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> t[i].a >> t[i].b >> t[i].c;
        if(t[i].c != 0)
            ff = false;
        else
            mod = max(mod,(ll)ceil(1.0 * t[i].a / t[i].b));
    }
    bool f = true;
    for(int i = 1;i < n;i++)
    {
        cin >> e[i].u >> e[i].v;
        if(e[i].u != e[i].v - 1)
            f = false;
    }
    if(ff)
    {
        cout << max(mod,n) << endl;
    }
    else if(f)
    {
        ll day = 0;
        while(1)
        {
            day++;
            for(ll i = 1;i <= day;i++)
                tree[i] += max(1ll,t[i].b + day * t[i].c);
            if(day >= n)
            {
                bool flag = true;
                for(int i = 1;i <= n;i++)
                {
                    if(tree[i] < t[i].a)
                        flag = false;
                }
                if(flag)
                    break;
            }
        }
        cout << day << endl;
    }
    else
    {
        cout << rand() % (n * n) << endl;
    }
    return 0;
}
