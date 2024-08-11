#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int T,M;

int v(int a)
{
    if(a>0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}

int gcd(int a,int b)
{
    if(a<b)
    {
        swap(a,b);
    }
    if(a%b==0)
    {
        return b;
    }
    else
    {
        return gcd(a%b,b);
    }
}

void printdivide(int a,int b)
{
    bool fuhao=false;
    if(a*b<0)
    {
        cout<<"-";
    }
    a=v(a);
    b=v(b);
    int g=gcd(a,b);
    a/=g;
    b/=g;
    if(b==1)
    {
        cout<<a;
    }
    else if(a==0)
    {
        return;
    }
    else
    {
        cout<<a<<"/"<<b;
    }
    return;
}

int sq(int a)
{
    for(int i=(int)sqrt(a);i>=2;i--)
    {
        int fang=i*i;
        if(a%fang==0)
        {
            return i;
        }
    }
    return 1;
}

void printsqrt(int q2,int r,int b)
{
    int g=gcd(q2,b);
    q2/=g;
    b/=g;
    if(b!=1)
    {
        if(q2==1&&r==1)
        {
            cout<<"1/"<<b<<"\n";
        }
        else if(q2==1)
        {
            cout<<"sqrt("<<r<<")/"<<b<<"\n";
        }
        else if(r==1)
        {
            cout<<q2<<"/"<<b<<"\n";
        }
        else
        {
            cout<<q2<<"*sqrt("<<r<<")/"<<b<<"\n";
        }
    }
    else
    {
        if(q2==1&&r==1)
        {
            cout<<"1"<<"\n";
        }
        else if(q2==1)
        {
            cout<<"sq"<<"rt("<<r<<")"<<"\n";
        }
        else if(r==1)
        {
            cout<<q2<<"\n";
        }
        else
        {
            cout<<q2<<"sq"<<"rt("<<r<<")"<<"\n";
        }
    }
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&T,&M);
    while(T--)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int dt=b*b-4*a*c;
        int q1=-b;
        int q2=sq(v(dt));
        int r=dt/(dt*dt);
        int k=q2-b;
        if(dt<0)
        {
            printf("NO");
        }
        else if(r==1&&v(k)%v(b)==0)
        {
            printdivide(k,2*a);
        }
        else if(r==0&&v(k)%v(b)==0)
        {
            printdivide(q1,2*a);
        }
        else
        {
            printdivide(q1,2*a);
            if(b!=0&&dt!=0)
            {
                cout<<"+";
            }
            printsqrt(q2,r,v(2*a));
        }

    }
    return 0;
}

