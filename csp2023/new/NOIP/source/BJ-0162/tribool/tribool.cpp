#include <bits/stdc++.h>

#define x first
#define y second
#define mp make_pair

using namespace std;
const int N = 1e5 + 10;
typedef pair<int,int> PII;

int a[N], v[N], n, m, head[N], ver[2 * N], Next[2 * N], edge[2 * N], tot = 1, top, v2[N], v1[N], ans;
char str[2];
PII stk[N];
vector <int> G1;

void add(int x, int y, int z)
{
    ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

int dfs1(int x, int in_edge)
{
    v1[x] = 1;
    for(int i = head[x]; i; i = Next[i])
    {
        int y = ver[i], z = edge[i];
        if(i == (in_edge ^ 1)) continue;
        if(!v1[y])
        {
            stk[++top] = mp(x, z);
            int t = dfs1(y, i);
            if(t != -1) return t;
            top--;
        }
        else if(y == x) return z;
        else
        {
            int res = z;
            while(top)
            {
                res += stk[top].y;
                if(stk[top].x == y) break;
                top--;
            }
            return res;
        }
    }
    return -1;
}

void dfs2(int x)
{
    G1.push_back(x);
    v2[x] = 1;
    for(int i = head[x]; i; i = Next[i])
    {
        int y = ver[i];
        if(!v2[y]) dfs2(y);
    }
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int id, T;
    scanf("%d%d", &id, &T);
    while(T--)
    {
        ans = 0;
        tot = 1;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++) a[i] = i, head[i] = v1[i] = v2[i] = v[i] = 0;
        for(int i = 1; i <= m; i++)
        {
            int x, y;
            scanf("%s%d", str, &x);
            if(str[0] == 'T')
            {
                v[x] = 1, a[x] = 0;
            }
            else if(str[0] == 'U')
            {
                v[x] = 0, a[x] = 0;
            }
            else if(str[0] == 'F')
            {
                v[x] = -1, a[x] = 0;
            }
            else if(str[0] == '-')
            {
                scanf("%d", &y);
                if(a[y])
                {
                    a[x] = -a[y];
                }
                else
                {
                    a[x] = 0, v[x] = -v[y];
                }
            }
            else if(str[0] == '+')
            {
                scanf("%d", &y);
                if(a[y])
                {
                    a[x] = a[y];
                }
                else
                {
                    a[x] = 0, v[x] = v[y];
                }
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(a[i])
            {
                add(i, abs(a[i]), a[i] < 0), add(abs(a[i]), i, a[i] < 0);
            }
            else
            {
                if(!v[i]) ans++;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(!v2[i])
            {
                top = 0;
                int res = dfs1(i, 0);
                G1.clear();
                dfs2(i);
                if(res != -1)
                {
                    if(res & 1) ans += G1.size();
                }
                else
                {
                    for(auto& x : G1)
                    {
                        if(!a[x])
                        {
                            if(v[x] == 0)
                            {
                                ans += G1.size();
                                ans--;
                            }
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
