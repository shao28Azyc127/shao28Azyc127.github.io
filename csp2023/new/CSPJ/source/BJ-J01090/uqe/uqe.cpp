#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1e5+10;
ll t,m,a,b,c,k,u,d;
ll g,p,f,x,y,z,q;
ll gcd(ll a,ll b)
{
    if(a%b==0)
    {
        return b;
    }
    return gcd(b,a%b);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--)
    {
        cin>>a>>b>>c;
        k=b*b-4*a*c;
        if(k<0)
        {
            cout<<"NO\n";
            continue;
        }
        g=abs(sqrt(k));
        if(g*g==k)
        {
            u=g-b;
            d=2*a;
        }
        f=1;
        if((d<0&&u>=0)||(u<0&&d>=0))
        {
            f=-1;
        }
        d=abs(d);
        u=abs(u);
        p=gcd(max(u,d),min(u,d));
        u/=p;
        d/=p;
        if(d==1)
        {
            cout<<f*u;
        }
        else
        {
            cout<<f*u<<"/"<<d;
        }
        if(g*g==k)
        {
            cout<<"\n";
            continue;
        }



        y=k;
        z=2*a;
        for(int i=1;i<=g;i++)
        {
            if(k%(i*i)==0)
            {
                x=i;
            }
        }
        k/=x*x;
        f=1;
        if((x<0&&z>=0)||(z<0&&x>=0))
        {
            f=-1;
        }
        z=abs(z);
        x=abs(x);
        q=gcd(max(x,z),min(x,z));
        x/=q;
        z/=q;
        x*=f;
        if(x>0)
        {
            cout<<"+";
        }
        else
        {
            cout<<"-";
        }
        if(abs(x)!=1)
        {
            cout<<abs(x)<<"*";
        }
        cout<<"sprt("<<k<<")";
        if(z!=1)
        {
            cout<<"/"<<z;
        }
        cout<<"\n";
    }
    return 0;
}
