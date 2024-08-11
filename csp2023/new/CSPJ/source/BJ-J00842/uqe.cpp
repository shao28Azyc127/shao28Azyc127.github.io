#include <cstdio>
#include <iostream>
using namespace std;

int t, m, a, b, c;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0) cout << "NO" << endl;
        else cout << 0 << endl;
    }
    return 0;
}