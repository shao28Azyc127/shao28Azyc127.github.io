#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int t , x;

int gcd(int a , int b)
{
    if (a < b)
    {
        int tmp = b;
        b = a;
        a = tmp;
    }
    if (a % b == 0) return b;
    return gcd(b , a % b);
}

int main()
{
    freopen("uqe.in" , "r" , stdin);
    freopen("uqe.out" , "w" , stdout);
    scanf("%d%d" , &t , &x);
    while (t--)
    {
        int a , b , c;
        scanf("%d%d%d" , &a , &b , &c);
        b *= -1;
        int delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            printf("NO\n");
            continue;
        }
        if (floor(sqrt(delta)) == ceil(sqrt(delta)))
        {
            delta = sqrt(delta);
            if ((b + delta) / a / 2 > (b - delta) / a / 2) b += delta;
            else b -= delta;
            if (b % (2 * a) == 0)
            {
                printf("%d\n" , b / a / 2);
                continue;
            }
            int tmp = gcd(abs(b) , abs(2 * a));
            b /= tmp;
            a = 2 * a / tmp;
            if ((a > 0 && b > 0) || (a < 0 && b < 0)) printf("%d/%d\n" , abs(b) , abs(a));
            else printf("-%d/%d\n" , abs(b) , abs(a));
        }
        else
        {
            if (b % (2 * a) == 0) printf("%d+" , b / a / 2);
            else
            {
                int tmp = gcd(abs(b) , abs(2 * a));
                b /= tmp;
                a = 2 * a / tmp;
                if ((a > 0 && b > 0) || (a < 0 && b < 0)) printf("%d/%d+" , abs(b) , abs(a));
                else printf("-%d/%d+" , abs(b) , abs(a));
                a = a * tmp / 2;
            }
            int times = 1;
            for (int i = 2; i * i <= delta; i++)
            {
                int tmp = i * i;
                while (delta % tmp == 0)
                {
                    times *= i;
                    delta /= tmp;
                }
            }
            if (times == 1)
            {
                printf("sqrt(%d)/%d\n" , delta , a * 2);
                continue;
            }
            if (times % (2 * a) == 0)
            {
                times = times / 2 / a;
                if (times == 1) printf("sqrt(%d)\n" , delta);
                else printf("%d*sqrt(%d)\n" , times / a / 2 , delta);
                continue;
            }
            int tmp = gcd(times , abs(2 * a));
            times /= tmp;
            a = 2 * a / tmp;
            if (times == 1) printf("sqrt(%d)/%d\n" , delta , a);
            else printf("%d*sqrt(%d)/%d\n" , times , delta , a);
        }
    }

    return 0;
}
