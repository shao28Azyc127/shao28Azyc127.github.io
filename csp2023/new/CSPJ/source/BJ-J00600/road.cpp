#include <iostream>
#include <cmath>
using namespace std;

int v[100005], a[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    long long sum = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    cout << ceil(sum / d) * a[1] << endl;
    return 0;
}
