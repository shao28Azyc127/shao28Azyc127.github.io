#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    long long n;
    cin >> n;
    long long x = n;
    int d = 0, nd = 0;
    if(n == 1)
    {
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    for(long long i = 1; ; i++)
    {
        if(x % 3 == 1 && nd == 0) nd = d+1;
        x -= (x-1)/3 + 1;
        d++;
        if(x == 0) break;
    }
    cout << d << " " << nd << endl;
    return 0;
}