#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y)
{
    if(y==0) return x;
    return gcd(y,x%y);
}
bool isprime(ll x)
{
    for(ll i=2;i<=sqrt(x);i++)
    {
        if(x%i==0) return false;
    }
    return true;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll t,m,x,y,z;
    cin>>t>>m;
    while(t--)
    {
        cin>>x>>y>>z;
        ll k=y*y-4*x*z;
        if(k<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(k==0)
        {
            ll res=-y;
            if(res%(2*x)==0)
            {
                cout<<res/(2*x)<<endl;
                continue;
            }
            else
            {
                bool flag=false;
                if(res<0 and 2*x>=0) flag=true;
                if(res>=0 and 2*x<0) flag=true;
                ll o=2*x;
                res=abs(res);
                o=abs(o);
                ll g=gcd(res,o);
                res/=g;
                o/=g;
                if(flag) cout<<"-";
                cout<<res<<"/"<<o<<endl;
                continue;
            }
        }
        else if(k>0)
        {
            ll res=-y;
            if(ll(sqrt(k))*ll(sqrt(k))==k)
            {
                ll p,f,q,s;
                res+=ll(sqrt(k));
                if(res%(2*x)==0)
                {
                    p=res/(2*x);
                    f=1;
                }
                else
                {
                    bool flag=false;
                    if(res<0 and 2*x>=0) flag=true;
                    if(res>=0 and 2*x<0) flag=true;
                    ll o=2*x;
                    res=abs(res);
                    o=abs(o);
                    ll g=gcd(res,o);
                    res/=g;
                    o/=g;
                    if(flag) res=-res;
                    p=res;
                    f=o;
                }
                res=-y;
                res-=sqrt(k);
                if(res%(2*x)==0)
                {
                    q=res/(2*x);
                    s=1;
                }
                else
                {
                    bool flag=false;
                    if(res<0 and 2*x>=0) flag=true;
                    if(res>=0 and 2*x<0) flag=true;
                    ll o=2*x;
                    res=abs(res);
                    o=abs(o);
                    ll g=gcd(res,o);
                    res/=g;
                    o/=g;
                    if(flag) res=-res;
                    q=res;
                    s=o;
                }
                res=-y;
                if(p*s>q*f)
                {
                    if(f==1) cout<<p<<endl;
                    else cout<<p<<"/"<<f<<endl;
                }
                else
                {
                    if(s==1) cout<<q<<endl;
                    else cout<<q<<"/"<<s<<endl;
                }
                continue;
            }
            else
            {
                ll sum=k;
                ll q2=1,r=1;
                for(int i=2;i<=sum;i++)
                {
//                    cout<<sum<<" "<<q2<<" "<<r<<" "<<endl;
                    if(isprime(sum))
                    {
                        r*=sum;
                        break;
                    }
                    if(sum%i) continue;
                    ll cnt=0;
                    while(sum%i==0)
                    {
                        cnt++;
                        sum/=i;
                    }
                    if(cnt%2) r*=i;
                    ll ret=cnt/2;
                    while(ret)
                    {
                        q2*=i;
                        ret--;
                    }
                }
                ll q1=res;
                ll o=2*x;
                if(q1%o==0)
                {
                    if(q1/o==0) ;
                    else
                    {
                        cout<<q1/o<<"+";
                    }
                }
                else
                {
                    ll g=gcd(q1,o);
                    q1/=g;
                    o/=g;
                    if(q1<0 and o<0)
                    {
                        q1=-q1;
                        o=-o;
                    }
                    else if(q1<0 or o<0)
                    {
                        o=abs(o);
                        q1=-abs(q1);
                    }
                    cout<<q1<<"/"<<o<<"+";
                }
                o=2*x;
                if(q2%o==0)
                {
                    if(q2/o==1) cout<<"sqrt("<<r<<")"<<endl;
                    else cout<<q2/o<<"*sqrt("<<r<<")"<<endl;
                    continue;
                }
                else if(o%q2==0)
                {
                    if(o/q2==1) cout<<"sqrt("<<r<<")"<<endl;
                    else cout<<"sqrt("<<r<<")/"<<o/q2<<endl;
                    continue;
                }
                else
                {
                    ll c=q2,d=o;
                    ll g=gcd(c,d);
                    c/=g;
                    d/=g;
                    if(c<0 and d<0)
                    {
                        c=abs(c);
                        d=abs(d);
                    }
                    else if(c<0 or d<0)
                    {
                        c=-abs(c);
                        d=abs(d);
                    }
                    cout<<c<<"*sqrt("<<r<<")/"<<d<<endl;
                    continue;
                }
            }
        }
    }
    return 0;
}
