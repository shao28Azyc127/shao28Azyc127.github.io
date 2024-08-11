#include<bits/stdc++.h>
using namespace std;
int minq,qian,u[100100],a[100100],n,d;
long long xing;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)
    {
        cin>>u[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    minq=a[1];
    for(int i=1;i<n;i++)
    {
        if(a[i]<minq) minq=a[i];
        while(xing<u[i])
        {
            xing+=d;
            qian+=minq;
        }
        xing-=u[i];
    }
    cout<<qian;
    return 0;
}
