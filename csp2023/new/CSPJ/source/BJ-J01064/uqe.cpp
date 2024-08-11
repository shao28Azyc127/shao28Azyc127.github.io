#include <bits/stdc++.h>
#define int long long
using namespace std;
int M,a,b,c;
int gcd(int x,int y)
{
    if(!y) return x;
    return gcd(y,x%y);
}
void print(int a,int b,int f)
{
    int c=f,fu=0;
    if(a<0) c++;
    if(b<0) c++;
    if(c&1) fu=1;
    a=abs(a);b=abs(b);
    int d=gcd(a,b);
    a/=d;b/=d;
    if(a)
    {
        if(fu) cout<<'-';
        if(b==1) cout<<a;
        else cout<<a<<'/'<<b;
        cout<<'+';
    }
}
void okprint(int a,int b,int f)
{
    int c=f,fu=0;
    if(a<0) c++;
    if(b<0) c++;
    if(c&1) fu=1;
    a=abs(a);b=abs(b);
    int d=gcd(a,b);
    a/=d;b/=d;
    if(a)
    {
        if(fu) cout<<'-';
        if(b==1) cout<<a;
        else cout<<a<<'/'<<b;
    }
    else cout<<0;
}
void print2(int a,int b,int x)
{
    a=abs(a);b=abs(b);
    int d=gcd(a,b);
    a/=d;b/=d;
    if(a==1&&b==1) cout<<"sqrt("<<x<<")";
    else if(b==1) cout<<a<<"*sqrt("<<x<<")";
    else if(a==1) cout<<"sqrt("<<x<<")/"<<b;
    else cout<<a<<"*sqrt("<<x<<")/"<<b;
}
void genshi(int x,int &t1,int &t2)
{
    int tmp=x,wai=1,li=1,i;
    for(i=2;i*i<=tmp;i++)
    {
        int cnt=0;
        while(tmp%i==0)
        {
            tmp/=i;
            cnt++;
            if(cnt%2==0)
                wai*=i;
        }
        if(cnt&1) li*=i;
    }
    if(tmp!=1) li*=tmp;
    t1=wai;t2=li;
}
void solve()
{
    //Clear();
    cin>>a>>b>>c;
    int delta=b*b-4*a*c;
    if(delta<0) cout<<"NO"<<'\n';
    else if(delta==0)
    {
        okprint(b,2*a,1);
        cout<<'\n';
    }
    else
    {
        int tmp=(int)sqrt(1.0*delta);
        if(tmp*tmp==delta)
        {
            double X1=1.0*((-b)+tmp)/(2*a);
            double X2=1.0*((-b)-tmp)/(2*a);
            if(X1>X2)
                okprint((-b)+tmp,(2*a),0);
            else
                okprint((-b)-tmp,(2*a),0);
            cout<<'\n';
        }
        else
        {
            print(b,2*a,1);
            int wai,li;
            genshi(delta,wai,li);
            print2(wai,2*abs(a),li);
            cout<<'\n';
        }
    }
}
signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    ios::sync_with_stdio(0);
    int _T;cin>>_T>>M;
    while(_T--)solve();
    return 0;
}

