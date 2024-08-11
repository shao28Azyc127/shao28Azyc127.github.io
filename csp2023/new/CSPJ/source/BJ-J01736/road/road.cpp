#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    int v[10000], a[10000];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    int money = 0;
    double oil = 0;
    int i = 0, distance;
    while (i < n - 1)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (a[j] < a[i])
            {
                for (int z = i; z < j; z++)
                {
                    distance += v[z];
                }
                if ((distance - oil *d) % d == 0)
                {
                    money += (distance - oil * d) / d  * a[i];
                }
                else
                {
                    money += ((distance - oil * d) / d + 1) * a[i];
                    oil += (distance - oil * d) / d + 1(int) - (distance - oil * d) / d;
                }
                i = j;
            }
            if (j == n - 1 && i != j)
            {
                for (int z = i; z < n - 1; z++)
                {
                    distance += v[z];
                }
                if ((distance - oil *d) % d == 0)
                {
                    money += (distance - oil * d) / d  * a[i];
                }
                else
                {
                    money += ((distance - oil * d) / d + 1) * a[i];
                    oil += (distance - oil * d) / d + 1(int) - (distance - oil * d) / d;
                }
                i = j;
            }
        }
    }
    cout << money;
    return 0;
}