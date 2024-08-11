#include <bits/stdc++.h> //rp++

using namespace std;
typedef long long ll;
const int MAXN = 100002;

struct Node
{
    int l,r;
    ll v;
};

int c,t;
ll ans;
int n,m;
ll k,d;
int b[MAXN];
Node a[MAXN];

inline bool Check()
{
    int start = 0;
    for(register int i = 1;i <= n;++i)
    {
        if(b[i] == 1)
            start++;
        else
            start = 0;
        if(start > k)
            return false;
    }

    return true;
}

inline int Get()
{
    ll sss = 0;
    for(register int i = 1;i <= m;++i)
    {
        Node &cur = a[i];
        bool bbb = true;
        for(register int j = cur.l;j <= cur.r;++j)
        {
            if(b[j] == 2)
            {
                bbb = false;
                break;
            }
        }

        if(bbb)
            sss += cur.v;
    }

    return sss;
}

void Dfs(int step,ll sum)
{
    if(step == n + 1)
    {
        if(Check())
            ans = max(ans,sum + Get());
        return;
    }

    b[step] = 1;
    Dfs(step + 1,sum - d);
    b[step] = 2;
    Dfs(step + 1,sum);
    b[step] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> m >> k >> d;
        for(register int i = 1;i <= m;++i)
        {
            int x,y,v;
            cin >> x >> y >> v;
            a[i] = {x - y + 1,x,v};
        }
        
        Dfs(1,0);
        cout << ans << endl;
        ans = 0;
    }

    return 0;
}