#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    while (b!=0)
    {
        int tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}
bool isprime(int n)
{
    for (int i=2;i*i<=n;i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
pair<int,int> ysfj(int n)
{
    int yin[10007];
    memset(yin,0,sizeof(yin));
    int zyin=1,pyin=1;
    for (int i=2;i*i<=n;i++)
    {
        if (isprime(i)&&n%i==0)
        {
            while(n%i==0)
            {
                yin[i]++;
                n/=i;
            }
            if (yin[i]>=2)
            {
                zyin*=i*(yin[i]/2);
            }
            if (yin[i]%2==1)
            {

                pyin*=i;
            }
        }
    }
    return make_pair(zyin,pyin);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    scanf("%d",&t);
    scanf("%d",&m);
    while (t--)
    {
        string sqr;
        int a,b,c;
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        int delta=b*b-4*a*c;
        if (delta<0)
        {
            printf("NO\n");
            continue;
        }
        double sqd=sqrt(delta);
        bool is_int=true,is_delta_prime=false;
        if (int(sqd)!=sqd)
        {
            is_int=false;
        }
        int q1=-b,q2,q22=-1,twoa=2*a;
        if (isprime(delta))
        {
            is_delta_prime=true;
        }
        if (!is_int)
        {
            if (!is_delta_prime)
            {
                pair<int,int> p=ysfj(delta);
                q2=p.first;
                q22=p.second;
            }
            else
            {
                q2=delta;
            }

        }
        else
        {
            q1=int(sqd)+q1;
        }

        if (q1%twoa==0&&q1/twoa!=0)
        {
            printf("%d",q1/twoa);
        }
        else
        {

            int gcd_q1=gcd(q1,twoa);
            if ((q1/gcd_q1<0&&twoa/gcd_q1>0)||(q1/gcd_q1>0&&twoa/gcd_q1<0))
            {
                 printf("-%d/%d",abs(q1/gcd_q1),abs(twoa/gcd_q1));
            }
            else if ((q1/gcd_q1<0&&twoa/gcd_q1<0)||(q1/gcd_q1>0&&twoa/gcd_q1>0))
            {
                printf("%d/%d",q1/gcd_q1,twoa/gcd_q1);

            }
        }
        if (!is_int)
        {
            if (q1/twoa!=0)
            {
                printf("+");
            }
            q2=q2/twoa;
            if (q2!=1&&int(q2)==q2)
            {
                printf("%d*",q2);
            }
            printf("sqrt(%d)",q22);


            if (q2!=1&&int(q2)!=q2&&int(1.0/(q2*1.0))==1.0/(q2*1.0))
            {
                printf("/%d",1/q2);
            }

        }
        printf("\n");
    }
    return 0;
}
