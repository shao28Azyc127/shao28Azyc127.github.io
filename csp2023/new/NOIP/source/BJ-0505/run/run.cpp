#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MR = 1e5 + 10;

struct Node
{
    long long x, y, v, tv;
}a[MR];

int main()
{
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {
        int n, m;
        long long k, d, maxx = -1e18;
        cin >> n >> m >> k >> d;
        for(int i = 1; i <= m; i++)
        {
            cin >> a[i].x >> a[i].y >> a[i].v;
            a[i].tv = a[i].v - d * a[i].y;
            if(a[i].y <= k) maxx = max(maxx, a[i].tv);
        }
        cout << maxx << endl;
    }
    return 0;
}
