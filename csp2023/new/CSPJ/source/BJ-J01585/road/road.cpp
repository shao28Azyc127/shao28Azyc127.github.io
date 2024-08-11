#include <iostream>
#include <stdlib.h>

using namespace std;

int n,d;
int v[100005];
int a[100005];
int locate;
int ans;
int gas;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++)
    {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int cheapest=999999;
    for(int i=1;i<=n;i++)
    {
        locate=i;
        if(i==n)
        {
            int run=0;
            for(int x=locate;x<=i;x++)
            {
                run=run+v[x];
            }
            int j=run/d;
            if(run%d!=0)
            {
                j++;
            }
            ans=ans+j*a[i];
            break;
        }
        if(a[i]<cheapest)
        {
            int run=0;
            for(int x=locate;x<=i;x++)
            {
                run=run+v[x];
            }
            int j=run/d;
            if(run%d!=0)
            {
                j++;
            }
            gas=gas+j*d;
            ans=ans+j*a[i];
            cheapest=a[i];
        }
        else
        {
            gas=gas-v[i];
        }
    }
    cout<<ans;
    return 0;
}
