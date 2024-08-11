#include<iostream>
#include<stdio.h>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int t,m;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int x=sqrt(delta);
        if(x*x==delta)
        {
            int x1=x/2.0/a-b/2.0/a;
            if(a*x1*x1+b*x1+c==0)cout<<x1<<endl;
            else
            {
                int p=x-b;
                int q=2*abs(a);
                int g=gcd(p,q);
                a*=2;
                p/=g,a/=g;
                if(a<0){p*=-1,a*=-1;}
                if(a==1)cout<<p<<endl;
                else if(p==0)cout<<0<<endl;
                else printf("%d/%d\n",p,a);
            }
        }
        else
        {
            int yinshu=1;
            for(int j=1;j*j<=delta;j++)
            {
                if(delta%(j*j)==0){yinshu*=j;delta=delta/j/j;}
            }
            int p1=abs(b),p2=delta;
            int q1=2*a,q2=2*a;
            int g1=gcd(p1,q1),g2=gcd(yinshu,q2);
            b/=g1,q1/=g1,yinshu/=g2,q2/=g2;
            if(b!=0)
            {
                if(q1==1)printf("%d+",-b);
                else printf("%d/%d+",-b,q1);
            }
            if(yinshu==1)
            {
                    if(q2==1)printf("sqrt(%d)\n",delta);
                    else printf("sqrt(%d)/%d\n",delta,q2);
            }
            else
            {
                    if(q2==1)printf("%d*sqrt(%d)\n",yinshu,delta);
                    else printf("%d*sqrt(%d)/%d\n",yinshu,delta,q2);
            }
        }
    }
    return 0;
}