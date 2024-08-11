#include <iostream>
#include <cstring>
using namespace std;
int t, n, m, a, b, value[100005], cnt;
bool c[100005];
char v;
inline int code(char s)
{
    if (s == 'T')
        return n + 1;
    else if (s == 'F')
        return -n - 1;
    else
        return 0;
}
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin >> t >> t;
    while (t--)
    {
        cin >> n >> m;
        memset(c, false, sizeof(c));
        cnt = 0;
        for (int i = 1; i <= n; i++)
            value[i] = i;
        for (int i = 1; i <= m; i++)
        {
            cin >> v;
            if (v == '+')
            {
                cin >> a >> b;
                value[a] = value[b];
            }
            else if (v == '-')
            {
                cin >> a >> b;
                value[a] = -value[b];
            }
            else
            {
                cin >> a;
                value[a] = code(v);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (value[i] == -i)
                value[i] = 0;
            if (value[i] == i)
                c[i] = true;
        }
        for (int i = 1; i <= n; i++)
        {
            while (value[i] && abs(value[i]) < i && !c[abs(value[i])])
            {
                if (value[i] > 0)
                    value[i] = value[value[i]];
                else
                    value[i] = -value[-value[i]];
            }
            if (value[i] == -i)
                value[i] = 0;
            if (value[i] == i)
                c[i] = true;
        }
        for (int i = n; i >= 1; i--)
        {
            while (value[i] && abs(value[i]) <= n && abs(value[i]) != i && !c[abs(value[i])])
            {
                if (value[i] > 0)
                    value[i] = value[value[i]];
                else
                    value[i] = -value[-value[i]];
            }
            if (value[i] == -i)
                value[i] = 0;
            if (value[i] == i)
                c[i] = true;
        }
        for (int i = 1; i <= n; i++)
            if (value[i] == 0)
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}
