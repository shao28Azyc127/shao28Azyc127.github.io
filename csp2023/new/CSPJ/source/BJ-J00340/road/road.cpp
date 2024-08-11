#include<iostream>
#include<cstdio>
using namespace std;
#define INF 100005
int n,v[INF],a[INF],d;
long long sumv[INF],ex[INF];
long long p(int s,int e)
{
    int mina=99999999,mini;
    for(int i=s;i<e;i++)
    {
        if(a[i]<=mina)
        {
            mina=a[i];
            mini=i;
        }
    }
    if(mini==1)
    {
        if(sumv[e]%d==0)
            return sumv[e]/d*mina;
        else
        {
            ex[e]=(sumv[e]/d+1)*d-sumv[e];
            return (sumv[e]/d+1)*mina;
        }
    }
    int l=p(1,mini);
    int sump=sumv[e]-sumv[mini]-ex[mini];
    if(sump%d==0)
    {
        return l+(sump/d)*mina;
    }
    else
    {
        ex[e]=(sump/d+1)*d-sump;
        return l+(sump/d+1)*mina;
    }
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    if (n==1)
    {
        cout<<"0";
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        cin>>v[i];
        for(int j=i+1;j<=n;j++)
            sumv[j]+=v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<p(1,n);
    return 0;
}
