#include <bits/stdc++.h>
using namespace std;
int T,m,a,b,c;
void print(int p,int q)
{
    int ap = abs(p),aq = abs(q);
    int k = __gcd(ap,aq);
    p /= k,q /= k;
    if(q < 0) q = -q,p = -p;
    if(q == 1) printf("%d",p);
    else printf("%d/%d",p,q);
    return ;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    scanf("%d%d",&T,&m);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int delta = b * b - 4 * a * c;
        if(delta < 0)
        {
            printf("NO\n");
            continue;
        }
        int sq_delta = sqrt(delta);
        if(sq_delta * sq_delta == delta)
        {
            if(a < 0) print(-b - sq_delta,2 * a);
            else print(-b + sq_delta,2 * a);
            putchar('\n');
            continue;
        }
        if(b != 0) print(-b,2 * a),putchar('+');
        int x = 1;
        for(int i = sq_delta;i >= 1;i--)
        {
            if(delta % (i * i) == 0) x *= i,delta /= (i * i);
        }
        if(2 * a < 0) a = -a;
        if(2 * a == x)
        {
            printf("sqrt(%d)",delta);
            printf("\n");
            continue;
        }
        if(x % (2 * a) == 0)
        {
            printf("%d*sqrt(%d)",x / (2 * a),delta);
            printf("\n");
            continue;
        }
        if((2 * a) % x == 0)
        {
            printf("sqrt(%d)/%d",delta,2 * a / x);
            printf("\n");
            continue;
        }
        int k = __gcd(2 * a,x);
        int t1 = 2 * a / k,t2 = x / k;
        printf("%d*sqrt(%d)/%d",t2,delta,t1);
        printf("\n");
    }
    return 0;
}
