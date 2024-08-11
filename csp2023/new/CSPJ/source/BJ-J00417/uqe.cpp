#include <iostream>
#include <cmath>
using namespace std;

int gcd(int x,int y,int z)
{
    int ans=1;
    for(int i=2;i*i<=max(z,max(x,y));i++)
    {
        if(x%i==0&&y%i==0&&z%i==0)
        {
            ans*=i;
        }
    }
    return ans;
}

int pingfangshu(int x)
{
    int ans=1;
    for(int i=2;i*i<=x;i++)
    {
        if(x%(i*i)==0)
        {
            ans*=(i*i);
        }
    }
    return sqrt(ans);
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
        int d=b*b-4*a*c;
        if(d<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else
        {
            int e=2*a,d1=-1*b;
            int d2=pingfangshu(d);//d2
            int g=d-d2*d2;//根号下的数
            int j=gcd(e,d2,d1);
            cout<<j<<endl;
            e/=j;
            d2/=j;
            d1/=j;
            if(int(d1+d2*sqrt(g))==d1+1.0*d2*sqrt(g))
            {
                cout<<d1+1.0*d2*sqrt(g)<<endl;
                continue;
            }
            if(e==1)
            {
               if(g==0)
                {
                    cout<<d1<<endl;
                    continue;
                }
                if(d2==1)
                {
                    cout<<d1<<"+sqrt("<<g<<")"<<endl;
                    continue;
                }
                else
                {
                    cout<<d1<<"+"<<d2<<"*sqrt("<<g<<")"<<endl;
                   continue;
                }
            }
            else
            {
                if(g==0)
                {
                    cout<<d1<<"/"<<e<<endl;
                    continue;
                }
                if(d2==1)
                {
                    cout<<d1<<"/"<<e<<"+sqrt("<<g<<")"<<"/"<<e<<endl;
                    continue;
                }
                else
                {

                    cout<<d1<<"/"<<e<<"+"<<d2<<"*sqrt("<<g<<")/"<<e<<endl;
                    continue;
                }
            }
        }
    }
    return 0;
}
