#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,w=1;
    char ch=0;
    while(ch<'0'||'9'<ch)
    {
        if(ch=='-')w=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9')
    {
        x=(x<<3)+(x<<1)+ch-'0';
        ch=getchar();
    }
    return x*w;
}
const int maxn=1e3+10;
void write(int a,int b)
{
    int d=__gcd(a,b);
    a/=d,b/=d;
    if(a==b)
    {
        cout<<1;
        return;
    }
    if(a==0)
    {
        cout<<0;
        return;
    }
    if(a<0&&b<0)a=-a,b=-b;
    if(a>=0&&b<0)a=-a,b=-b;
    if(b==1)
    {
        cout<<a;
        return;
    }
    cout<<a<<"/"<<b;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,m;
    cin>>T>>m;
    while(T--)
    {
        int a=read(),b=read(),c=read();
        int x=b*b-4*a*c;
        if(x<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        double t=sqrt(x);
        if(t==(int)t)
        {
            write(-b+sqrt(x),2*a);
            cout<<endl;
            continue;
        }
        int tmp=1;
        for(int i=1;i<=m;++i)
        {
            if(x%(i*i)==0)x/=i*i,tmp*=i;
        }
        if(b!=0)
        {
            write(-b,2*a);
            cout<<"+";
        }
        if(tmp/(double)(2*a)==1)
        {
            cout<<"sqrt("<<x<<")"<<endl;
            continue;
        }
        if(tmp/(double)(2*a)==(int)(tmp/(double)(2*a)))
        {
            write(tmp,2*a);
            cout<<"*"<<"sqrt("<<x<<")"<<endl;
            continue;
        }
        if(1/(tmp/(double)(2*a))==(int)(1/(tmp/(double)(2*a))))
        {
            cout<<"sqrt("<<x<<")"<<"/"<<1/(tmp/(double)(2*a))<<endl;
            continue;
        }
        int d=__gcd(tmp,2*a);
        cout<<tmp/d<<"*"<<"sqrt("<<x<<")"<<"/"<<2*a/d<<endl;
    }
    return 0;
}
