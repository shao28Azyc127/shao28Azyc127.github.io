#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int a[N],b[N];
int main()
{
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    int c,n,m,q;
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=m;i++)
        cin>>b[i];
    if(n<=1 && m<=1)
        cout<<1;
    else if((a[1]<b[1] && a[2]<b[2]) || (a[1]>b[1] && a[2]>b[2]))
        cout<<1;
    else
        cout<<0;
    while(q--)
    {
        int ca,cb;
        cin>>ca>>cb;
        for(int i=1;i<=ca;i++)
        {
            int p,v;
            cin>>p>>v;
            a[p]=v;
        }
        for(int i=1;i<=cb;i++)
        {
            int p,v;
            cin>>p>>v;
            b[p]=v;
        }
        if(n<=1 && m<=1)
            cout<<1;
        else if((a[1]<b[1] && a[2]<b[2]) || (a[1]>b[1] && a[2]>b[2]))
            cout<<1;
        else
            cout<<0;
    }
    return 0;
}
