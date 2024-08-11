#include<cstdio>
#include<iostream>
using namespace std;
long long gcd(long long x,long long y)
{
    if (y == 0) return x;
    return gcd(y,x % y);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    long long M;
    scanf("%d%lld",&t,&M);
    while(t--)
    {
        long long a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        //a1/a2+b1*sqrt(r)/b2
        //if(XX != 1) print
        long long a1,a2,b1,b2,d,r;
        a1 = -b;
        a2 = 2 * a;
        b2 = 2 * a;
        long long derta = b * b - 4 * a * c;
        if (derta < 0)
        {
            printf("NO\n");
            continue;
        }
        r = derta;
        d = 1;
        for (int i = 2;i * i <= derta;i++)
            while (r % (i * i) == 0)
            {
                d *= i;
                r /= (i * i);
            }
        b1 = d;
        if (a2 < 0) a1 = -a1,a2 = -a2;
        if (b2 < 0) b1 = -b1,b2 = -b2;
        if (b1 < 0) b1 = -b1;
        long long tmp;
        if (r == 1)
        {
            long long x = a1 + b1,y = a2;
            tmp = gcd(abs(x),abs(y));
            x /= tmp;
            y /= tmp;
            if (y < 0) x = -x,y = -y;
            printf("%lld",x);
            if (y != 1) printf("/%lld",y);
            printf("\n");
            continue;
        }
        tmp = gcd(abs(a1),abs(a2));
        a1 /= tmp;
        a2 /= tmp;
        tmp = gcd(abs(b1),abs(b2));
        b1 /= tmp;
        b2 /= tmp;
        if (r == 0)
        {
            printf("%lld",a1);
            if (a2 != 1) printf("/%lld",a2);
            printf("\n");
            continue;
        }
        if (a1 != 0)
        {
            printf("%lld",a1);
            if (a2 != 1) printf("/%lld",a2);
            printf("+");
        }
        if (b1 != 1) printf("%lld*",b1);
        printf("sqrt(%lld)",r);
        if (b2 != 1) printf("/%lld",b2);
        printf("\n");
    }
}
