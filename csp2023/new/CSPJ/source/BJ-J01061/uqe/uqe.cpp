#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
long long gcd(long long x,long long y)
{
    long long xx=max(x,y),yy=min(x,y);
    while(yy!=0)
    {
        long long t=yy;
        yy=xx%yy;
        xx=t;
    }
    return abs(xx);
}
int f[110],g[110];
long long hj(long long x)
{
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    int sz=0;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)g[++sz]=i;
        while(x%i==0)
        {
            f[sz]++;
            x/=i;
        }
    }
    if(x>1)
    {
        g[++sz]=x;
        f[sz]++;
    }
    long long t=1;
    for(int i=1;i<=sz;i++)
    {
        if(f[i]%2==0)continue;
        t*=g[i];
    }
    return t;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        long long a,b,c;
        cin>>a>>b>>c;
        long long pb=(b*b)-(4*a*c);
        if(pb<0)
        {
            cout<<"NO"<<endl;
            continue;
        }
        bool f=((-b-sqrt(pb))/(2*a)>(-b+sqrt(pb))/(2*a));
        if(long(sqrt(pb))*long(sqrt(pb))==pb)
        {
            long long up,down=2*a;
            if(f==1)
            {
                up=(-b-sqrt(pb));
            }
            else
            {
                up=(-b+sqrt(pb));
            }
            if(up<0&&down<0)
            {
                up=-up;
                down=-down;
            }
            if(up>0&&down<0)
            {
                up=-up;
                down=-down;
            }
            long long k=gcd(up,down);
            if(k==down)cout<<up/k<<endl;
            else cout<<up/k<<"/"<<down/k<<endl;
        }
        else
        {
            long long an=sqrt(pb/hj(pb)),bn=hj(pb);
            if(-b!=0)
            {
                long long up1=-b,down1=2*a;
                if(down1<0)
                {
                    up1=-up1;
                    down1=-down1;
                }
                long long k1=gcd(up1,down1);
                if(k1==down1)cout<<up1/k1<<"+";
                else cout<<up1/k1<<"/"<<down1/k1<<"+";
            }
            long long up1=an,down1=2*a;
            if(down1<0)
            {
                up1=-up1;
                down1=-down1;
            }
            up1=abs(up1);
            long long k1=gcd(up1,down1);
            if(k1==down1)
            {
                if(up1==k1)cout<<"sqrt("<<bn<<")"<<endl;
                else cout<<up1/k1<<"*"<<"sqrt("<<bn<<")"<<endl;
            }
            else
            {
                if(up1==k1)cout<<"sqrt("<<bn<<")"<<"/"<<down1/k1<<endl;
                else cout<<up1/k1<<"*"<<"sqrt("<<bn<<")"<<"/"<<down1/k1<<endl;
            }
        }
    }
    return 0;
}
