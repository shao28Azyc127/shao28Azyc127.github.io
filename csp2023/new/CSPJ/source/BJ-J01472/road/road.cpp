#include <iostream>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    int v[n + 10],a[n + 10];
    int cnt = 0;
    for (int i = 1;i <= n - 1;i++)
    {
        cin >> v[i];
        cnt += v[i];
    }
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    cout << int(1.0 * cnt / d + 0.5) * a[1];
    return 0;
}
