#include<bits/stdc++.h>
using namespace std;
void BREAK(int &x,double &y)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%(i*i)==0)
        {
            y=y*i;
            x/=(i*i);
        }
    }
    return ;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    if(m<=1)
    {
        int a,b,c;
        while(t--)
        {
            cin>>a>>b>>c;
            int delta=b*b-4*a*c;
            if(delta<0)
                cout<<"NO"<<endl;
            else
                cout<<0<<endl;
        }
    }
    else
    {
        int a,b,c;
        while(t--)
        {
            cin>>a>>b>>c;
            int delta=b*b-4*a*c;
            if(delta<0)
            {
                cout<<"NO"<<endl;
                continue;
            }
            else if(delta==0)
            {
                int ans=(-b)/2*a;
                cout<<ans<<endl;
                continue;
            }
            else
            {
                double ans1,ans2;
                ans1=(-b+sqrt(delta))/(2*a);
                ans2=(-b-sqrt(delta))/(2*a);
                int x;
                if(ans1>ans2) x=ans1;
                else x=ans2;
                for(int i=sqrt(delta)-2;i<=sqrt(delta)+2;i++)
                {
                    if(i*i==delta)
                    {
                        if((2*a)==__gcd(-b+i,2*a))
                        {
                            cout<<x<<endl;
                            continue;
                        }
                    }
                }
                double times_delta=1;
                BREAK(delta,times_delta);
                if(b==0) continue;
                else if(-b!=0 && (-b)%(2*a)==0)
                    cout<<(-b)%(2*a)<<"+";
                else
                {
                    if(-b<0 && 2*a<0)
                    {
                        b=-1*b;
                        a=-1*a;
                    }
                    else if(-b<0)
                    {
                        cout<<"-";
                        b=-1*b;
                    }
                    else if(2*a<0)
                    {
                        cout<<"-";
                        a=-1*a;
                    }
                    b/=__gcd(-b,2*a);
                    a/=__gcd(-b,2*a);
                    cout<<-b<<"/"<<2*a<<"+";
                }
                if(times_delta==1 && delta!=1)
                    cout<<"sqrt("<<delta<<")"<<endl;
                else if(times_delta==1 && delta==1)
                    cout<<1<<endl;
                else if(times_delta>1)
                    cout<<times_delta<<"*sqrt("<<delta<<")"<<endl;
                else if(1/(int(times_delta))==(1.0)/times_delta)
                    cout<<"sqrt("<<delta<<")/"<<1/times_delta<<endl;
                else
                {
                    double c=1,d=1;
                    double x=times_delta;
                    while(c/d!=x)
                    {
                        if(c/d>x) d++;
                        if(c/d<x) c++;
                    }
                    cout<<c<<"*sqrt("<<delta<<")/"<<d<<endl;
                }
            }
        }
    }
    return 0;
}
