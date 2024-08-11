#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;

int t, m, a, b, c;
int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin >> t >> m;
    for (int k = 1; k <= t; k++)
    {
        cin >> a >> b >> c;
        int s = b * b - 4 * a * c;
        if (s < 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (s == 0)
        {
            cout << (-b) / 2 * a << endl;
            continue;
        }
        cout << (-b + sqrt(s)) / 2 * a << endl;
    }
    return 0;
}
