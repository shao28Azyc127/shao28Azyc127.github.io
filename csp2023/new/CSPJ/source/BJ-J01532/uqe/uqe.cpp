#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
    if(x == y)
    {
        return x;
    }
    if(x > y)
    {
        x -= (x - y) / y * y;
    }
    else
    {
        y -= (y - x) / x * x;
    }
}
int main ()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    scanf("%d%d",&t,&m);
    int a,b,c;
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int d = b * b - 4 * a * c;
        if(d < 0)
        {
            printf("NO\n");
        }
        else
        {
            double linret1 = (-b + sqrt(d)) * 1.0 / 2,linret2 = (-b - sqrt(d)) * 1.0 / 2;
            double x = max(linret1,linret2);
            int p,q;
            for (q = 1;;q++)
            {
                if(x * q == floor(x * q))
                {
                    if(q == 1)
                    {
                        printf("%d",x);
                    }
                    else
                    {
                        printf("%d/%d",x * q,q);
                    }
                    p = x * q;
                }
            }
        }
    }
    return 0;
}
