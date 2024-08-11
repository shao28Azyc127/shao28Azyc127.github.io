#include <bits/stdc++.h>
using namespace std;
double t, m, a, b, c, J1, j2;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c;
        if (b * b - 4 * a * c < 0)
        {
            cout << "NO";
        }
        else
        {
            J1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
            j2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
            if (J1 == j2)
            {
                cout << J1;
            }
            else
            {
                cout << (int)max(J1, j2);
            }
        }
        cout << endl;
    }
}
