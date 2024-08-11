#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int v[100005], a[100005];
int minplace[100005];//minplace[i] = the station with the lowest price before(within) i
int minprice[100005];
int nextplace[100005];//nextplace[i] = the next minplace after i
long long s[100005];//qianzhuihe
//bool newplace[100005];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d, D = 0, OIL = 0;
    minprice[0] = 1e9;
    cin>>n>>d;
    for (int i = 1; i < n; i++)
    {
        cin >> v[i];
        s[i] = s[i - 1] + v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] < minprice[i - 1])
        {
            minplace[i] = i;
            //newplace[i] = true;
        }
        else minplace[i] = minplace[i - 1];
        minprice[i] = min(minprice[i - 1], a[i]);
    }
    nextplace[n] = n;
    for (int i = n - 1; i >= 0; i--)
    {
        if (minplace[i] != minplace[i + 1])nextplace[i] = i;
        else nextplace[i] = nextplace[i + 1];
    }
    long long money = 0, tank = 0;
    for (int i = 1; i <= n; i++)
    {
        if (minplace[i] != minplace[i - 1])
        {
            long long dis = s[nextplace[i]] - s[i];
            long long gas_ = ceil(1.0 * dis / d) - (tank / d);
            money += gas_ * a[i];
            tank += gas_ * d;
        }
        tank -= v[i];
    }
    cout << money << endl;
    return 0;
}
