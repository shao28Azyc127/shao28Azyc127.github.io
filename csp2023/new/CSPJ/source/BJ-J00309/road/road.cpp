#include<iostream>
using namespace std;

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int rlong;
    long roadlong[n+1];
    roadlong[1]=0;
    int oilcost[n+1];

    for(int i=2;i<=n;i++)
    {
        cin>>rlong;
        roadlong[i]=roadlong[i-1]+rlong;
    }

    for(int i=2;i<=n;i++)
    {
        if(roadlong[i]%d==0)
        {
            roadlong[i]/=d;
        }
        else
        {
            roadlong[i]=roadlong[i]/d+1;
        }
    }


    bool cheapest[n+1];
    for(int i=1;i<=n;i++)
    {
        cheapest[i]=0;
    }
    int cheapestcost=1000000;
    for(int i=1;i<=n;i++)
    {
        cin>>oilcost[i];
        if(cheapestcost>oilcost[i])
        {
            cheapestcost=oilcost[i];
            cheapest[i]=1;
        }
    }


    long long ans=0;
    int i=n;
    while(i>=2)
    {
        for(int j=i-1;i>=1;j--)
        {
            if(cheapest[j]==1)
            {
                ans+=oilcost[j]*(roadlong[i]-roadlong[j]);
                i=j;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}