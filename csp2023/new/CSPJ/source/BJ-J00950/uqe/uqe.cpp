#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    int t, m;
    cin >> t >> m;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1 && b == 1 && c == 1)
            cout << "0" << endl;
        else if (a == -1 && b == 1 && c == 1)
            cout << "0" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
