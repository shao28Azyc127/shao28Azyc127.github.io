#include <cstdio>
#include <iostream>
using namespace std;

long long n, cnt, ansn;
bool flag = false;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    while (n)
    {
        cnt++;
        if (n % 3 == 1 && !flag)
        {
            ansn = cnt;
            flag = true;
        }
        n = n - (n + 2) / 3;
    }
    cout << cnt << " " << ansn << endl;
    return 0;
}