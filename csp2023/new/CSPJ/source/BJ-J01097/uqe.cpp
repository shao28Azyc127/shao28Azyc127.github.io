#include <bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
    int x=0,f=1;
    char c=getchar();
    while (!isdigit(c))
    {
        if (c=='-')
        {
            f=-1;
        }
        c=getchar();
    }
    while (isdigit(c))
    {
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int T,M;
signed main()
{
	freopen("uqe.in","r",stdin);
	freopen("uqe.out","w",stdout);
	T=read();
	M=read();
	while (T--)
	{
		int a,b,c;
		a=read();
		b=read();
		c=read();
		int sump=0,sumq=1;
		int delta=b*b-4*a*c;
		if (delta<0)
		{
			printf("NO\n");
		}
		else if (delta==0)
		{
			if (b==0)
			{
				printf("0\n");
				continue;
			}
			int q1p=-1*b,q1q=2*a;
			int g=__gcd(q1p,q1q);
			q1p/=g;
			q1q/=g;
			if (q1p*q1q<0)
            {
                q1p=-abs(q1p);
                q1q=abs(q1q);
            }
            else if (q1p*q1q>0)
            {
                q1p=abs(q1p);
                q1q=abs(q1q);
            }
			if (q1q==1)
			{
				printf("%lld\n",q1p);
			}
			else
			{
				printf("%lld/%lld\n",q1p,q1q);
			}
		}
		else
		{
			int q1p=-1*b,q1q=2*a;
			int g=__gcd(q1p,q1q);
			q1p/=g;
			q1q/=g;
			if (q1p*q1q<0)
            {
                q1p=-abs(q1p);
                q1q=abs(q1q);
            }
            else if (q1p*q1q>0)
            {
                q1p=abs(q1p);
                q1q=abs(q1q);
            }
			if (b!=0)
			{
			    sump=sump*q1q+q1p*sumq;
			    sumq=sumq*q1q;
			    int g2=__gcd(sump,sumq);
                sump/=g2;
                sumq/=g2;
                if (sump*sumq<0)
                {
                    sump=-abs(sump);
                    sumq=abs(sumq);
                }
                else if (q1p*q1q>0)
                {
                    sump=abs(sump);
                    sumq=abs(sumq);
                }
			}
			int q2p=1,q2q=2*a;
			for (int i=2;i*i<=delta;i++)
			{
				while (delta%(i*i)==0)
				{
					delta/=(i*i);
					q2p*=i;
				}
				if (delta==1)
				{
					break;
				}
			}
			int g1=__gcd(q2p,q2q);
			q2p/=g1;
			q2q/=g1;
			if (q2p*q2q<0)
            {
                q2p=-abs(q2p);
                q2q=abs(q2q);
            }
            else if (q1p*q1q>0)
            {
                q2p=abs(q2p);
                q2q=abs(q2q);
            }
			if (delta==1)
			{
			    sump=sump*q2q+abs(q2p)*sumq;
                sumq=sumq*q2q;
                int g3=__gcd(sump,sumq);
                sump/=g3;
                sumq/=g3;
                if (sump*sumq<0)
                {
                    sump=-abs(sump);
                    sumq=abs(sumq);
                }
                else if (q1p*q1q>0)
                {
                    sump=abs(sump);
                    sumq=abs(sumq);
                }
                if (sumq==1)
                {
                    printf("%lld\n",sump);
                }
				else
                {
                    printf("%lld/%lld\n",sump,sumq);
                }
			}
			else
			{
			    if (b!=0)
                {
                    if (q1q==1)
                    {
                        printf("%lld+",q1p);
                    }
                    else
                    {
                        printf("%lld/%lld+",q1p,q1q);
                    }
                }
                if (q2q==1)
				{
					if (abs(q2p)==1)
					{
						printf("sqrt(%lld)\n",delta);
					}
					else
					{
						printf("%lld*sqrt(%lld)\n",abs(q2p),delta);
					}
				}
				else
				{
					if (abs(q2p)==1)
					{
						printf("sqrt(%lld)/%lld\n",delta,q2q);
					}
					else
					{
						printf("%lld*sqrt(%lld)/%lld\n",abs(q2p),delta,q2q);
					}
				}
			}
		}
	}
	return 0;
}
