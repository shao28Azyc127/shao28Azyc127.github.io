#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

struct node
{
    int v, a;
} x[N];

bool cmp(node x, node y)
{
    return x.a < y.a;
}

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
        cin >> x[i].v;
    for (int i = 1; i <= n; i++)
        cin >> x[i].a;
    sort(x + 1, x + n, cmp);
    int ans = 0, p = 1, sum = 0;
    while (p != n)
    {
        if (sum < x[p].v)
        {
            while (sum < x[p].v)
            {
                sum += d;
                ans += x[p].a;
            }
        }
        sum -= x[p].v;
        p++;
    }
    cout << ans << endl;
    return 0;
}