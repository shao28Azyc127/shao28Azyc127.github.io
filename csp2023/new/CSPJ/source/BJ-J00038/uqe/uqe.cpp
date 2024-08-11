#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,M;
int a,b,c;
int x;
int gcd(int n,int m)
{
    if(m==0)  return n;
    return gcd(m,n%m);
}
int f(int n)
{
    if(n==0)  return 0;
    for(int i=sqrt(n);i>=1;i--)
        if(n%(i*i)==0)  return i;
    return 1;
}
bool ff(int n)
{
    if(n==0)  return 1;
    for(int i=1;i*i<=n;i++)
        if(i*i==n)  return 1;
    return 0;
}
signed main()
{
    freopen("uqe.in","w",stdin);
    freopen("uqe.out","r",stdout);
    cin>>T>>M;
    while(T--)
    {
        cin>>a>>b>>c;
        if(b*b-4*a*c<0)  cout<<"NO"<<endl;
        else
        {
            x=b*b-4*a*c;
            if(ff(x))
            {
                int xx=sqrt(x);
                if(2*a/gcd((xx-b),(2*a))==1)  cout<<(xx-b)/gcd((xx-b),(2*a))<<endl;
                else if(2*a/gcd((xx-b),(2*a))==-1)  cout<<-1*(xx-b)/gcd((xx-b),(2*a))<<endl;
                else
                {
                    if(2*a/gcd((xx-b),(2*a))<0)  cout<<-1*(xx-b)/gcd((xx-b),(2*a))<<"/"<<-2*a/gcd((xx-b),(2*a))<<endl;
                    else                         cout<<(xx-b)/gcd((xx-b),(2*a))<<"/"<<2*a/gcd((xx-b),(2*a))<<endl;
                }
            }
            else
            {
                int xx=f(x),xxx=x/xx/xx;
                if(b!=0)
                {

                    if((0-b)%(2*a)==0)  cout<<(0-b)/2/a<<"+";
                    else
                    {
                        if(2*a/gcd((0-b),(2*a))<0)  cout<<-1*(0-b)/gcd((0-b),(2*a))<<"/"<<-2*a/gcd((0-b),(2*a))<<"+";
                        else cout<<(0-b)/gcd((0-b),(2*a))<<"/"<<2*a/gcd((0-b),(2*a))<<"+";
                    }
                }

                if(xx%(2*a)==0)  cout<<xx/(2*a)<<"*sqrt("<<xxx<<")"<<endl;

                else
                {
                    if(2*a/gcd(xx,(2*a))<0) cout<<-1*xx/gcd(xx,(2*a))<<"*sqrt("<<xxx<<")"<<"/"<<-2*a/gcd(xx,(2*a))<<endl;
                    else if(xx/gcd(xx,(2*a))==1)  cout<<"sqrt("<<xxx<<")"<<"/"<<2*a/gcd(xx,(2*a))<<endl;
                    else cout<<xx/gcd(xx,(2*a))<<"*sqrt("<<xxx<<")"<<"/"<<2*a/gcd(xx,(2*a))<<endl;
                }
            }
        }

    }
    return 0;
}
