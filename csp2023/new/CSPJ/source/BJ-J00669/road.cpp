#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 1e5 + 10;
int n;
long long d, a[MAXN], v[MAXN];
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> d;
    for (int i = 1; i < n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long sum = 0;
    for (int i = 1; i < n; i++)
        sum += v[i];
    cout << (sum + d - 1) / d * a[1] << endl;
    return 0;
}
