#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

void oup(ll p,ll q) // frac{p}{q};
{
    ll gg=__gcd(p,q);
    p/=gg,q/=gg;
    if(q<0) q*=-1,p*=-1;
    if(q==1) cout<<p;
    else cout<<p<<'/'<<q;
}

void Solve()
{
    ll a,b,c;cin>>a>>b>>c;
    // cout<<a<<' '<<b<<' '<<c<<endl;
    ll delt=b*b-4*a*c;
    if(delt<0) {cout<<"NO\n";return ;}
    ll q1=-b,q2=1,dv1=2*a,dv2=2*a;
    ll ttmp=delt;
    for(ll i=2;i*i<=ttmp;i++)
    {
        while(delt%(i*i)==0) q2*=i,delt/=i*i;
        // RP++!
    }
    // cout<<q1<<' '<<dv1<<' '<<q2<<' '<<dv2<<' '<<delt<<endl;
    if(a>=0)
    {
        ll g1=__gcd(q1,dv1);
        ll g2=__gcd(q2,dv2);
        if(q2<0&&dv2<0) g2*=-1;
        // cout<<q2<<' '<<dv2<<' '<<g2<<endl;
        if(delt==1)
        {
            oup(q1+q2,dv1);goto end;
        }
        if(q1!=0)
        {
            oup(q1,dv1);
            if(delt!=0) cout<<'+';
            else goto end;
        }
        if(delt==0) {cout<<0;goto end;}
        if(q2==1) cout<<"sqrt("<<delt<<")/"<<abs(dv2);
        else if(dv2==q2)
        {
            cout<<"sqrt("<<delt<<")";
        }
        else if(dv2==g2)
        {
            oup(q2,dv2);
            cout<<"*sqrt("<<delt<<")";
        }
        else if(q2==g2)
        {
            cout<<"sqrt("<<delt<<")/";
            oup(dv2,q2);
        }
        else 
        {
            if(q2/g2<0&&dv2/g2<0) q2*=-1,dv2*=-1;
            if(dv2/g2<0) q2*=-1,dv2*=-1;
            cout<<q2/g2<<"*sqrt("<<delt<<")/"<<dv2/g2;
        }
    }
    else
    {
        ll g1=__gcd(q1,dv1);
        ll g2=__gcd(q2,dv2);
        if(q2<0&&dv2<0) g2*=-1;
        if(delt==1)
        {
            oup(q1-q2,dv1);goto end;
        }
        if(q1!=0)
        {
            oup(q1,dv1);
            if(delt!=0) cout<<'+';
            else goto end;
        }
        if(delt==0) {cout<<0;goto end;}
        if(q2==1) cout<<"sqrt("<<delt<<")/"<<abs(dv2);
        else if(dv2==-q2)
        {
            cout<<"sqrt("<<delt<<")";
        }
        else if(dv2==g2)
        {
            oup(-q2,dv2);
            cout<<"*sqrt("<<delt<<")";
        }
        else if(q2==g2)
        {
            cout<<"sqrt("<<delt<<")/";
            oup(abs(dv2),abs(q2));
        }
        else 
        {
            if(-q2/g2<0&&dv2/g2<0) q2*=-1,dv2*=-1;
            if(dv2/g2<0) q2*=-1,dv2*=-1;
            cout<<-q2/g2<<"*sqrt("<<delt<<")/"<<dv2/g2;
        }
        
    }end:;cout<<endl;
}

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ll T,M;cin>>T>>M;
    while(T--) Solve();
    return 0;
}