#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t, m;
    cin >> t >> m;
    while (t--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long s = b * b - 4 * a * c;
        if (s < 0)
        {
            cout << "NO\n";
            continue;
        }
        long long x1 = (sqrt(s) - b) / (2 * a);
        long long x2 = (-sqrt(s) - b) / (2 * a);
        cout << max(x1, x2) << '\n';
    }
    return 0;
}
