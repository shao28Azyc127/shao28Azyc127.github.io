#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll totalans, nans, cnt;
bool flag = 0;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%lld",  &n);

    while (n) {
        cnt++;
        if (n % 3 == 1 && !flag) {
            flag = true;
            nans = cnt;
        }
        n -= (n - 1) / 3 + 1;
    }
    totalans = cnt;
    printf("%lld %lld", totalans, nans);
    return 0;
}

