#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

const int NR = 1e5;
int n, m, ans = INT_MAX;
int x[NR], org[NR], num[NR][2];
char ope[NR];

int cal(int a)
{
    if (a == 2) return 2;
    if (a == 1) return 0;
    return 1;
}

void dfs1(int step)
{
    if (step > n)
    {
        memcpy(org, x, sizeof(x));
        for (int i = 1; i <= m; i++)
        {
            if (ope[i] == '+') x[num[i][0]] = x[num[i][1]];
            else if (ope[i] == '-') x[num[i][0]] = cal(x[num[i][1]]);
            else if (ope[i] == 'T') x[num[i][0]] = 1;
            else if (ope[i] == 'F') x[num[i][0]] = 0;
            else x[num[i][0]] = 2;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (x[i] != org[i])
            {
                memcpy(x, org, sizeof(x));
                return;
            }
            if (x[i] == 2) cnt++;
        }
        ans = min(ans, cnt);
        memcpy(x, org, sizeof(x));
        return;
    }
    x[step] = 0;
    dfs1(step + 1);
    x[step] = 1;
    dfs1(step + 1);
    x[step] = 2;
    dfs1(step + 1);
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while (t--)
    {
        memset(x, -1, sizeof(x));
        ans = INT_MAX;
        if (c == 1 || c == 2) // ±©ËÑ
        {
            cin >> n >> m;
            for (int i = 1; i <= m; i++)
            {
                cin >> ope[i];
                if (ope[i]  >= 'A' && ope[i] <= 'Z') cin >> num[i][0];
                else cin >> num[i][0] >> num[i][1];
            }
            dfs1(1);
            cout << ans << endl;
        }
        else if (c == 3 || c == 4) // Ö»ÓÐu
        {
            cin >> n >> m;
            for (int i = 1; i <= m; i++)
            {
                char op;
                int p;
                cin >> op >> p;
                if (op == 'U') x[p] = 2;
                else if (op == 'T') x[p] = 1;
                else x[p] = 0;
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++)
                if (x[i] == 2) cnt++;
            cout << cnt << endl;
        }
        else
        {
            cin >> n >> m;
            for (int i = 1; i <= m; i++)
            {
                cin >> ope[i];
                if (ope[i]  >= 'A' && ope[i] <= 'Z') cin >> num[i][0];
                else cin >> num[i][0] >> num[i][1];
            }
            dfs1(1);
            cout << ans << endl;
        }
    }

    return 0;
}

