#include<cstdio>
#include<cmath>
using namespace std;

long long n,len = 1,num = 1,tm = 0;

int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%lld",&n);

    while(num <= n)
    {
        num = ceil(num * 1.5);
        tm++;
    }

    while(n > 1 && n % 3 != 1)
    {
        n = n - (n + 1) / 3;
        len++;
    }

    printf("%lld %lld",tm,len);
    return 0;
}