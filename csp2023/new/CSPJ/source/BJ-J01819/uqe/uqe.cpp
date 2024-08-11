#include<bits/stdc++.h>
using namespace std;
const long long MAXN=5e6+5;
const double lim=1e-8;
int T,M;
long long a,b,c;
void output(long long p,long long q)
{
    long long gcd=__gcd(p,q);
    p/=gcd,q/=gcd;
    if(q<0)
    {
        p=-p,q=-q;
    }
    if(q==1)
    {
        printf("%lld",p);
    }
    else
    {
        printf("%lld/%lld",p,q);
    }
    return;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d %d",&T,&M);
    while(T--)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        long long delta=b*b-4*a*c;
        if(delta<0)
        {
            printf("NO\n");
            continue;
        }
        else if(delta==0)
        {
            output(-b,2*a);
            printf("\n");
        }
        else if(delta>0)
        {
            if(abs(sqrt(delta)-(long long)sqrt(delta))<=lim)
            {
                long long p,p1=-b+sqrt(delta),p2=-b-sqrt(delta),q=2*a;
                if(q>0)
                {
                    p=max(p1,p2);
                }
                else
                {
                    p=min(p1,p2);
                }
                output(p,q);
                printf("\n");
            }
            else
            {
                long long p1=-b,q1=2*a;
                if(p1!=0)
                {
                    output(p1,q1);
                    printf("+");
                }
                long long q2=1,q3=abs(q1),r=delta;
                for(q2=ceil(sqrt(delta));q2>=2;q2--)
                {
                    if(delta%(q2*q2)==0)
                    {
                        r=delta/(q2*q2);
                        break;
                    }
                }
                long long gcd=__gcd(q2,q3);
                q2/=gcd,q3/=gcd;
                if(q2!=1)
                {
                    printf("%lld*",q2);
                }
                printf("sqrt(%lld)",r);
                if(q3!=1)
                {
                    printf("/%lld",q3);
                }
                printf("\n");
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
