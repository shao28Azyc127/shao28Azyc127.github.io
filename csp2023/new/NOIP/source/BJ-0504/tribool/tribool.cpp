#include <bits/stdc++.h>
using namespace std;

struct node
{
    char op;
    int x;
    int y;
}p[100005];

inline char neg(char x)
{
    if (x == 'T')
    {
        return 'F';
    }
    else if (x == 'F')
    {
        return 'T';
    }
    else
    {
        return 'U';
    }
}

int n, m, ans;
char a[100005], b[100005];

void dfs(int s, int cnt)
{
    if (s == n)
    {
        for (int i = 1; i <= n; i++)
        {
            b[i] = a[i];
        }
        for (int i = 1; i <= m; i++)
        {
            int op = p[i].op;
            int x = p[i].x;
            int y = p[i].y;
            if (op == '+')
            {
                b[x] = b[y];
            }
            else if (op == '-')
            {
                b[x] = neg(b[y]);
            }
            else
            {
                b[x] = op;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] != b[i])
            {
                return;
            }
        }
        ans = min(ans, cnt);
        return;
    }
    a[s + 1] = 'T';
    dfs(s + 1, cnt);
    a[s + 1] = 'F';
    dfs(s + 1, cnt);
    a[s + 1] = 'U';
    dfs(s + 1, cnt + 1);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(p, 0, sizeof(p));
        ans = 1e9;
        cin >> n >> m;
        if (c == 1 || c == 2)
        {
            for (int i = 1; i <= m; i++)
            {
                cin >> p[i].op >> p[i].x;
                char op = p[i].op;
                int x = p[i].x;
                if (op == '+' || op == '-')
                {
                    cin >> p[i].y;
                }
            }
            dfs(0, 0);
            cout << ans << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}