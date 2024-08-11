#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    int num = 0, tmp = n, f = 1, ans = 1;
    while (tmp != 0)
    {
        num++;
        if (tmp % 3 == 1 && f)
        {
            f = 0;
            ans = num;
        }
        tmp -= (int)(tmp / 3.0 + 0.999);
    }
    printf("%d %d", num, ans);
    return 0;
}
