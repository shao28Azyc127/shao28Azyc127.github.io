#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[100010];

int NOT(int x)
{
    if (x == 100001) return 100002;
    if (x == 100002) return 100001;
    if (x == 100003) return 100003;
    return -x;
}

int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            a[i] = i;
        }
        for (int i = 1; i <= m; i++)
        {
            char v;
            scanf(" %c", &v);
            if (v == '+')
            {
                int x, y;
                scanf("%d%d", &x, &y);
                a[x] = y;
                while (a[x] <= 100000 && abs(a[abs(a[x])]) != abs(a[x]))
                {
                    if (a[x] > 0) a[x] = a[a[x]];
                    else a[x] = NOT(a[-a[x]]);
                }
            }
            else if (v == '-')
            {
                int x, y;
                scanf("%d%d", &x, &y);
                a[x] = -y;
                while (a[x] <= 100000 && abs(a[abs(a[x])]) != abs(a[x]))
                {
                    if (a[x] > 0) a[x] = a[a[x]];
                    else a[x] = NOT(a[-a[x]]);
                }
            }
            else
            {
                int id;
                scanf("%d", &id);
                if (v == 'T') a[id] = 100001;
                if (v == 'F') a[id] = 100002;
                if (v == 'U') a[id] = 100003;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == -i) a[i] = 100003;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            while (abs(a[abs(a[i])]) != abs(a[i]) && a[i] <= 100000)
            {
                if (a[i] > 0) a[i] = a[a[i]];
                else a[i] = NOT(a[-a[i]]);
            }
            if (a[abs(a[i])] < 0 || a[i] == 100003)
            {
                cnt++;
                //cout << a[i] << " ";
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
