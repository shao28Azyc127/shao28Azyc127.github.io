#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#define int long long int
using namespace std;
int tests,mmm;
int a,b,c;
inline pair<int,int> ad(int p1,int q1,int p2,int q2)
{
    if(q1<0)
    {
        p1=-p1;
        q1=-q1;
    }
    if(q2<0)
    {
        p2=-p2;
        q2=-q2;
    }
    int gcdd=__gcd(q1,q2);
    int lcmm=q1/gcdd*q2;
    p1*=lcmm/q1;
    p2*=lcmm/q2;
    int p=p1+p2;
    int q=lcmm;
    gcdd=__gcd(p,q);
    pair<int,int> pr;
    pr.first=p/gcdd;
    pr.second=q/gcdd;
    return pr;
}
inline int getsqrt(int p)
{
    if(p==0)
        return 0;
    int now=1;
    int q=p;
    for(register int i=2;i*i<=q;i++)
    {
        while(q%(i*i)==0)
        {
            q/=(i*i);
            now*=i;
        }
    }
    return now;
}
inline void print(int p,int q)
{
    if(q==0)
        return;
    if(q<0)
    {
        p=-p;
        q=-q;
    }
    if(p==0)
    {
        cout << p;
        return;
    }
    int gcdd=__gcd(abs(p),q);
    p/=gcdd;
    q/=gcdd;
    if(q==1)
        cout << p;
    else
        cout << p << '/' << q;
    return;
}
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> tests >> mmm;
    while(tests--)
    {
        cin >> a >> b >> c;
        int derta=(b*b-4*a*c);
        if(derta<0)
        {
            cout << "NO\n";
            continue;
        }
        if(derta==0)
        {
            print(-b,2*a);
            cout << endl;
            continue;
        }
        int q2=getsqrt(derta);
        int sqr=derta/(q2*q2);
        if(b!=0 && sqr>1)
        {
            print(-b,2*a);
            cout << '+';
        }
        if(b!=0 && sqr==1)
        {
            pair<int,int> pr=ad(-b,2*a,q2,abs(2*a));
            print(pr.first,pr.second);
            cout << endl;
            continue;
        }
        if(sqr==1)
        {
            print(q2,abs(2*a));
            cout << endl;
            continue;
        }
        a=abs(a);
        if(q2==2*a)
            cout << "sqrt(" << sqr << ")\n";
        else if(q2%(2*a)==0)
            cout << (q2/(2*a)) << "*sqrt(" << sqr << ")\n";
        else if((2*a)%q2==0)
            cout << "sqrt(" << sqr << ")/" << (2*a/q2) << "\n";
        else
        {
            int gcdd=__gcd(q2,2*a);
            cout << (q2/gcdd) << "*sqrt(" << sqr << ")/" << (2*a/gcdd) << "\n";
        }
    }
    return 0;
}
