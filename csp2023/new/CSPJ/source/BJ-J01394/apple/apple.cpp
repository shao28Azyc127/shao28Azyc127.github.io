#include <iostream>
using namespace std;
int up(int n)
{
    double ans = n / 3.0;
    if (ans == n / 3) return n / 3;
    else return n / 3 + 1;
}
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin >> n;
    int n2 = n;
    int cur = 0;
    while (n != 0)
    {
        cur++;
        n -= up(n);
    }
    cout << cur << " ";
    cur = 0;
    while (n2 != 0)
    {
        cur++;
        if (n2 % 3 == 1)
        {
            cout << cur;
            break;
        }
        n2 -= up(n2);
    }


    return 0;
}