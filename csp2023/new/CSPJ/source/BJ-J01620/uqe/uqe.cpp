#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int t,m;

void print_youli(int x,int y)
{
    if(x % y == 0)
    {
        printf("%d",x / y);
        return ;
    }
    int k = max(x,y);
    for(int i=2;i<=sqrt(k);i++)
        while(x % i == 0 && y % i == 0)
        {
            x /= i;
            y /= i;
        }
    if(y < 0)
    {
        y = -y;
        x = -x;
    }
    printf("%d/%d",x,y);
    return ;
}

void huajian_print(int a,int b,int c)
{
    if(a == b)
    {
        printf("sqrt(%d)\n",c);
        return ;
    }
    if(a % b == 0)
    {
        printf("%d*sqrt(%d)\n",a / b,c);
        return;
    }
    if(b % a == 0)
    {
        printf("sqrt(%d)/%d\n",c,b / a);
        return;
    }
    int k = max(a,b);
    for(int i=2;i<=sqrt(k);i++)
        while(a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
        }
    printf("%d*sqrt(%d)/%d\n",a,c,b);
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&t,&m);
    while(t--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        int delta = b * b - 4 * a * c;#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int t,m;

void print_youli(int x,int y)
{
    if(x % y == 0)
    {
        printf("%d",x / y);
        return ;
    }
    int k = max(x,y);
    for(int i=2;i<=sqrt(k);i++)
        while(x % i == 0 && y % i == 0)
        {
            x /= i;
            y /= i;
        }
    if(y < 0)
    {
        y = -y;
        x = -x;
    }
    printf("%d/%d",x,y);
    return ;
}

void huajian_print(int a,int b,int c)
{
    if(a == b)
    {
        printf("sqrt(%d)\n",c);
        return ;
    }
    if(a % b == 0)
    {
        printf("%d*sqrt(%d)\n",a / b,c);
        return;
    }
    if(b % a == 0)
    {
        printf("sqrt(%d)/%d\n",c,b / a);
        return;
    }
    int k = max(a,b);
    for(int i=2;i<=sqrt(k);i++)
        while(a % i == 0 && b % i == 0)
        {
            a /= i;
            b /= i;
        }
    printf("%d*sqrt(%d)/%d\n",a,c,b);
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&t,&m);
    while(t--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);

        int delta = b * b - 4 * a * c;

        if(delta < 0)
        {
            printf("NO\n");
            continue;
        }

        int sqrt_delta = sqrt(delta);
        if(sqrt_delta * sqrt_delta == delta)
        {
            int x;
            int y = 2 * a;
            if(y > 0) x = max(sqrt_delta - b,-sqrt_delta - b);
            else x = min(sqrt_delta - b,-sqrt_delta - b);
            print_youli(x,y);
            printf("\n");
        }
        else
        {
            int q1_up = -b;
            int q1_dw = 2 * a;
            if(q1_up != 0)
            {
                print_youli(q1_up,q1_dw);
                printf("+");
            }

            int q2_up = 1;
            int q2_dw = max(-2 * a,2 * a);
            int r = delta;
            for(int i=2;i<=sqrt(r);i++)
                while(r % (i * i) == 0)
                {
                    r /= (i * i);
                    q2_up *= i;
                }
            huajian_print(q2_up,q2_dw,r);
        }
    }
    return 0;
}


        if(delta < 0)
        {
            printf("NO\n");
            continue;
        }

        int sqrt_delta = sqrt(delta);
        if(sqrt_delta * sqrt_delta == delta)
        {
            int x;
            int y = 2 * a;
            if(y > 0) x = max(sqrt_delta - b,-sqrt_delta - b);
            else x = min(sqrt_delta - b,-sqrt_delta - b);
            print_youli(x,y);
            printf("\n");
        }
        else
        {
            int q1_up = -b;
            int q1_dw = 2 * a;
            if(q1_up != 0)
            {
                print_youli(q1_up,q1_dw);
                printf("+");
            }

            int q2_up = 1;
            int q2_dw = max(-2 * a,2 * a);
            int r = delta;
            for(int i=2;i<=sqrt(r);i++)
                while(r % (i * i) == 0)
                {
                    r /= (i * i);
                    q2_up *= i;
                }
            huajian_print(q2_up,q2_dw,r);
        }
    }
    return 0;
}
