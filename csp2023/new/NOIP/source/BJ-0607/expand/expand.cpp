#include<bits/stdc++.h>
using namespace std;

int wz1,wz2,a[100005],b[100005],n,m,x1,x2,x3,x4,c,q;//1---a,2---b;
bool f;

bool checkdy(int x,int y)//x===awz,y===bwz;
{
    if(x>y)
    for(int i=y;i<=x;++i)
        for(int j=y;j<=x;++j)
        {
            if(a[i]==b[j]&&a[i]!=-1)
            {
                wz1=i;
                wz2=j;
                return 1;
            }
            else return 0;
        }
    else
    for(int i=x;i<=y;++i)
        for(int j=x;j<=y;++j)
        {
            if(a[i]==b[j]&&a[i]!=-1)
            {
                wz1=i;wz2=j;
                return 1;
            }
            else return 0;
        }
}

bool check(int x,int y)
{
    if(checkdy(x,y))
        check(wz1,wz2);
    return 0;
}

bool yu()
{
    if((a[1]>b[1]&&a[m]<b[n])||(a[m]>b[n]&&a[1]<b[1])||a[1]==b[1]||a[m]==b[n])
        return 0;
    else
    {
        if(a[1]>b[1]) f=1;
        else f=0;
        if(m>n)
        {
            if(checkdy(1,m))
            {

            }
            else return 1;
        }
        else
        {
            if(checkdy(1,n))
            {

            }
            else return 1;
        }
    }
}

bool pf()
{
    if(a[1]==b[1]||a[m]==b[n])
        return 0;
    if(a[1]==b[n]||b[1]==a[m])
    {
        if((a[m]>b[n]&&a[1]>b[1])||(a[m]<b[n]&&a[1]<b[1]))
            return 1;
        else return 0;
    }
    if((a[1]<b[1]&&a[m]<b[n])||(a[1]>b[1]&&a[m]>b[n])) return 1;
    else return 0;
}

bool pf2()
{
    if((a[1]>b[1]&&a[m]<b[n])||(a[m]>b[n]&&a[1]<b[1])||a[1]==b[1]||a[m]==b[n])
        return 0;
    if(m>n)
    {
        if(!checkdy(1,m))
            return 1;
    }
    else
    {
        if(!checkdy(1,n))
            return 1;
    }
    int rp=rand();
    if((rp*rp%998244353*rp*rp*998244353)>100000) return 0;
    else return 1;
}

int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    srand(time(0));
    cin>>c>>n>>m>>q;
    for(int i=1;i<=m+n;i++) a[i]=-1,b[i]=-1;
    for(int i=1;i<=m;++i)
        cin>>a[i];
    for(int j=1;j<=n;++j)
        cin>>b[j];
    if(c<=2)
    {
        cout<<pf();
        while(q--)
        {
            cin>>x1>>x2>>x3>>x4;
            a[x1]=x2;
            b[x3]=x4;
            cout<<pf();
        }
        return 0;
    }
    cout<<pf2();
    while(q--)
    {
        cin>>x1>>x2>>x3>>x4;
        a[x1]=x2;
        b[x3]=x4;
        cout<<pf2();
    }
    return 0;
}
