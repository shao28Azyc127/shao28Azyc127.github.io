#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int t, m;

void solve(int a, int b, int c)
{
    int k = b*b-4*a*c;
    if(k<0)
    {
        printf("NO\n");
    }
    else if(k>0)
    {
        int x = sqrt(k);
        if(sqrt(k)*sqrt(k)!=k)
        {
            if(b==0)
            {
                int y = 2*a;
                printf("sqrt(%d)/%d\n", k, y);
            }
            else
            {
                if(b%(2*a)==0)
                {
                    int y = -b/(2*a);
                    printf("%d+sqrt(%d)/%d\n", y, k, 2*a);
                }
                else
                {
                    int d = 2*a;
                    b /= __gcd(d, b);
                    d /= __gcd(d, b);
                    printf("%d/%d+sqrt(%d)/%d\n", -b, d, k, 2*a);
                }
            }
        }
        else
        {
            int y = sqrt(k);
            if(b==0)
            {
                if(y%(2*a)==0)
                {
                    printf("%d\n", y/(a*2));
                }
                else
                {
                    printf("%d\n", y/(a*2));
                }
            }
            else
            {
                if(y%(2*a)==0 && b%(2*a)==0)
                {

                    printf("%d\n", -b/(2*a)+y/(2*a));
                }
                else if(y%(2*a) && b%(2*a)==0)
                {
                    int d = 2*a;
                    y /= __gcd(d, y);
                    d /= __gcd(d, y);
                    printf("%d+%d/%d\n", -b/(a*2), y, d);
                }
                else if(y%(2*a)==0 && b%(2*a))
                {
                    int d = 2*a;
                    b /= __gcd(d, b);
                    d /= __gcd(d, b);
                    printf("%d/%d+%d\n", -b, d, y/(2*a));
                }
                else
                {
                    int d = 2*a;
                    int e = -b+y;
                    if(e==0)
                    {
                        printf("0\n");
                        return ;
                    }
                    e /= __gcd(d, e);
                    d /= __gcd(d, e);
                    printf("%d/%d\n", e, d);
                }
            }
        }
    }
    else
    {
        if(b%(2*a)==0)
        {
            int y = b/(2*a);
            printf("%d\n", y);
        }
        else
        {
            int d = 2*a;
            b /= __gcd(d, b);
            d /= __gcd(d, b);
            printf("%d/%d\n", -b, d);
        }
    }
}

int main()
{
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    scanf("%d%d", &t, &m);
    for(int i=1; i<=t; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        solve(a, b, c);
    }
    fclose(stdin);
    fclose(stdout);


    return 0;
}
