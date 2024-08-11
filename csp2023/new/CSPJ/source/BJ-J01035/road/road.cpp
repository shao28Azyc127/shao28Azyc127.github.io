#include <iostream>
#include <cmath>
using namespace std;
long long int n, d, minn = 99999999;
int p = -1;
int a[100000005], b[100000005];//a j b q
int minnn(long long int x)
{
    if (x == 1)
    {
        return 0;
    }
    long long int minmin = 9999999;
    for (int i = 1; i <= n; i++)
    {
        if (b[i] < minmin)
        {
            minmin = b[i];
        }
    }
    return minnn(minmin) + (x - minmin) * b[minmin];
}
int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin >> n >> d;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (b[i] < minn)
        {
            minn = b[i];
        }
    }
    if (b[1] == minn)
    {
        p = 1;
    }
    for (int i = 1; i <= n - 1; i++)
    {
        if(a[i] % d != 0)
        {
            p = 0;
        }
    }
    if (p == 1)
    {
        long long int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
        }
        if (sum % d == 0)
        {
            cout << sum / d * b[1];
        }
        else{
            cout << (sum / d + 1) * b[1];
        }
    }
    else if (p == -1)
    {
        cout << minnn(minn);
    }
    return 0;
}
