#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, M;
    cin >> T >> M;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        int x1 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        int x2 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        cout << max(x1, x2) << endl;
    }
    return 0;
}
