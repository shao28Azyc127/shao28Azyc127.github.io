#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
int gcb(int a1,int b1)
{
    int r=max(a1,b1)%min(a1,b1);
    if(r==0)
        return min(a1,b1);
    return gcb(min(a1,b1),r);
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c,d,p,q,r;
    cin>>t>>m;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b>>c;
        d=b*b-4*a*c;
        if(d<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(round(sqrt(d))*round(sqrt(d))==round(d))
        {
            if(a>0)
                d=0-b+int(sqrt(d));
            else
                d=0-b-int(sqrt(d));
            if(d%(2*a)==0)
                cout<<d/(2*a)<<endl;

            else
            {
                p=gcb(d,2*a);
                if(2*a/p<0)
                    cout<<d/(0-p)<<'/'<<2*a/(0-p)<<endl;
                else
                    cout<<d/p<<'/'<<2*a/p<<endl;
            }
        }
        else
        {
            if(2*a>0)
            {
                if(b!=0)
                {
                    if((0-b)%(2*a)==0)
                        cout<<(0-b)/(2*a)<<'+';
                    else
                    {
                        p=gcb((0-b),(2*a));
                        if(2*a/p<0)
                            cout<<(0-b)/(0-p)<<'/'<<2*a/(0-p)<<'+';
                        else
                            cout<<(0-b)/p<<'/'<<2*a/p<<'+';
                    }
                }
                r=d;
                p=1;
                for(int i=2;i<sqrt(r);i++)
                {
                    while(r%(i*i)==0)
                    {
                        p*=i;
                        r/=i*i;
                    }
                }
                if(p/(2*a)==1)
                    cout<<"sqrt("<<r<<')'<<endl;
                else if(p%(2*a)==0)
                    cout<<p/(2*a)<<"*sqrt("<<r<<')'<<endl;
                else if(2*a%p==0)
                    cout<<"sqrt("<<r<<")/"<<2*a/p<<endl;
                else
                {
                    q=gcb(p,2*a);
                    cout<<p/q<<"*sqrt("<<r<<")/"<<2*a/q<<endl;
                }
            }
            else
            {
                a=0-a;
                if(b!=0)
                {
                    if(b%(2*a)==0)
                        cout<<b/(2*a)<<'+';
                    else
                    {
                        p=gcb(b,(2*a));
                        if(2*a/p<0)
                            cout<<b/(0-p)<<'/'<<2*a/(0-p)<<'+';
                        else
                            cout<<b/p<<'/'<<2*a/p<<'+';
                    }
                }
                r=d;
                p=1;
                for(int i=2;i<sqrt(r);i++)
                {
                    while(r%(i*i)==0)
                    {
                        p*=i;
                        r/=i*i;
                    }
                }
                if(p/(2*a)==1)
                    cout<<"sqrt("<<r<<')'<<endl;
                else if(p%(2*a)==0)
                    cout<<p/(2*a)<<"*sqrt("<<r<<')'<<endl;
                else if(2*a%p==0)
                    cout<<"sqrt("<<r<<")/"<<2*a/p<<endl;
                else
                {
                    q=gcb(p,2*a);
                    cout<<p/q<<"*sqrt("<<r<<")/"<<2*a/q<<endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
