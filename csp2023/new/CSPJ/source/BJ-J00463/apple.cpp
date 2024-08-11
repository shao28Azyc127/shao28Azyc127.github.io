#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
int n;
int main()
{
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    cin >> n;
    int d = - 1;
    int t = n;
    int rd = 0;
    while(t > 0)
    {
        if((t - 1) % 3 == 0 && d == -1)
            d = rd + 1;
        rd++;
        if(t < 3)
            t--;
        else
        {
            if(t % 3 == 0)
            {
                t -= t / 3;
            }
            else
            {
                t -= ((t / 3) + 1);
            }
        }
    }
    if(d == -1)
        d = rd;
    printf("%d %d\n", rd, d);
    return 0;
}
