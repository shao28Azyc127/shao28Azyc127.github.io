#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int a,b,c;
int pfyz(int a)
{
    int sum=1;
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            if(a%i*i==0 and a%i*i*i*i!=0)
                sum*=i;
        }
    }
    return sum;
}
int gcd(int a,int b)
{
    int num=1;
    for(int i=1;i*i<=a;i++)
    {
        if(a%i==0 and b%i==0)
        {
            num*=i;
            a/=i;
            b/=i;
        }
    }
    return num;
}
int n(int a,int b,int c)
{
    int k=b*b-4*a*c;
    if(k<0)
    return 0;
    return k;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int v,m;
    cin>>v>>m;
    for(int i=1;i<=v;i++)
    {
        cin>>a>>b>>c;
        int k=n(a,b,c);
        int y=pfyz(k);
        if(n(a,b,c)==0)
        {
            cout<<"NO";
            return 0;
        }
        if(b==0)
        {
            if(y==2*a)
            {
                cout<<"sqrt("<<k/y/y<<")"<<endl;
            }
            else if(gcd(y,2*a)==2*a)
            {
                cout<<y/2/a<<"*"<<"sqrt("<<k/y/y<<")"<<endl;
            }
            else if(gcd(y,2*a)==y)
            {
                cout<<"sqrt("<<k/y/y<<")"<<"/"<<2*a/y<<endl;
            }
            else
            {
                cout<<y/gcd(y,2*a)<<"sqrt("<<k/y/y<<")"<<"/"<<2*a/gcd(y,2*a)<<endl;
            }
        }
        else if(gcd(2*a,b)==2*a)
        {
            if(y==2*a)
            {
                cout<<b/2/a<<"+" <<"sqrt("<<k/y/y<<")"<<endl;
            }
            else if(gcd(y,2*a)==2*a)
            {
                cout<<b/2/a<<"+" <<y/2/a<<"*"<<"sqrt("<<k/y/y<<")"<<endl;
            }
            else if(gcd(y,2*a)==y)
            {
                cout<<b/2/a<<"+" <<"sqrt("<<k/y/y<<")"<<"/"<<2*a/y<<endl;
            }
            else
            {
                cout<<b/2/a<<"+" <<y/gcd(y,2*a)<<"sqrt("<<k/y/y<<")"<<"/"<<2*a/gcd(y,2*a)<<endl;
            }
        }
        else 
        {
            if(y==2*a)
            {
                cout<<b/2/a<<"+" <<"sqrt("<<k/y/y<<")"<<endl;
            }
            else if(gcd(y,2*a)==2*a)
            {
                cout<<b/2/a<<"+" <<y/2/a<<"*"<<"sqrt("<<k/y/y<<")"<<endl;
            }
            else if(gcd(y,2*a)==y)
            {
                cout<<b/2/a<<"+" <<"sqrt("<<k/y/y<<")"<<"/"<<2*a/y<<endl;
            }
            else
            {
                cout<<b/2/a<<"+" <<y/gcd(y,2*a)<<"sqrt("<<k/y/y<<")"<<"/"<<2*a/gcd(y,2*a)<<endl;
            }
        }
    }
    return 0;
}
