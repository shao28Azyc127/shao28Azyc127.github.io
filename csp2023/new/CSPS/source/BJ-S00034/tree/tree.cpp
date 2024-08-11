#include <iostream>
#include <cstdio>
using namespace std;

int n, b[100007] = {}, c[100007] = {}, m[100007] = {}, day = 0, dis[100007] = {};
long long a[100007] = {}, d[100007] = {};

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cout << u << v;
        m[v] = 1;
    }
    day++;
    dis[1] = 1;
    d[1] += max(b[1] + c[1] ,1);
    while (true)
    {
        day++;
        dis[day] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i])
            {
                d[i] += max(b[i] + c[i] * day, 1);
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            if (d[i] < a[i])
            {
                flag = false;
                break;
            }
        }
        if (flag) break;
    }
    cout << day << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}