#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a,b,c;
ll gcd(ll a,ll b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return gcd(b,a%b);
    }
}
void printfra(ll p,ll q)
{
    if(q<0)
    {
        p*=-1;
        q*=-1;
    }
    ll yue=gcd(abs(p),q);
    p/=yue;
    q/=yue;
    if(q==1)
    {
        cout<<p;
    }
    else
    {
        cout<<p<<"/"<<q;
    }
}
void printira(ll p1,ll q1,ll p2,ll q2,ll root)
{
    if(p1!=0)
    {
        printfra(p1,q1);cout<<"+";
    }
    if(q2<0)
    {
        p2*=-1;
        q2*=-1;
    }
    ll yue=gcd(abs(p2),q2);
    p2/=yue;
    q2/=yue;
    if(q2!=1)
    {
        if(p2!=1)
            cout<<p2<<"*sqrt("<<root<<")/"<<q2;
        else
        {
            cout<<"sqrt("<<root<<")/"<<q2;
        }
    }
    else{
        if(p2!=1)
            cout<<p2<<"*sqrt("<<root<<")";
        else
        {
            cout<<"sqrt("<<root<<")";
        }
    }
}
int solve()
{
    cin>>a>>b>>c;
    ll delta=b*b+(-4)*a*c;
    if(delta<0)
    {
        cout<<"NO\n";
        return 0;
    }
    ll p1,p2,q1,q2;
    p1=1;
    p2=1;
    q1=1;
    q2=1;
    if(delta==0)
    {
        printfra(-b,2*a);
        cout<<"\n";
        return 0;
    }
    for(ll i=2;i*i<=delta;i++)
    {
        ll j=i*i;
        if(delta%j==0)
        {
            while(delta%j==0)
            {
                p2*=i;
                delta/=j;
            }
        }
    }
    if(a<0)
    {
        p1=b;
        p2*=(1);
        q1=a*(-2);
        q2=a*(-2);
    }
    else
    {
        p1=-b;
        p2*=1;
        q1=2*a;
        q2=2*a;
    }
    if(delta==1)
    {
        p1+=p2;
        printfra(p1,q1);
        cout<<"\n";
        return 0;
    }
    printira(p1,q1,p2,q2,delta);
    cout<<"\n";
    return 0;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t;
    cin>>t;
    int m;
    cin>>m;
    while(t--)
    {
        solve();
    }
    return 0;
}
