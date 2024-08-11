#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int T, m;
    cin >> T >> m;
    while (T--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int x = b * b - 4 * a * c;
        if (x < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (pow(sqrt(x), 2) == x)
        {
            int ans1 = (-b + sqrt(x)) / (2 * a);
            int ans2 = (-b - sqrt(x)) / (2 * a);
            if (ans1 != 0 && ans2 != 0)
            {
                int temp = gcd(ans1, ans2);
                if (ans1 >= ans2) cout << (b + sqrt(x)) / temp;
                else cout << (-b - sqrt(x)) / temp;
            }
            else
            {
                if (ans1 >= ans2) cout << (b + sqrt(x));
                else cout << (-b - sqrt(x));
            }
            if (2 * a != 1 && max(ans1, ans2) != 0) cout << "/" << 2 * a;
            cout << endl;
            continue;
        }
    }
    return 0;
}
