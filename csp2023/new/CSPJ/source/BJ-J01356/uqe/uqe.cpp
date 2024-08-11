#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,t,m;
int gcd(int a,int b)
{
    int c;
    a=abs(a);
    b=abs(b);
    while (1)
    {
        int c=a%b;
        if (c==0)
            return b;
        return gcd(b,c);
    }
}
void print_rational_number(int a,int b)
{
    if (a==b)
    {
        cout<<1;
        return;
    }
    if (-a==b || a==-b)
    {
        cout<<-1;
        return;
    }
    if (gcd(a,b)>1)
        cout<<a/gcd(a,b)<<'/'<<b/gcd(a,b);
    else
        cout<<a/gcd(a,b);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    for (int i=1;i<=t;i++)
    {
        cin>>a>>b>>c;
        d=b*b-4*a*c;
        if (d<0)
        {
            cout<<"NO";
            continue;
        }
        else if (d==0)
        {
            print_rational_number(-b,2*a);
            continue;
        }
        else
            if ((-b+sqrt(d))/(2*a)>(-b-sqrt(d))/(2*a))
                if ((int)sqrt(d)*(int)sqrt(d)==d)
                    print_rational_number(-b+sqrt(d),2*a);
                else
                {
                    if (b!=0)
                    {
                        print_rational_number(-b,2*a);
                        cout<<'+';
                    }
                    if (a==0.5)
                        cout<<"sqrt("<<d<<')';
                    if (a==-0.5)
                        cout<<"-1*sqrt("<<d<<')';
                    else
                        cout<<"sqrt("<<d<<")/"<<2*a;
                }
            else
                if ((int)sqrt(d)*(int)sqrt(d)==d)
                    print_rational_number(-b-sqrt(d),2*a);
                else
                {
                    if (b!=0)
                    {
                        print_rational_number(-b,2*a);
                        cout<<'+';
                    }
                    if (a==-0.5)
                        cout<<"sqrt("<<d<<')';
                    if (a==0.5)
                        cout<<"-1*sqrt("<<d<<')';
                    else
                        cout<<"sqrt("<<d<<")/"<<-2*a;
                }
    }
}