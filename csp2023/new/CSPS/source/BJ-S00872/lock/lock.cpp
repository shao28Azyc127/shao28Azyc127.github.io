#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct sec
{
    int a, b, c, d, e;
}a[10];
int main()
{
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d >> a[i].e;
    }
    if(n == 1)
    {
        cout << 81;
    }
    return 0;
}
