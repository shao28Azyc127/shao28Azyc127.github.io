#include <iostream>
#include <cstdio>

using namespace std;

int c, t, n, m, ans;
int start[100001], End[100001], fa[100001];  // T: -1; F: -2; U: -3
bool Not[100001], vis[100001];

int find(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return find(fa[x]);
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    fa[x] = y;
}

void read(void)
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        start[i] = Not[i] = 0;
        End[i] = i;
    }
    ans = 0;

    while (m--)
    {
        char v;
        int i, j;
        cin >> v;
        switch (v)
        {
            case 'T':
                cin >> i;
                End[i] = -1;
                break;

            case 'F':
                cin >> i;
                End[i] = -2;
                break;

            case 'U':
                cin >> i;
                End[i] = -3;
                break;

            case '+':
                cin >> i >> j;
                End[i] = End[j];
                Not[i] = Not[j];
                break;

            case '-':
                cin >> i >> j;
                if (End[j] > 0)
                {
                    End[i] = End[j];
                    Not[i] = !Not[j];
                }
                else if (End[j] == -1)
                {
                    End[i] = -2;
                }
                else if (End[j] == -2)
                {
                    End[i] = -1;
                }
                else
                {
                    End[i] = -3;
                }
                break;
        }
    }
}

void init(void)
{
    for (int i = 1; i <= n; i++)
    {
        if (End[i] < 0)
        {
            start[i] = End[i];
            if (End[i] == -3)
            {
                ans++;
            }
        }
        else if (End[i] == i)
        {
            if (Not[i])
            {
                start[i] = -3;
                ans++;
            }
            else
            {
                start[i] = -1;
            }
        }
    }
}

void work(void)
{
    int cnt;
    do
    {
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (start[i] == 0 && start[End[i]] < 0)
            {
                if (Not[i])
                {
                    switch (start[End[i]])
                    {
                        case -1:
                            start[i] = -2;
                            break;

                        case -2:
                            start[i] = -1;
                            break;

                        case -3:
                            start[i] = -3;
                            ans++;
                            break;
                    }
                }
                else
                {
                    start[i] = start[End[i]];
                    if (start[i] == -3)
                    {
                        ans++;
                    }
                }
                cnt++;
                vis[i] = true;
            }
        }
    } while (cnt != 0);
}

bool check(int x)
{
    int y = End[x];
    if (Not[x])
    {
        if (start[y] == -1)
        {
            return start[x] == -2;
        }
        else if (start[y] == -2)
        {
            return start[x] == -1;
        }
        else
        {
            return start[x] == -3;
        }
    }
    else
    {
        if (start[y] == -1)
        {
            return start[x] == -1;
        }
        else if (start[y] == -2)
        {
            return start[x] == -2;
        }
        else
        {
            return start[x] == -3;
        }
    }
}

int main(void)
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    cin >> c >> t;
    while (t--)
    {
        read();
        init();
        work();

        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            if (End[i] > 0)
            {
                merge(i, End[i]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            if (fa[i] == i && start[i] == 0)
            {
                int tmp, minp = 0, mans;
                for (int j = 1; j <= n; j++)
                {
                    vis[j] = false;
                }
                tmp = ans;
                start[i] = -1;
                work();
                if (check(i))
                {
                    minp = -1;
                    mans = ans;
                }
                for (int j = 1; j <= n; j++)
                {
                    if (vis[j])
                    {
                        start[j] = 0;
                    }
                }
                ans = tmp;
                start[i] = -2;
                work();
                if (check(i))
                {
                    if (minp == 0)
                    {
                        minp = -2;
                        mans = ans;
                    }
                    else if (ans < mans)
                    {
                        minp = -2;
                        mans = ans;
                    }
                }
                for (int j = 1; j <= n; j++)
                {
                    if (vis[j])
                    {
                        start[j] = 0;
                    }
                }
                ans = tmp + 1;
                start[i] = -3;
                work();
                if (check(i))
                {
                    if (minp == 0)
                    {
                        minp = -3;
                        mans = ans;
                    }
                    else if (ans < mans)
                    {
                        minp = -3;
                        mans = ans;
                    }
                }

                for (int j = 1; j <= n; j++)
                {
                    if (vis[j])
                    {
                        start[j] = 0;
                    }
                }
                ans = tmp;
                start[i] = minp;
                work();
                ans += (minp == -3);
            }
        }

        cout << ans << endl;
    }

    return 0;
}