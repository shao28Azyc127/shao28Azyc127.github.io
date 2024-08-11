#include <cstdio>
#include <cmath>
using namespace std;

int n;

int main()
{
    freopen("apple.in" , "r" , stdin);
    freopen("apple.out" , "w" , stdout);
    scanf("%d" , &n);
    int tmp = n;
    int r = 0;
    while (tmp)
    {
        tmp = tmp * 2 / 3;
        r++;
    }
    printf("%d " , r);
    int i = 0;
    while (1)
    {
        i++;
        if (n % 3 == 1)
        {
            printf("%d" , i);
            return 0;
        }
        n -= ceil(n * 1.0 / 3);
    }

    return 0;
}