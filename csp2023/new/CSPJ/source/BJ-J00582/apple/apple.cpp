#include <iostream>
#include <cstdio>

using namespace std;

int n, i, out;
bool flag;

int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    scanf("%d", &n);
    while(n)
    {
        i++;
        register int x = n / 3;
        if(n % 3 == 1 && !flag)
            out = i, flag = true;
        if(n % 3)
            x++;
        n -= x;
    }
    printf("%d %d", i, out);
    return 0;
}
