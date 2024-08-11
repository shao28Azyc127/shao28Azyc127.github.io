#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
#define int long long

int l[100010], p[100010];
signed main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
   int n, d;
   cin >> n >> d;
   int sum = 0;
   for(int i = 1; i <= n - 1; i++)
   {
        cin >> l[i];
        sum += l[i];
   }
   for(int i = 1; i <= n; i++)
        cin >> p[i];
    cout << p[1] * ceil(1.0 * sum / d) << endl;
    return 0;
}
