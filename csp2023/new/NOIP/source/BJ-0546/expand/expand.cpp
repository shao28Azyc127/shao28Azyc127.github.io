#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
const int MAX=5e5+5;

int c,n,m,q;
LL x[MAX],y[MAX];

/*

8 2 9 1
9 2 5 12


*/
bool checksame(LL a,LL b)
{
    return (a>0&&b>0)||(a<0&&b<0);
}

bool check1(LL a[],LL b[])
{
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        if(cnt>i)
        {
            return false;
        }
        if(a[i]>=b[cnt])
        {
            cnt++;
            i--;
        }
    }
    return true;
}
bool check2(LL a[],LL b[])
{
    int cnt=1;
    for(int i=1;i<=m;i++)
    {
        if(cnt>i)
        {
            return false;
        }
        if(a[cnt]>=b[i])
        {
            cnt++;
        }
    }
    return true;
}

int main()
{

    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>y[i];
    }
        LL f=x[1]-y[1];
        LL l=x[n]-y[m];
        if((f>0&&l>0)||(f<0&&l<0))
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    while(q--)
    {
        LL kx,ky,cntx[MAX],cnty[MAX];
        cin>>kx>>ky;
        for(int i=1;i<=n;i++)
        {
            cntx[i]=x[i];
        }
        for(int i=1;i<=kx;i++)
        {
            int p,v;
            cin>>p>>v;
            cntx[p]=v;
        }
        for(int i=1;i<=m;i++)
        {
            cnty[i]=y[i];
        }
        for(int i=1;i<=ky;i++)
        {
            int p,v;
            cin>>p>>v;
            cnty[p]=v;
        }
        f=cntx[1]-cnty[1];
        l=cntx[n]-cnty[m];
        if((f>0&&l>0)||(f<0&&l<0))
        {
            cout<<"1";
        }
        else
        {
            cout<<"0";
        }
    }
    return 0;
}

