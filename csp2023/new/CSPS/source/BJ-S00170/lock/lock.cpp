#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
using namespace std;

int a[10][10];

int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    if (n == 1)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        cout << 81 << endl;
    }
    else
    {
        int a[10][10];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= 5; j++)
            {
                cin >> a[i][j];
            }
        }
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            
        }
    }
    return 0;
}
