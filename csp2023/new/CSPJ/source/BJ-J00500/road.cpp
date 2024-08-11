#include <bits/stdc++.h>
#define N 10005
#define INF 0x7fffffff
int n, d, v[N], sum = 0, p;
using namespace std;

int main()
{
    freopen("bus.in", "r", stdin);
    freopen("bus.out", "w", stdout);
    cin >> n >> d;
    for (int i = 0; i < n; i++) cin >> v[i], sum += v[i];
    cin >> p;
    cout << ceil(sum/d*p);
    return 0;
}
