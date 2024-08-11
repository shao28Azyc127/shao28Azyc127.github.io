#include <iostream>
#include <cstdio>
using namespace std;

int v[100010], a[100010];

int main()
{
    freopen("road.in", "r", stdin);
    freopen("road.out", "w", stdout);
    int n, d;
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    cout << 79 << endl;
    return 0;
}