#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,m;
void print(int a,int b)
{
    if(a==0)
    {
        cout<<0;
        return;
    }
    if(a<0&&b<0)a=-a,b=-b;
    else if(a<0)
    {
        cout<<'-';
        a=-a;
    }
    else if(b<0)
    {
        cout<<'-';
        b=-b;
    }
    int g=__gcd(a,b);
    a/=g,b/=g;
    if(b==1)cout<<a;
    else cout<<a<<'/'<<b;
}
void printsqrt(int a,int b,int x)
{
    if(a<0&&b<0)a=-a,b=-b;
    int g=__gcd(a,b);
    a/=g,b/=g;
    if(a==1&&b==1)cout<<"sqrt("<<x<<")";
    else if(a==1)cout<<"sqrt("<<x<<")/"<<b;
    else if(b==1)cout<<a<<"*sqrt("<<x<<")";
    else cout<<a<<"*sqrt("<<x<<")/"<<b;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0)cout<<"NO"<<endl;
        else if(delta==0)
        {
            print(-b,2*a);
            cout<<endl;
        }
        else
        {
            if(a<0)a=-a,b=-b;
            double x=sqrt(delta);
            if(x==int(x))print(-b+x,2*a);
            else
            {
                if(b!=0)
                {
                    print(-b,2*a);
                    cout<<'+';
                }
                int k;
                for(int i=1;i*i<=delta;i++)
                    if(delta%(i*i)==0)k=i;
                delta/=k*k;
                printsqrt(k,2*a,delta);
            }
            cout<<endl;
        }
    }
    return 0;
}