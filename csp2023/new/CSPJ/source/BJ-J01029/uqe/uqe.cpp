#include<iostream>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,b%a);
}
bool issqr(int a)
{
    int s=(int)sqrt(a);
    return s*s==a;
}
void outd(int p,int q)
{
    int g=gcd(max(p,q),min(p,q));
    int p0=p/g,q0=q/g;
    cout<<p0;
    if(q0!=1) cout<<'/'<<q0;
}
void solve(int a,int b,int c)
{
    int d=b*b-4*a*c;
    int p=-b,q=2*a;
    if(d<0)
        cout<<"NO"<<endl;

    else if(d==0)
    {
        outd(p,q);cout<<endl;
    }
    else
    {
        if(issqr(d))
        {
            int sd=(int)sqrt(d);
            outd(p-sd,q);cout<<'/';
            outd(p+sd,q);cout<<endl;
        }
    }
}
int main()
{
    int T,M;
    int a,b,c;
    cin>>T>>M;
    for(int i=0;i<T;i++)
    {
        cin>>a>>b>>c;
        solve(a,b,c);
    }
    return 0;
}
