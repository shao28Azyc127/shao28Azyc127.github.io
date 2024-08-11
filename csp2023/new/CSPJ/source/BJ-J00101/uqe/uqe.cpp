#include<iostream>
#include<cmath>
using namespace std;
int gen(int m)
{
    int n=m;
    int ans=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            int cnt=0;
            while(n%i==0)
            {
                n/=i;
                cnt++;
            }
            ans*=pow(i,cnt/2);
        }
    }
    return ans;
}
int gcd(int a,int b)
{
    if(b==0)return a;
    else gcd(b,a%b);
}
int main()
{
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=t;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int deta=pow(b,2)-4*a*c;
        if(deta<0)
        {
            cout<<"NO";
            continue;
        }
        else if(deta>0)
        {
            int q2=gen(deta);
            int q3=deta/pow(q2,2);
            int q4=2*a;
            int fenmu,fenzi;
            int fu=1;
            int fu2=0;
            if(q4<0)fu2=1;
            if(q4<0&&b<0)
            {
                fu=1;
                q4*=-1;
                b*=-1;
            }
            else if(q4>0&&b<0)
            {
                fu=0;
                b*=-1;
            }
            else if(q4<0&&b>0)
            {
                fu=0;
                q4*=-1;
            }
            int q5=q2/gcd(q2,q4);
            int q6=q4/gcd(q2,q4);
            if(b>0)
            {
                fenmu=q4/gcd(q4,b);
                fenzi=b/gcd(q4,b);
                if(fenmu==1)
                {
                    if(fu==0)
                    {
                        cout<<fenzi;
                    }
                    else cout<<"-"<<fenzi;
                }
                else
                {
                    if(fu==0)
                    {
                    cout<<fenzi<<"/"<<fenmu;
                    }
                    else
                    {
                        cout<<"-"<<fenzi<<"/"<<fenmu;
                    }
                }
                
            }
            if(q5==1)
            {
                if(fu2==0)
                {
                    cout<<q5<<"/"<<q6;
                }
                else
                {
                    cout<<"-"<<q5<<"/"<<q6;
                }
            }
           else
            {
                if(q6==1)
                {if(fu2==0)
                {
                    cout<<"+"<<q5<<"*sqrt("<<q3<<")";
                }
                else
                {
                    cout<<"-"<<q5<<"*sqrt("<<q3<<")";
                }
                }
                else
                {{if(fu2==0)
                {
                    cout<<"+"<<q5<<"*sqrt("<<q3<<")"<<"/"<<q6;
                }
                else
                {
                    cout<<"-"<<q5<<"*sqrt("<<q3<<")"<<"/"<<q6;
                }
                }
            }
            }

        }
        else
        {
            int fu3=0;
            if(a>0&&b<0)
            {
                fu3=1;
                b*=-1;
            }
            else if(a<0&&b>0)
            {
                fu3==1;
                a*=-1;
            }
            else if(a<0&&b<0)
            {
                a*=-1;
                b*=-1;
            }
            a*=2;
            int zi=a/gcd(a,b);
            int mu=b/gcd(a,b);
            if(mu==1)
                {
                    if(fu3==0)
                    {
                        cout<<zi;
                    }
                    else cout<<"-"<<zi;
                }
                else
                {
                    if(fu3==0)
                    {
                    cout<<zi<<"/"<<mu;
                    }
                    else
                    {
                        cout<<"-"<<zi<<"/"<<mu;
                    }
                }
        }
    }
}