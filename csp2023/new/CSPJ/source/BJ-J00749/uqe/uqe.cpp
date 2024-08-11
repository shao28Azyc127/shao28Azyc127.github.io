#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll t,m;
    scanf("%lld%lld",&t,&m);
    while(t--)
    {
        ll a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        ll derta=b*b-4*a*c;
        if(derta<0)
        {
            printf("NO\n");
            continue;
        }
        double ans1=((-b)+sqrt(derta))/(2*a);
        double ans2=((-b)-sqrt(derta))/(2*a);
        ll ansd1=ans1;
        ll ansd2=ans2;
        if(ansd1==ans1&&ansd2==ans2)
        {
            printf("%lld\n",max(ansd1,ansd2));
            continue;
        }
        if(derta==0)
        {
            ll shang=-b;
            ll xia=2*a;
            ll gcdsx=__gcd(abs(shang),abs(xia));
            shang/=gcdsx;
            xia/=gcdsx;
            if(xia==1)
            {
                printf("%lld\n",shang);
            }
            else
            {
                printf("%lld/%lld\n",shang,xia);
            }
        }
        else
        {
            ll shang1=-b;
            ll xia=2*a;
            ll shang2=derta;
            ll t=sqrt(shang2);
            if(t*t==shang2)
            {
                ll gcdsx=__gcd(abs(shang1),abs(xia));
                ll xiaa=xia;
                shang1/=gcdsx;
                xiaa/gcdsx;
                if(xiaa==1)
                {
                    printf("%lld+",shang1);
                    gcdsx=__gcd(abs(t),abs(xia));
                    xiaa=xia;
                    t/=gcdsx;
                    xiaa/gcdsx;
                    if(xiaa==1)
                    {
                        printf("%lld\n",t);
                    }
                    else
                    {
                        printf("%lld/%lld\n",t,xia);
                    }
                }
                else
                {
                    printf("%lld/%lld+",shang1,xia);
                    gcdsx=__gcd(abs(t),abs(xia));
                    xiaa=xia;
                    t/=gcdsx;
                    xiaa/gcdsx;
                    if(xiaa==1)
                    {
                        printf("%lld\n",t);
                    }
                    else
                    {
                        printf("%lld/%lld\n",t,xia);
                    }
                }
            }
            else
            {
                ll gcdsx=__gcd(abs(shang1),abs(xia));
                ll xiaa=xia;
                shang1/=gcdsx;
                xiaa/gcdsx;
                if(xiaa==1)
                {
                    if(shang1!=0)
                    {
                        printf("%lld+",shang1);
                    }
                    gcdsx=__gcd(abs(shang2),abs(xia));
                    xiaa=xia;
                    shang2/=gcdsx;
                    xiaa/gcdsx;
                    if(xiaa==1)
                    {
                        ll sq=0;
                        ll xian=sqrt(derta);
                        for (int i=2; i<=xian; i++)
                        {
                            ll fang=i*i;
                            if(derta%fang==0)
                            {
                                sq=i;
                            }
                        }
                        if(!sq)
                        {
                            printf("sqrt(%lld)\n",derta);
                        }
                        else
                        {
                            printf("%lld*sqrt(%lld)\n",sq,derta/(sq*sq));
                        }
                    }
                    else
                    {
                        printf("%lld/%lld",t,xia);
                        ll sq=0;
                        ll xian=sqrt(derta);
                        for (int i=2; i<=xian; i++)
                        {
                            ll fang=i*i;
                            if(derta%fang==0)
                            {
                                sq=i;
                            }
                        }
                        if(!sq)
                        {
                            printf("sqrt(%lld)/%lld\n",derta,xia);
                        }
                        else
                        {
                            printf("%lld*sqrt(%lld)/%lld\n",sq,derta/(sq*sq),xia);
                        }
                    }
                }
                else
                {
                    if(shang1!=0){
                        printf("%lld/%lld+",shang1,xia);
                    }
                    gcdsx=__gcd(abs(shang2),abs(xia));
                    xiaa=xia;
                    shang2/=gcdsx;
                    xiaa/gcdsx;
                    if(xiaa==1)
                    {
                        ll sq=0;
                        ll xian=sqrt(derta);
                        for (int i=2; i<=xian; i++)
                        {
                            ll fang=i*i;
                            if(derta%fang==0)
                            {
                                sq=i;
                            }
                        }
                        if(!sq)
                        {
                            printf("sqrt(%lld)\n",derta);
                        }
                        else
                        {
                            printf("%lld*sqrt(%lld)\n",sq,derta/(sq*sq));
                        }
                    }
                    else
                    {
                        printf("%lld/%lld",derta,xia);
                        ll sq=0;
                        ll xian=sqrt(derta);
                        for (int i=2; i<=xian; i++)
                        {
                            ll fang=i*i;
                            if(derta%fang==0)
                            {
                                sq=i;
                            }
                        }
                        if(!sq)
                        {
                            printf("sqrt(%lld)/%lld\n",derta,xia);
                        }
                        else
                        {
                            printf("%lld*sqrt(%lld)/%lld\n",sq,derta/(sq*sq),xia);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
