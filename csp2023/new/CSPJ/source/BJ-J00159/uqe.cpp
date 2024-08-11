#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    for (int l = 1; l <= t; ++l)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int tri = b * b - 4 * a * c;
        if (tri < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int x1 = (-b + sqrt(tri)) / 2 / a, x2 = (-b - sqrt(tri)) / 2 / a;
        cout << max(x1, x2) << endl;
    }
    return 0;
}
