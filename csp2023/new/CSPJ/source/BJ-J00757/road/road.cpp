#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int a[100005];
int main()
{
    freopen("road.in" , "r" , stdin);
    freopen("road.out" , "w" , stdout);
    int n , d , sum = 0;
    cin >> n >> d;
    for(int i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
        sum += a[i];
        cout << sum << "\n";
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int y = ceil(1.0 * sum / d);
    cout << a[1] * y;
    return 0;
}
