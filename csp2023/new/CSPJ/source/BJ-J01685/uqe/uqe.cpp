#include<bits/stdc++.h>
using namespace std;
void q(long long a,long long b)
{
    long long c,d;
    if (a<=0&&b>=0||a>=0&&b<=0) c=1;
    a=abs(a);
    b=abs(b);
    for (d=2;d<=min(a,b);d++)
    {
        while (a%d==0&&b%d==0) a/=d,b/=d;
    }
    if (c==1) cout<<"-";
    if (b==1) cout<<a;
    else cout<<a<<"/"<<b;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    double a,b,c,d,e,f;
    long long g,h,i;
    cin>>a>>b;
    while (a--)
    {
        cin>>c>>d>>e;
        e=d*d-4*c*e;
        c*=2;
        if (e<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        f=sqrt(e);
        if (f==ceil(f))
        {
            if (c<0) q(min(-d+f,-d-f),c),cout<<endl;
            else q(max(-d+f,-d-f),c),cout<<endl;
        }
        else
        {
            if (-d/2/c!=0) q(-d,c),cout<<"+";
            c=abs(c);
            if (c==1) cout<<"("<<e<<")"<<endl;
            else if (1/c==ceil(1/c)) cout<<1/c<<"*sqrt("<<e<<")"<<endl;
            else if (c==ceil(c)) cout<<"sqrt("<<e<<")/"<<c<<endl;
            else cout<<"1*sqrt("<<e<<")/"<<c<<")"<<endl;
        }
    }
    return 0;
}
