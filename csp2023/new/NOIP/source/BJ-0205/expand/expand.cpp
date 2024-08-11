#include<iostream>
using namespace std;
int a[300005];
int a1[300005];
int b1[300005];
int b[300005];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    int i;
    int j;
    int n1,m1;
    cin>>c>>n>>m>>q;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    if((a[1]-b[1])*(a[n]-b[m])>0)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
    for(i=1;i<=n;i++)
    {
        a1[i]=a[i];
    }
    for(i=1;i<=m;i++)
    {
        b1[i]=b[i];
    }
    while(q--)
    {
        for(i=1;i<=n;i++)
        {
            a[i]=a1[i];
        }
        for(i=1;i<=m;i++)
        {
            b[i]=b1[i];
        }
        int u,v;
        cin>>u>>v;
        for(i=1;i<=u;i++)
        {
           int p1,q1;
           cin>>p1>>q1;
           a[p1]=q1;
        }
        for(i=1;i<=v;i++)
        {
            int p1,q1;
            cin>>p1>>q1;
            b[p1]=q1;
        }
        if((a[1]-b[1])*(a[n]-b[m])>0)
        {
            cout<<1;
        }
        else
        {
            cout<<0;
        }
    }
    return 0;
}
