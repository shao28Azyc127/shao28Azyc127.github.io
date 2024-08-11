#include<iostream>
#include<algorithm>
#include<cstdio>
#include<math.h>
#include<string>
#define int long long
using namespace std;
int gcd(int a,int b)
{
    if(b>a) swap(a,b);
    int c=a%b;
    while(c!=0)
    {
        a=b;
        b=c;
        c=a%b;
    }
    return b;
}
int tabs(int a)
{
    if(a<0) return -a;
    return a;
}
string zf(int a,int b)
{
    if(a==0) return "";
    if(a>0&&b>0) return "";
    if(a>0&&b<0) return "-";
    if(b>0) return "-";
    return "";
}
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        if((b*b-4*a*c)<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        int d=b*b-4*a*c;//d>=0
        if(d==((int)(sqrt(d))*(int)(sqrt(d))))
        {
            d=sqrt(d);
            int e=tabs(d-b);
            int f=tabs(2*a);
            if(e%f==0)
            cout<<zf(d-b,2*a)<<e/f<<endl;
            else
            cout<<zf(d-b,2*a)<<e/(gcd(e,f))<<"/"<<f/(gcd(e,f))<<endl;
            continue;
        }
        int d1,d2;
        for(int i=sqrt(d);i>=1;i--)
        {
            if(d%(i*i)==0)
            {
                d1=i;
                d2=d/i/i;
                break;
            }
        }
        if(b!=0)
        {
            int b1=tabs(b),f=tabs(2*a);
            if(b1%f==0)
            cout<<zf(-b,2*a)<<b1/f;
            else
            cout<<zf(-b,2*a)<<b1/(gcd(b1,f))<<"/"<<f/(gcd(b1,f));
            if(zf(d1,2*a)=="") cout<<"+";

        }
        cout<<zf(d1,2*a);
        int g=tabs(2*a);
        if(d1==g)
        cout<<"sqrt("<<d2<<")"<<endl;
        else if(d1%g==0)
        cout<<d1/g<<"*sqrt("<<d2<<")"<<endl;
        else if(d1/(gcd(d1,g))!=1)
        cout<<d1/(gcd(d1,g))<<"*sqrt("<<d2<<")"<<"/"<<g/(gcd(d1,g))<<endl;
        else cout<<"sqrt("<<d2<<")"<<"/"<<g/(gcd(d1,g))<<endl;

    }


    return 0;
}
