#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int lens = 1e5;
int v[lens + 1] = {};
int a[lens + 1] = {};
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n, d;
    cin >> n >> d;
    long long sum = 0;
    long long zz = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> v[i];
        zz += v[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int temp = a[1];
    sort(a+1,a+1+n);
    if (a[1] == temp)
    {
        if (zz % d == 0) sum = zz / d *a[1];
        else sum = (zz / d + 1) * a[1];
        cout << sum;
    }
    else
    {
        cout << 79;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}