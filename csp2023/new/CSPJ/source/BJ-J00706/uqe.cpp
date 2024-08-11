#include <bits/stdc++.h>
using namespace std;

int t, m;

inline bool check(int a, int b, int c)
{
    int delta = b * b - 4 * a * c;
    return delta >= 0;
}

inline void get_ans(int a, int b, int c, int &x1, int &x2)
{
    int delta = b * b - 4 * a * c;
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
}

int main()
{
    ifstream cin("uqe.in");
    ofstream cout("uqe.out");
    ios::sync_with_stdio(false);

    cin >> t >> m;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (!check(a, b, c))
        {
            cout << "NO" << endl;
            continue;
        }

        int x1, x2;
        get_ans(a, b, c, x1, x2);
        cout << max(x1, x2) << endl;
    }
    return 0;
}