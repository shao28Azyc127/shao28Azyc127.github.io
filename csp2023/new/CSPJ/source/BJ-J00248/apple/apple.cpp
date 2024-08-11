#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n, day = 0, dn = -1;
    cin >> n;
    while (n > 0)
    {
        day++;
        if ((n - 1) % 3 == 0 && dn == -1) dn = day;
        n -= 1 + (n - 1) / 3;
    }
    cout << day << " " << dn << endl;
    return 0;
}
