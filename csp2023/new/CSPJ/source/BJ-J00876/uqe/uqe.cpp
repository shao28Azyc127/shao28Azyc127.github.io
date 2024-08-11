#include<cstdio>
#include<cmath>
using namespace std;

int t,a,b,c,j3,j2;

int gcd(int x,int y)
{
    int t;
    if(y>x)
    {
        t=y;
        y=x;
        x=t;
    }
    while(x%y!=0)
    {
        x%=y;
        t=y;
        y=x;
        x=t;
    }
    return y;
}

void printd(int x,int y)
{

    if(y<0)
    {
        x=-x;
        y=-y;
    }
    if(x%y==0)
        printf("%d",x/y);
    else
    {
        printf("%d/%d",x/gcd(x,y),y/gcd(x,y));
    }
    return;
}


int main()
{
    freopen(uqe.in,'r',stdin);
    freopen(uqe.out,'w',stdout);
    int T,M;
    scanf("%d%d",&T,&M);
    for(int i = 1;i<=T;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        t=b*b-4*a*c;
        j3=int(-b+sqrt(t));
        j2=int(-b-sqrt(t));
        if(t<0)
            printf("NO");
        else if(t==0)
        {
            if(int(sqrt(t))*int(sqrt(t))==t)
            {
                printd(j3,2*a);
            }
            else
            {
                printf("NO");
            }
        }
        else
        {
            if(int(sqrt(t))*int(sqrt(t))==t)
            {
                if(j3*1.0/(2*a)>j2*1.0/(2*a))
                {
                    printd(j3,2*a);
                }
                else
                {
                    printd(j2,2*a);
                }
            }
            else
            {
            printf("NO");
            }
        }
    }
    return 0;
}
