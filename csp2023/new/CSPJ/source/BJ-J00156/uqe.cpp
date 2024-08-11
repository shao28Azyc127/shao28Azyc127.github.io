#include <iostream>
#include <cmath>
using namespace std;
#define IO_ON_FILE
int t,m;
int gcd(int a,int b)
{
    if(a<0)
        a=-a;
    if(b<0)
        b=-b;
    if(a<b)
    {
        int t=a;
        a=b;
        b=t;
    }
    while(b>=1)
    {
        int t=a;
        a=b;
        b=t%b;
    }
    return a;
}
int main()
{
    #ifdef IO_ON_FILE
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    #endif // IO_ON_FILE
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int t=b*b-4*a*c;
        if(t<0)
        {
            cout<<"NO\n";
            continue;
        }
        double tmp=sqrt(t);
        if(floor(tmp)==tmp)
        {
            //-b+tmp/2*a
            int ttmp=a<0?-b-tmp:-b+tmp;
            int g=gcd(ttmp,2*a);
            int p=ttmp/g,q=2*a/g;
            if(q<0)
            {
                p=-p;
                q=-q;
            }
            if(q==1)
                cout<<p;
            else if(q==-1)
                cout<<-p;
            else
                cout<<p<<"/"<<q;
        }
        else
        {
            //-b/2*a+sqrt(t)/2*a
            int g1=gcd(-b,2*a);
            int p1=(-b)/g1,q1=2*a/g1;
            if(q1<0)
            {
                p1=-p1;
                q1=-q1;
            }
            if(p1!=0)
                if(q1==1)
                    cout<<p1<<"+";
                else if(q1==-1)
                    cout<<-p1<<"+";
                else
                    cout<<p1<<"/"<<q1<<"+";
            int tt=t,b=1;
            for(int i=2;i*i<=tt;i++)
                while(tt%(i*i)==0)
                {
                    tt/=i*i;
                    b*=i;
                }
            int g2=gcd(b,2*a);
            int p2=b/g2,q2=2*a/g2;
            if(a<0)
                q2*=-1;
            if(p2!=1)
                if(q2==-1)
                    cout<<-p2<<"*";
                else
                    cout<<p2<<"*";
            cout<<"sqrt("<<tt<<")";
            if(q2!=1&&q2!=-1)
                cout<<"/"<<q2;
        }
        cout<<endl;
    }
    return 0;
}
