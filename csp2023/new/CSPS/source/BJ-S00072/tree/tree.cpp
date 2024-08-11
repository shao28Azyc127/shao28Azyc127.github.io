#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int n;
    cin >> n;
    long long s = 0;
    long long x, y, z;
    for(int i = 1; i <= n; i++)
    {
        cin  >> x >> y >> z;
        s += y;
    }
    s/=n;
    cout << int(s)+1;
    return 0;
}
