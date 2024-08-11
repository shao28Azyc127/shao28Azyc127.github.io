#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d,nothing,goal = 0,cost = 0;
    cin >> n >> d;
    int v[n + 1] = {0}, a[n + 1] = {0};
    for(int i = 2; i <= n; i++)
    {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ep = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i == n) break;
        goal = n;
        for (int j = i + 1; j = n; j++)
        {
            if(a[j] <= a[i])
            {
                goal = j;
                j = n + 1;
            }
        }
        cost += (v[goal] - v[i] - ep + d - 1) / d * a[i];
        ep += (v[goal] - v[i] - ep + d - 1) / d * d - v[goal] + v[i];
        i = goal - 1;
    }
    cout << cost;
    return 0;
}