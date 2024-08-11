#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long gcd(long long a,long long b)
{
    if(b==0)
    {
        return a;
    }
    else return gcd(b,a%b);
}
long long f(long long x)
{
    long long cnt=1;
    for(long long i=2;i<=sqrt(x);i++)
    {
        long long c=0;
        while(x%i==0)
        {
            x=x/i;
            c++;
        }
        for(long long j=2;j<=c;j+=2)
        {
            cnt*=i;
        }
    }
    return cnt;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long cta=b*b-4*a*c;
        if(cta<0)
        {
            cout<<"NO\n";
            continue;
        }
        long long sq=sqrt(cta);
        if(sq*sq==cta)
        {
            long long p1=-b+sq,p2=-b-sq,q=2*a,p;
            if(q>=0)
            {
                p=max(p1,p2);
            }
            else p=min(p1,p2);
            long long a=gcd(p,q);
            p=p/a;
            q=q/a;
            if(q<0)
            {
                q=-q;
                p=-p;
            }
            if(q==1)
            {
                cout<<p<<endl;
            }
            else cout<<p<<"/"<<q<<endl;
        }
        else
        {
            double p1=-b+sqrt(cta),p2=-b-sqrt(cta),q=2*a,q1=q;
            long long p=-b;
            long long a=gcd(p,q);
            p=p/a,q1=q1/a;
            if(q1<0)
            {
                q1=-q1;
                p=-p;
            }
            if(p!=0)
            {
                if(q1==1)cout<<p;
                else cout<<p<<"/"<<q1;
            }
            if(q<0)
            {
                if(p1<p2)cout<<"-";
                else if(p!=0)cout<<"+";
                q=-q;
            }
            else
            {
                if(p1>p2)
                {
                    if(p!=0)cout<<"+";
                }
                else cout<<"-";
            }
            long long s=f(cta);
            long long b=gcd(s,q);
            long long s1=s/b;
            q=q/b;
            if(s1!=1)
            {
                cout<<s1<<"*";
            }
            cout<<"sqrt("<<cta/s/s<<")";
            if(q!=1)cout<<"/"<<q;
            cout<<endl;
        }
    }
    return 0;
}
