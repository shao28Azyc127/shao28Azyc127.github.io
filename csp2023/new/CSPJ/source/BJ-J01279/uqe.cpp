#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a,b,c,m;
int r,R;
int p,q,q1,q2;
int q1p,q1q,q2p,q2q;
int z,GCD;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void yuefen(int& p,int& q)
{
    GCD=gcd(p,q);
    p/=GCD;
    q/=GCD;
    if(p>0&&q<0)
    {
        p=-p;
        q=-q;
    }
}
void printdiv(int p,int q)
{

    if(q==1) cout<<p;
    else cout<<p<<'/'<<q;
}
int getsqdiv(int z)
{
    for(int i=sqrt(z);i>=1;i--)
        if(z%(i*i)==0)
            return i*i;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    //ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int _=1;_<=n;_++)
    {
        scanf("%d%d%d",&a,&b,&c);
//        cout<<a<<' '<<b<<' '<<c<<'\n';
        r=b*b-4*a*c;
//        cout<<"r="<<r<<'\n';
        if(r<0)
        {
            cout<<"NO\n";
            continue;
        }
        if(int(sqrt(r))*int(sqrt(r))==r)
        {
//cout<<r<<" square\n";
            z=int(sqrt(r));
            if(a>0)
                p=-b+z;
            else
                p=-b-z;
            q=2*a;
//cout<<"p="<<p<<" q="<<q<<'\n';
            yuefen(p,q);
            printdiv(p,q);
            cout<<'\n';
        }
        else{
//cout<<r<<" not square\n";
            q1p=-b;
            q1q=2*a;
//cout<<"q1p="<<q1p<<" q1q="<<q1q<<'\n';
            yuefen(q1p,q1q);
            if(q1p!=0) printdiv(q1p,q1q);
            if(q1p!=0) cout<<'+';
            q2p=sqrt(getsqdiv(r));
            R=r/getsqdiv(r);
            q2q=2*a;
//cout<<"q2p="<<q2p<<" q2q="<<q2q<<'\n';
            yuefen(q2p,q2q);
            if(q2p<0) q2p=-q2p;
            if(q2p==1&&q2q==1)
                cout<<"sqrt("<<R<<")\n";
            else if(q2q==1)
                cout<<q2p<<"*sqrt("<<R<<")\n";
            else if(q2p==1)
                cout<<"sqrt("<<R<<")/"<<q2q<<"\n";
            else
                cout<<q2p<<"*sqrt("<<R<<")/"<<q2q<<"\n";
        }
    }
    return 0;
}

