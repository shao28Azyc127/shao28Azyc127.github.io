#include <bits/stdc++.h>
using namespace std;

int T, m;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> T >> m;
    while(T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int t = b * b - 4 * a*c;
        if(t < 0)
        {
            cout << "NO\n";
            continue;
        }
        double a1, a2;
        a1 = (-b + sqrt(t)) / 2 / a;
        a2 = (-b - sqrt(t)) / 2 / a;
        cout << max(a1, a2) << endl;
    }
    return 0;
}