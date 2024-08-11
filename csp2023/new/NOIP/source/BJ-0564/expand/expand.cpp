#include <iostream>
#include <cstdio>

using namespace std;

int c, n, m, q, kx, ky;
int x[10000000], y[10000000], px[500000], vx[500000], py[500000], vy[500000];

bool dfs1(int a)
{
    if (a >= n)
    {
        for (int i = a; i < m; i++)
        {
            if (x[n - 1] <= y[i])
            {
                return false;
            }
        }
        return true;
    }

    if (a >= m)
    {
        for (int i = a; i < n; i++)
        {
            if (x[i] <= y[n - 1])
            {
                return false;
            }
        }
        return true;
    }

    if (x[a] > y[a])
    {
        return dfs1(a + 1);
    }

    for (int i = 0; i < a; i++)
    {
        if (x[i] > y[a] && x[i] != x[i + 1])
        {
            bool flag = true;
            for (int j = i + 1; j < a; j++)
            {
                if (x[i] <= y[j])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                n += a - i;
                for (int j = n - 1; j > a; j--)
                {
                    x[j] = x[j - (a - i)];
                }
                if (dfs1(a + 1))
                {
                    for (int j = a + 1; j < n; j++)
                    {
                        x[j] = x[j + a - i];
                    }
                    n -= a - i;
                    return true;
                }
                for (int j = a + 1; j < n; j++)
                {
                    x[j] = x[j + a - i];
                }
                n -= a - i;
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        if (x[a] > y[i] && y[i] != y[i + 1])
        {
            bool flag = true;
            for (int j = i + 1; j < a; j++)
            {
                if (x[j] <= y[i])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                m += a - i;
                for (int j = m - 1; j > a; j--)
                {
                    y[j] = y[j - (a - i)];
                }
                if (dfs1(a + 1))
                {
                    for (int j = a + 1; j < m; j++)
                    {
                        y[j] = y[j + a - i];
                    }
                    m -= a - i;
                    return true;
                }
                for (int j = a + 1; j < m; j++)
                {
                    y[j] = y[j + a - i];
                }
                m -= a - i;
            }
        }
    }

    return false;
}

bool dfs2(int a)
{
    if (a >= n)
    {
        for (int i = a; i < m; i++)
        {
            if (x[n - 1] >= y[i])
            {
                return false;
            }
        }
        return true;
    }

    if (a >= m)
    {
        for (int i = a; i < n; i++)
        {
            if (x[i] >= y[n - 1])
            {
                return false;
            }
        }
        return true;
    }

    if (x[a] < y[a])
    {
        return dfs2(a + 1);
    }

    for (int i = 0; i < a; i++)
    {
        if (x[i] < y[a] && x[i] != x[i + 1])
        {
            bool flag = true;
            for (int j = i + 1; j < a; j++)
            {
                if (x[i] >= y[j])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                n += a - i;
                for (int j = n - 1; j > a; j--)
                {
                    x[j] = x[j - (a - i)];
                }
                if (dfs2(a + 1))
                {
                    for (int j = a + 1; j < n; j++)
                    {
                        x[j] = x[j + a - i];
                    }
                    n -= a - i;
                    return true;
                }
                for (int j = a + 1; j < n; j++)
                {
                    x[j] = x[j + a - i];
                }
                n -= a - i;
            }
        }
    }

    for (int i = 0; i < a; i++)
    {
        if (x[a] < y[i] && y[i] != y[i + 1])
        {
            bool flag = true;
            for (int j = i + 1; j < a; j++)
            {
                if (x[j] >= y[i])
                {
                    flag = false;
                }
            }
            if (flag)
            {
                m += a - i;
                for (int j = m - 1; j > a; j--)
                {
                    y[j] = y[j - (a - i)];
                }
                if (dfs2(a + 1))
                {
                    for (int j = a + 1; j < m; j++)
                    {
                        y[j] = y[j + a - i];
                    }
                    m -= a - i;
                    return true;
                }
                for (int j = a + 1; j < m; j++)
                {
                    y[j] = y[j + a - i];
                }
                m -= a - i;
            }
        }
    }

    return false;
}

void work(void)
{
    if (x[0] == y[0])
    {
        cout << 0;
    }
    else if (x[0] > y[0])
    {
        if (x[n - 1] <= y[m - 1])
        {
            cout << 0;
        }
        else
        {
            cout << dfs1(0);
        }
    }
    else if (x[0] < y[0])
    {
        if (x[n - 1] >= y[m - 1])
        {
            cout << 0;
        }
        else
        {
            cout << dfs2(0);
        }
    }
}

int main(void)
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);

    cin >> c >> n >> m >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> y[i];
    }
    work();
    while (q--)
    {
        int tmp;
        cin >> kx >> ky;
        for (int i = 0; i < kx; i++)
        {
            cin >> px[i] >> tmp;
            vx[i] = x[--px[i]];
            x[px[i]] = tmp;
        }
        for (int i = 0; i < ky; i++)
        {
            cin >> py[i] >> tmp;
            vy[i] = y[--py[i]];
            y[py[i]] = tmp;
        }

        work();
        for (int i = 0; i < kx; i++)
        {
            x[px[i]] = vx[i];
        }
        for (int i = 0; i < ky; i++)
        {
            y[py[i]] = vy[i];
        }
    }
    cout << endl;

    return 0;
}