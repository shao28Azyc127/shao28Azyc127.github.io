#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("road.in", r, stdin);
    freopen("road.out", w, stdout);
    int n, d;
    cin >> n >> d;
    int v[n - 1], a[n];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int sum = 0, cost = 0, way = 0;
    while (way != n - 1)
    {
        for (int i = way; i < n; i++)
        {
            if (a[i] < a[way] || i == n - 1)
            {
                int vi = 0;
                for (int j = way; j < i; j++)
                {
                    vi += v[j];
                }
                way = i;
                cost += ceil((float)(vi - sum) / d) * a[i];
                sum += ceil((float)(vi - sum) / d) * d - vi;
                break;
            }
        }
    }
    cout << cost << endl;
    return 0;
}