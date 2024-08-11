#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a<b)swap(a,b);
    while(b!=0)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int d=b*b;
        d-=4*a*c;
        if(d<0){cout<<"NO";}
        else
        {
            if(sqrt(d)==(int)sqrt(d))
            {
                if(a<0)
                {
                    d=sqrt(d)+b;
                    a=-a;
                }
                else
                {
                    d=sqrt(d)-b;
                }
                int p=gcd(2*a,d);
                d/=p;
                a*=2;
                a/=p;
                if(a<0)d=-d,a=-a;
                cout<<d;
                if(a!=1)cout<<"/"<<a;
            }
            else
            {
                if(b!=0)
                {
                    int a1=a;
                    a1*=2;
                    int p=gcd(a1,b);
                    a1/=p;
                    b/=p;
                    b=-b;
                    if(a1<0)
                    {
                        b=-b;
                        a1=-a1;
                    }
                    cout<<b;
                    if(a1!=1)cout<<"/"<<a1;
                    cout<<"+";
                }
                int k;
                for(int j=1;j<=sqrt(d);j++)
                {
                    if(d%(j*j)==0)k=j;
                }
                if(k==0)
                {
                    if(a<0)cout<<"-",a=-a;
                    cout<<"sqrt("<<d<<")/"<<2*a;
                }
                else
                {
                    d/=k*k;
                    a*=2;
                    int p=gcd(k,a);
                    a/=p;
                    k/=p;
                    if(a<0)a=-a;
                    k=abs(k);
                    if(k!=1)cout<<k<<"*";
                    cout<<"sqrt("<<d<<")";
                    if(a!=1)cout<<"/"<<a;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
