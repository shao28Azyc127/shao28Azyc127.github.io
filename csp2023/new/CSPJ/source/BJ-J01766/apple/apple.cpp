#include <bits/stdc++.h>
using namespace std;

int n, day, ap, nd;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    ap = n;
    while(ap > 0)
    {
        day ++;
        if((ap-1) % 3 == 0 && nd == 0) nd = day;
        ap -= (ap-1) / 3 + 1;

    }
    cout << day << ' ' << nd;
    return 0;
}
