#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    for (int i = 1; i <= T; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int d = b * b - (4 * a * c);
        if (d < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        double e = (1.0 * sqrt(1.0 * d) - 1.0 * b) * 1.0 / 2.0 / a;
        double f = (1.0 * b - 1.0 * sqrt(1.0 * d) - 2.0 * b) * 1.0 / 2.0 / a;
        if (e < f) cout << f << endl;
        else cout << e << endl;
    }
    return 0;
}