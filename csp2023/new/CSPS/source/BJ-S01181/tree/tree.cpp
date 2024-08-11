#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 1e5 + 10;
int n, a[NR], b[NR], c[NR];
vector <int> adj[NR];
bool vis[NR];


//----------------alpha
int ans = 0, req[NR];

struct nodealp
{
    int u, treq;
    bool operator <(const nodealp &p) const
    {
        if(treq != p.treq)
        {
            return treq < p.treq;
        }
        return u > p.u;
    }
};

void bfsalpha()
{
    priority_queue <nodealp> q;
    q.push((nodealp){1, req[1]});
    int clk = 0;
    while(!q.empty())
    {
        nodealp u = q.top();
        q.pop();
        clk++;
        ans = max(ans, clk + u.treq - 1);
        vis[u.u] = true;
        for(int i = 0; i < adj[u.u].size(); i++)
        {
            int v = adj[u.u][i];
            if(!vis[v])
            {
                q.push((nodealp){v, req[v]});
            }
        }
    }
}

void workalpha()
{
    for(int i = 1; i <= n; i++)
    {
        int tmp = max(b[i], 1ll);
        req[i] = (a[i] + tmp - 1) / tmp;
    }
    bfsalpha();
    cout << ans << endl;
}

//---------------calc

inline int fndbrkpnt(int num)
{
    if(c[num] >= 0)
    {
        return 2147483647;
    }
    else
    {
        return (b[num] + (abs(c[num])) - 1) / (abs(c[num]));
    }
}

bool checkcalc(int endd, int num, int strt)
{
    if(strt > endd) return -1;
    int res = 0;
    if(endd >= fndbrkpnt(num))
    {
        int tmp = endd - max(strt, fndbrkpnt(num)) + 1;
        res += tmp;
        endd = fndbrkpnt(num) - 1;
    }
    if(strt > endd)
    {
        return res;
    } 
    res += (endd - strt + 1) * b[num];
    int res2;
    if((strt * c[num] + endd * c[num]) & 1)
    {
        res2 = (endd - strt + 1) / 2 * (strt * c[num] + endd * c[num]);
    }
    else
    {
        res2 = (strt * c[num] + endd * c[num]) / 2 * (endd - strt + 1);
    }
    //cout << "KEYY " << fndbrkpnt(4) << " " << res << " " << res2 << "YYEK" << endl;
    return res + res2 >= a[num];
}

int calc(int strt, int num) // mind that calc is o(nlogn)
{
    int l = strt, r = a[num] + strt + 100, mid;
    while(l < r)
    {
        //cout << "calc " << mid << endl;
        mid = (l + r) >> 1;
        if(checkcalc(mid, num, strt))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return r;
}

//-----------------bravo

set <int> avabravo;
int fa[NR];

void initbravo(int u, int fu)
{
    fa[u] = fu;
    for(int i = 0; i < adj[u].size(); i++)
    {
        if(adj[u][i] != fu)
        {
            initbravo(adj[u][i], u);
        }
    }
}

void dfsbravo(int u, int res, int dfn)
{
    dfn++;
    if(res > ans)
    {
        return;
    }
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(!vis[v])
        {
            avabravo.insert(v);
        }
    }
    res = max(res, calc(dfn, u));
    if(dfn >= n)
    {
        //cout << "tst " << u << " " << res << endl;
        ans = min(ans, res);
        return;
    }
    for(set<int>::iterator it = avabravo.begin(); it != avabravo.end(); it++)
    {
        int v = *it;
        if(!vis[v])
        {
            vis[v] = true;
            //cout << "psp " << u << " " << v << endl;
            dfsbravo(v, res, dfn);
            vis[v] = false;
        }
    }
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(v != fa[v])
        {
            avabravo.erase(v);
        }
    }
}

void workbravo()
{
    initbravo(1, 1);
    ans = 2147483647;
    vis[1] = true;
    dfsbravo(1, 0, 0);
    cout << ans << endl;
}

//charlie

void dfscharlie(int u, int res, int dfn, int fa)
{
    dfn++;
    res = max(res, calc(dfn, u));
    if(dfn >= n)
    {
        ans = res;
        return;
    }
    for(int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];;
        if(v != fa)
        {
            dfscharlie(v, res, dfn, u);
        }
    }
}

void workcharlie()
{
    dfscharlie(1, 0, 0, 1);
    cout << ans << endl;
}

signed main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    bool casealpha = true;
    bool casebravo = true;
    bool casecharlie = true;
    bool casedelta = true;
    bool caseecho = true;
    cin >> n;
    if(n > 20)
    {
        casebravo = false;
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
        if(c[i] != 0)
        {
            casealpha = false;
        }
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if(u != i && v != i + 1)
        {
            casecharlie = false;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        if(adj[i].size() > 2)
        {
            casedelta = false;
            break;
        }
    }
    if(casealpha)
    {
        workalpha();
    }
    else if(casebravo)
    {
        //cerr << "TST " << calc(3, 1) << endl;
        //cout << "KEY " << checkcalc(5, 4, 3) << endl;
        //cerr << "KLM " << calc(1, 1) << " " << calc(2, 3) << " " << calc(3, 4) << " " << calc(4, 2) << endl;
        workbravo();
    }
    else if(casecharlie)
    {
        workcharlie();
    }
    else if(casedelta)
    {
        workbravo();
    }
    /*else if(caseecho)
    {

    }*/
    else
    {
        workbravo();
    }
    return 0;
}