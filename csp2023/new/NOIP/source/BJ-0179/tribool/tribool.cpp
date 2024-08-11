#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std; 

#define N 100000 + 10
#define T 'T'
#define F 'F'
#define U 'U'
#define undefine 'u'

struct tribool
{
    char v;

    inline void operator=(char a)
    {
        v = a;
    }

    inline bool operator==(char a)
    {
        return v == a;
    }

    inline bool operator!=(tribool a)
    {
        return v != a.v;
    }

    inline tribool operator-()
    {
        if (v == T)
            return (tribool){F};
        if (v == F)
            return (tribool){T};
        if (v == U)
            return (tribool){U};
        return (tribool){undefine};
    }
};

int n, m;
char v[N];
int a[N], b[N];
tribool x[N], y[N];
int ans = 1e9;

inline bool judge()
{
    for (int i = 1; i <= m; i++)
        if (v[i] == '+')
            y[a[i]] = x[b[i]];
        else if (v[i] == '-')
            y[a[i]] = -x[b[i]];
        else
            y[a[i]] = v[i];
    for (int i = 1; i <= n; i++)
        if (x[i] != y[i])
            return false;
    return true;
}

void dfs(int i)
{
    if (i > n)
    {
        if (judge())
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (x[i] == U)
                    cnt++;
            ans = min(ans, cnt);
        }
        return;
    }
    x[i] = T;
    dfs(i + 1);
    x[i] = F;
    dfs(i + 1);
    x[i] = U;
    dfs(i + 1);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    int c, t;
    scanf("%d%d", &c, &t);
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            cin >> v[i];
            if (v[i] == '+' || v[i] == '-')
                scanf("%d%d", &a[i], &b[i]);
            else
                scanf("%d", &a[i]);
        }

        if (c == 1 || c == 2)
        {
            ans = 1e9;
            dfs(1);
            printf("%d\n", ans);
            continue;
        }

        for (int i = 1; i <= m; i++)
            if (v[i] == T || v[i] == F || v[i] == U)
                x[a[i]] = v[i];

        if (c == 3 || c == 4)
        {
            int ans = 0;
            for (int i = 1; i <= n; i++)
                if (x[i] == U)
                    ans++;
            printf("%d\n", ans);
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}