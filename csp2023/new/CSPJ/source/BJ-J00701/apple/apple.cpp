#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int cnt = 0;
    int g = 0;
    while(n > 0)
    {
        cnt ++;
        if(n % 3 == 1 && !g)
        {
            g = cnt;
        }
        int k = n / 3 + (bool)(n % 3);
        n -= k;
    }
    if(!g) g = cnt;
    printf("%d %d\n", cnt, g);
    return 0;
}
