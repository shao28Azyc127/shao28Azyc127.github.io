#include<bits/stdc++.h>
using namespace std;
bool f(double q)
{
    if(q-int(q)==0) return 1;
    return 0;
}
int d(double a,double b)
{
    if(b==1) cout<<a;
    else if(a==0) cout<<0;
    else
    {
        while((f(a)&&f(b))==0)
        {
            a*=10;
            b*=10;
        }
        int q=a,w=b;
        int x=(__gcd(q,w));
        if(x==1) cout<<q<<"/"<<w;
        else
        {
            q/=x;
            w/=x;
            if(w<0)
            {
                w=-w,q=-q;
            }
            cout<<q<<"/"<<w;
        }
    }
}
int s(double a,double b,double c)
{
    while((f(a)&&f(b))==0)
    {
        a*=10;
        b*=10;
    }
    int q=a,w=b;
    int x=(__gcd(q,w));
    q/=x;
    w/=x;
    if(c) cout<<q;
    return w;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    while(t--)
    {
        double a,b,c,derta;
        cin>>a>>b>>c;
        derta=b*b-4*a*c;
        if(derta<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(derta==0)
        {
            double q=(-b)/(2*a);
            if(f(q))
            {
                cout<<q<<endl;
                continue;
            }
            d(-b,2*a);
            cout<<endl;
            continue;
        }
        else
        {
            double x1=(-b+sqrt(derta))/(2*a),x2=(-b-sqrt(derta))/(2*a);
            if(x1>x2)
            {
                if(-b==0)
                {
                    if(f(x1))
                    {
                        cout<<x1<<endl;
                        continue;
                    }
                    if(f(derta))
                    {
                        if(2*a==1) cout<<"sqrt("<<derta<<")"<<endl;
                        else if(f(2*a)) cout<<2*a<<"*sqrt("<<derta<<")"<<endl;
                        else if(f(1/(a*2))) cout<<"sqrt("<<derta<<")/"<<(1/(a*2));
                        else
                        {
                            s(2*a,1,1);
                            cout<<"*sqrt("<<derta<<")/"<<s(2*a,1,0);
                        }
                    }
                }
                else
                {
                    if(f(x1))
                    {
                        cout<<x1<<endl;
                        continue;
                    }
                    if(f((-b)/(2*a))) cout<<(-b)/(2*a);
                    else d(-b,2*a);
                    cout<<"+";
                    if(f(derta))
                    {
                        if(2*a==1) cout<<"sqrt("<<derta<<")"<<endl;
                        else if(f(2*a)) cout<<"sqrt("<<derta<<")/"<<2*a<<endl;
                        else if(f(1/(a*2))) cout<<(1/(a*2))<<"*sqrt("<<derta<<")";
                        else
                        {
                            s(2*a,1,1);
                            cout<<"*sqrt("<<derta<<")/"<<s(2*a,1,0);
                        }
                    }
                    else
                    {

                    }
                }
            }
        }


    }
    return 0;
}
